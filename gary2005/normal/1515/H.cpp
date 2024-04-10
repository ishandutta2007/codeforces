/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int root=1,cnt=1,ans[200000*41+233],lc[200000*41+233],rc[200000*41+233],depth[200000*41+233],r[200000*41+233],l[200000*41+233],tag[200000*41+233];
bool have[200000*41+233];
void pushdown(int idx){
	if((tag[idx]>>depth[idx])&1) swap(lc[idx],rc[idx]);
	if(lc[idx]) tag[lc[idx]]^=tag[idx];
	if(rc[idx]) tag[rc[idx]]^=tag[idx];
	int oldl=l[idx],oldr=r[idx];
	r[idx]^=r[idx]&tag[idx];
	l[idx]^=l[idx]&tag[idx];
	r[idx]|=oldl&tag[idx];
	l[idx]|=oldr&tag[idx];
	tag[idx]=0;
	assert(!(l[idx]&r[idx]));
}
void upd(int idx){
	ans[idx]=have[idx];
	if(depth[idx]==20) return ;
	l[idx]=r[idx]=0;
	assert(lc[idx]||rc[idx]);
	if(lc[idx]) pushdown(lc[idx]),ans[idx]+=ans[lc[idx]],assert(!tag[lc[idx]]);
	else r[idx]|=1<<depth[idx];
	if(rc[idx]) pushdown(rc[idx]),ans[idx]+=ans[rc[idx]],assert(!tag[rc[idx]]);
	else l[idx]|=1<<depth[idx];
	if(lc[idx]&&rc[idx]) l[idx]|=l[lc[idx]]&l[rc[idx]],r[idx]|=r[lc[idx]]&r[rc[idx]];
	else l[idx]|=l[max(lc[idx],rc[idx])],r[idx]|=r[max(lc[idx],rc[idx])];	
	assert(!(l[idx]&r[idx]));
}
void merge(int& u,int& v){//merge(u,v) -> v
	if(!u||!v){
		if(u){
			v=u;
			u=0;
		}
		if(v) pushdown(v);
		return ;
	}
	pushdown(u),pushdown(v);
	have[v]|=have[u];
	merge(rc[u],rc[v]);
	merge(lc[u],lc[v]);
//	cout<<u<<" "<<v<<' '<<rc[v]<<' '<<lc[v]<<' '<<endl;
	u=0;
	upd(v);
}
int Rev(int x){
	int ret=0;
	rep(i,20){
		ret|=((x>>i)&1)<<(19-i);
	}
	return ret;
}
void split(int rt,int val,int & x,int & y){
	if(!rt){
		x=y=0;
		return ;
	}
	pushdown(rt);
	if(depth[rt]==20){
		x=rt,y=0;
		return;
	}
	if((val>>depth[rt])&1){
		x=rt;
		y=++cnt;
		depth[cnt]=depth[rt];
		split(rc[rt],val,rc[x],rc[y]);
	}
	else{
		x=++cnt;
		y=rt;                                                                                                                                                    
		depth[cnt]=depth[rt];
		split(lc[rt],val,lc[x],lc[y]);
	}
	if(!lc[x]&&!rc[x]){
		x=0;
	}
	if(!lc[y]&&!rc[y]){
		y=0;
	}
	if(x) upd(x);
	if(y) upd(y);
}
void getor(int idx,int x){
	if(depth[idx]==20) return ;
	pushdown(idx);
	
	if((x&(l[idx]|r[idx]))==x){
		tag[idx]^=x&l[idx];
		pushdown(idx);
		return ;
	}
	
	if((x>>depth[idx])&1);
	else{
		if(lc[idx]) getor(lc[idx],x);
		if(rc[idx]) getor(rc[idx],x);
		upd(idx);
		return ;
	}
	if(lc[idx]&&rc[idx]){
		merge(lc[idx],rc[idx]);
		getor(rc[idx],x^(1<<depth[idx]));
		upd(idx);
		return ;
	}
	if(lc[idx]){
		swap(lc[idx],rc[idx]);
		getor(rc[idx],x^(1<<depth[idx]));
		upd(idx);
		return ;
	}
	assert(rc[idx]);
	getor(rc[idx],x^(1<<depth[idx]));
	upd(idx);
}
void insert(int rt,int val){
	if(depth[rt]==20){
		have[rt]=1;
		upd(rt);
		return ;	
	}
	bool bt=(val>>depth[rt])&1;
	if(bt){
		if(!rc[rt]) rc[rt]=++cnt,depth[cnt]=depth[rt]+1;
		insert(rc[rt],val);
	}
	else{
		if(!lc[rt]) lc[rt]=++cnt,depth[cnt]=depth[rt]+1;
		insert(lc[rt],val);
	}
	upd(rt);
}
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	rb(i,1,n){
		int ai;
		scanf("%d",&ai);
		insert(root,Rev(ai));
	}
	rb(i,1,q){
		int ty,l,r;
		scanf("%d%d%d",&ty,&l,&r);
		int x=0,y=0,z=0;
		split(root,Rev(r),y,z);
		if(l)
		split(y,Rev(l-1),x,y);
		else x=0;
		if(ty<=3){
			int X;
			scanf("%d",&X);
//			if(n==1000) cout<<ty<<' '<<l<<' '<<r<<" "<<X<<endl;
			if(y){
				if(ty==1){
					tag[y]^=(1<<20)-1;
					getor(y,((1<<20)-1)^Rev(X));
					tag[y]^=(1<<20)-1;
				}
				if(ty==2){
					getor(y,Rev(X));
				}
				if(ty==3){
					tag[y]^=Rev(X);
				}
				pushdown(y);
			}
		}
		else{
//			if(n==1000) cout<<ty<<' '<<l<<' '<.<r<<endl;
			printf("%d\n",ans[y]);
		}
		merge(x,y);
		merge(y,z);
		root=z;
	}
	return 0;
}