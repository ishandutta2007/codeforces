/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
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
set<mp> seg;
map<int,int> l,r;
int highbit(int x){
	int ret=0;
	while(x){
		ret++;
		x>>=1;
	}
	return ret-1;
}
struct QUERY{
	int ty,l,r,x;
	QUERY(int l_,int r_,int x_){
		l=l_;
		r=r_;
		x=x_;
		ty=1;
	}
	QUERY(int l_,int r_){
		l=l_;
		r=r_;
		ty=2;
	}
	QUERY(){}
};
vector<QUERY> v;
const int N=1<<18;
struct SEGMENTTREE{
	int tree[N+N];
	int tag[N+N];
	SEGMENTTREE(vector<int> vec){
		memset(tag,0,sizeof(tag));
		memset(tree,63,sizeof(tree));
		rep(i,N){
			if(i<vec.size())
				tree[i+N]=vec[i];
			else break;
		}
		rl(i,N-1,1)
			tree[i]=min(tree[i<<1],tree[i<<1|1]);
	}
	void pd(int index){
		if(!tag[index]) return;
		tree[index]=tag[index];
		if(index<N){
			tag[index<<1]=tag[index<<1|1]=tag[index];
		}
		tag[index]=0;
	}
	void Assign(int a,int b,int val,int now=1,int l=1,int r=N+1){
		pd(now); 
		if(r<=a||l>=b) return ;
		if(r<=b&&l>=a){
			tag[now]=val;
			pd(now);
			return ;
		}
		int mid=(l+r)>>1;
		Assign(a,b,val,now<<1,l,mid);
		Assign(a,b,val,now<<1|1,mid,r);
		tree[now]=min(tree[now<<1],tree[now<<1|1]);
	}
	int query(int a,int b,int now=1,int l=1,int r=N+1){
		pd(now);
		if(r<=a||l>=b) return INF;
		if(r<=b&&l>=a){
			return tree[now];
		}
		int mid=(l+r)>>1;
		return min(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
	}
};
int n,k,mini[100000+20][18],a[100000+20];
int query(int l,int r){
	int hb=highbit(r-l+1);
	return min(mini[l][hb],mini[r-(1<<hb)+1][hb]);
}
void split(int l,int r){
	auto ite=seg.upper_bound(II(l,INF));
	ite--;
	mp is=*ite;
	if(is.FIR!=l){
		seg.erase(ite);
		seg.insert({l,is.SEC});
		seg.insert({is.FIR,l-1});
	}
	ite=seg.upper_bound(II(r,INF));
	ite--;
	is=*ite;
	if(is.SEC!=r){
		seg.erase(ite);
		seg.insert({r+1,is.SEC});
		seg.insert({is.FIR,r});
	}
}
int main(){
	scanf("%d%d",&n,&k);
	seg.insert({1,n*k});
	rb(i,1,n) scanf("%d",&a[i]);
	rb(i,1,n) mini[i][0]=a[i];
	rb(j,1,17){
		rb(i,1,n){
			if(i+(1<<j)-1<=n){
				mini[i][j]=min(mini[i][j-1],mini[i+(1<<(j-1))][j-1]);
			}
			else break;
		}
	}
	int q;
	scanf("%d",&q);
	rb(i,1,q){
		int ty,l,r,x;
		scanf("%d%d%d",&ty,&l,&r);
		if(ty==1){
			scanf("%d",&x);
			v.PB(QUERY(l,r,x));
		}
		else{
			v.PB(QUERY(l,r));
		}
		split(l,r);
	}
	int cnt=0;
	vector<int> vv;
	for(auto ite=seg.begin();ite!=seg.end();++ite){
		++cnt;
		l[ite->FIR]=r[ite->SEC]=cnt;
		int belong=(ite->FIR+n-1)/n;
		belong*=n;
		int L,R;
		L=ite->FIR%n;
		R=ite->SEC%n;
		if(!L) L=n;
		if(!R) R=n;
		if(belong<ite->SEC){
			if(belong+n-1<ite->SEC) vv.PB(query(1,n));
			else vv.PB(min(query(L,n),query(1,R)));
		}
		else{
			vv.PB(query(L,R));
		}
	}
	SEGMENTTREE sgt(vv);
	for(auto &it:v){
		it.l=l[it.l];
		it.r=r[it.r];
		if(it.ty==1){
			sgt.Assign(it.l,it.r+1,it.x);
		}
		else{
			printf("%d\n",sgt.query(it.l,it.r+1));
		}
	}
	return 0;
}