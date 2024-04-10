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
const int MAXN=1e5+233;
vector<int> gra[MAXN];
vector<int> tree[MAXN];
int n,m;
int vis[MAXN];
int num[MAXN];
bool leaf[MAXN];
int g[MAXN],f[MAXN][2],h[MAXN];
void dfs(int now,int pre){
	for(auto it:gra[now]){
		if(it!=pre){
			if(vis[it]){
				if(vis[it]<vis[now]){
					num[it]--;
					num[now]++;
				}
			}
			else{
				vis[it]=vis[now]+1;
				dfs(it,now);
			}
		}
	}
}
void gao(int now,int pre){
	vis[now]=1;
	for(auto it:gra[now]) if(it!=pre){
		if(!vis[it]){
			gao(it,now);
			num[now]+=num[it];
//			cout<<now<<' '<<it<<" "<<num[now]<<endl;
		}
	}
	if(!num[now]&&pre){
		tree[pre].PB(now);
		tree[now].PB(pre);
	}
}
vector<mp> rest;
bool cmp(int A,int B){
	return f[A][1]-f[A][0]<f[B][1]-f[B][0];
}
void calc(int now,int pre){
	vis[now]=1;
	vector<int> sons;
	f[now][0]=0;
	bool all_leaf=true;
	for(auto it:gra[now]) if(it!=pre) calc(it,now),sons.PB(it),f[now][0]+=f[it][1],all_leaf&=leaf[it];
	if((sons.size()&1)&&all_leaf) f[now][0]=INF;
	else
	f[now][0]+=(sons.size()+1)>>1;
	int sum=0;
	for(auto it:sons) sum+=f[it][0];
	sort(ALL(sons),cmp);
	f[now][1]=INF;
	if(sons.size()==0){
		f[now][1]=0;
		g[now]=now;
		h[now]=0;
		leaf[now]=true;
	}
	rb(i,1,sons.size()){
		sum+=f[sons[i-1]][1]-f[sons[i-1]][0];
		if(i>=sons.size()-1);
		else continue;
//		cout<<"#"<<now<<' '<<sum<<' '<<f[sons[i-1]][1]<<" "<<f[sons[i-1]][0]<<endl;
		if(i&1){
			if(sum+i/2<f[now][1]){
				f[now][1]=sum+i/2;
				g[now]=g[sons[0]];
				h[now]=i;
			}
		}
		else{
			if(leaf[sons[0]]) continue;
			if(sum+i/2<f[now][1]){
				g[now]=g[sons[1]];
				f[now][1]=sum+i/2; 
				h[now]=i;
			}
		}
	}
//	cout<<now<<":"<<f[now][0]<<' '<<f[now][1]<<endl;
}
void gao(int now,int ty,int pre){
	vector<int> sons;
	for(auto it:gra[now]) if(it!=pre) sons.PB(it);
	if(ty==0){
		int notleaf=-1;
		rep(i,sons.size()){
			int now=i,nex=i+1; 
			if((sons.size()&1)&&notleaf==-1&&!leaf[sons[now]]){
				notleaf=sons[now];
				now++;
				nex++;
			}
			if((sons.size()&1)&&notleaf==-1&&!leaf[sons[nex]]){
				notleaf=sons[nex];
				nex++;
			}
			if(nex>=sons.size()) break;
			rest.PB(II(g[sons[now]],g[sons[nex]]));
			i=nex;
		}
		if(notleaf!=-1){
			rest.PB(II(g[notleaf],now));
		}
		for(auto it:sons) gao(it,1,now);return;
	}
	if(sons.empty()) return;
	sort(ALL(sons),cmp);
	if((h[now])&1){
		rb(i,1,h[now]-1){
			rest.PB(II(g[sons[i]],g[sons[i+1]]));
			++i;
		}
	}
	else{
		rb(i,2,h[now]-1){
			rest.PB(II(g[sons[i]],g[sons[i+1]]));
			++i;
		}
		rest.PB(II(g[sons[0]],now));
	}
	rb(i,1,h[now]) gao(sons[i-1],1,now);
	rb(i,h[now]+1,sons.size()) gao(sons[i-1],0,now);
}
void solve(){
	rest.clear();
	rb(i,1,n) gra[i].clear(),leaf[i]=false;
	rb(i,1,n) tree[i].clear();
	rb(i,1,n) vis[i]=0;
	rb(i,1,n) num[i]=0;
	rb(i,1,m){
		int si;
		scanf("%d",&si);
		int pre=-1;
		rb(j,1,si){
			int ai;
			scanf("%d",&ai);
			if(pre!=-1) gra[pre].PB(ai),gra[ai].PB(pre);
			pre=ai;
		}
	}
	vis[1]=1;
	dfs(1,0);
	rb(i,1,n) vis[i]=0;
	gao(1,0);
	rb(i,1,n) vis[i]=0;
	rb(i,1,n) gra[i]=tree[i];
	rb(i,1,n) if(!vis[i]){
		calc(i,0);
		int ret=f[i][0],z=0;
		int sum=0;
		for(auto it:gra[i]){
			sum+=f[it][1];
		}
		for(auto it:gra[i]){
			if(sum-f[it][1]+f[it][0]+gra[i].size()/2<ret){
				ret=sum-f[it][1]+f[it][0]+gra[i].size()/2;
				z=it;
			}
		}
		if(z==0)
		gao(i,0,0);	
		else{
			gao(z,0,i);
			for(auto it:gra[i]) if(it!=z) gao(it,1,i);
			int pre=-1;
			for(auto it:gra[i]){
				if(it!=z){
					if(pre!=-1) rest.PB(II(g[pre],g[it])),pre=-1;
					else{
						pre=it;
					}
				}
			}
			if(pre!=-1) rest.PB(II(g[pre],i));
		}
	}
	printf("%d\n",int(rest.size()));
	for(auto it:rest){
		printf("%d %d\n",it.FIR,it.SEC); 
	}
}
int main(){
	while(true){
		scanf("%d%d",&n,&m);
		if(!n&&!m){
			break;
		}
		solve(); 
	}
	return 0;
}