/*
AuThOr Gwj
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
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define int LL
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=3e5+2;
int n,m,k,c[MAXN],w[MAXN],cBcc[MAXN],depth[MAXN],low[MAXN],belong[MAXN],cntBcc;
bool sp[MAXN],spBcc[MAXN],vis[MAXN];
vector<mp> g[MAXN];
stack<int> sta;
void dfs(int now,int pre,int deep){
	sta.push(now);
	depth[now]=deep;
	low[now]=deep;
	vis[now]=1;
	for(auto it:g[now]){
		int to=it.FIR;
		if(to!=pre){
			if(vis[to]){
				low[now]=min(low[now],depth[to]);
			}
			else{
				dfs(to,now,deep+1);
				low[now]=min(low[now],low[to]);
			}
		}
	}
	if(low[now]==deep){
		cntBcc++;
		while(1){
			int index=sta.top();
			sta.pop();
			belong[index]=cntBcc; 
			if(index==now) break;
		} 
	}
}
int cntSp[MAXN];
int cntHave[MAXN];
int total=0;
LL dp[MAXN];//ispecial node |..#..| isaturated 
LL totC[MAXN],sumC[MAXN];//c[j](json(i),cntSp[j]=0)+cBcc[i]
void dfsInit(int now,int pre){
	cntSp[now]=spBcc[now];
	cntHave[now]=spBcc[now];
	total+=spBcc[now];
	sumC[now]=cBcc[now];
	for(auto it:g[now])
	{
		if(it.FIR!=pre)
		{
			dfsInit(it.FIR,now);
			sumC[now]+=sumC[it.FIR];
			cntSp[now]+=cntSp[it.FIR];
			if(cntSp[it.FIR]){
				cntHave[now]++;
			}
		}
	}
} 
int onlySon[MAXN][2];
void dfsDp(int now,int pre){
	onlySon[now][0]=onlySon[now][1]=-1; 
	totC[now]=cBcc[now];
	for(auto it:g[now]){
		if(it.FIR!=pre)
		if(!cntSp[it.FIR]){
			totC[now]+=sumC[it.FIR];
		}
	}
	dp[now]=totC[now];
	for(auto it:g[now]){
		if(it.FIR!=pre)
		if(cntSp[it.FIR]){
			if(onlySon[now][0]==-1){
				onlySon[now][0]=it.FIR;
			}
			else{
				onlySon[now][1]=it.FIR;
			}
			dfsDp(it.FIR,now);
			if(cntSp[it.FIR]==total){
				dp[now]+=dp[it.FIR];
			}
			else
			dp[now]+=max(0ll,dp[it.FIR]-it.SEC);
		}
	}
}
int res[MAXN];
struct DATA{
	int cntSp,dp,totC,sumC;
};
map<mp,int> id;
pair<DATA,DATA> Copy(int i,int j){
	DATA d1,d2;
	d1.cntSp=cntSp[i];
	d1.dp=dp[i];
	d1.sumC=sumC[i];
	d1.totC=totC[i];
	d2.cntSp=cntSp[j];
	d2.dp=dp[j];
	d2.sumC=sumC[j];
	d2.totC=totC[j]; 
	return II(d1,d2);
}
void  Paste(int i,int j,DATA d1,DATA d2){
	cntSp[i]=d1.cntSp;
	dp[i]=d1.dp;
	sumC[i]=d1.sumC;
	totC[i]=d1.totC;
	cntSp[j]=d2.cntSp;
	dp[j]=d2.dp;
	sumC[j]=d2.sumC;
	totC[j]=d2.totC; 
}
void change_root(int now,int pre){
//	cout<<no
	res[now]=dp[now];
	for(auto it2:g[now]){
		int it=it2.FIR;
		if(it!=pre){
			mp saveSon=II(onlySon[now][0],onlySon[now][1]);
			int saveHave1=cntHave[now],saveHave2=cntHave[it];
			pair<DATA,DATA> save;
			save=Copy(now,it);
			if(!cntSp[it]){
				totC[now]-=sumC[it];
			}
			if(cntSp[it]){
				if(cntSp[it]!=total)
				dp[now]-=max(0ll,dp[it]-it2.SEC);
				else 
				dp[now]-=dp[it];
			}
			dp[now]-=totC[now];
			dp[it]-=totC[it];
			sumC[now]-=sumC[it];
			sumC[it]+=sumC[now];
			cntSp[now]-=cntSp[it];
			cntSp[it]+=cntSp[now];
			cntHave[it]+=(bool)(cntSp[now]);
			if(!cntSp[now]){
				totC[it]+=sumC[now];
			}
			dp[now]+=totC[now];
			dp[it]+=totC[it];
			if(cntSp[now]){
				if(cntSp[now]!=total){
					if(dp[now]-it2.SEC>0){
						dp[it]+=dp[now]-it2.SEC;
					}
				}
				else{
					dp[it]+=dp[now];
				}
			}
			change_root(it,now);
			Paste(now,it,save.FIR,save.SEC);
			cntHave[now]=saveHave1,cntHave[it]=saveHave2;
			onlySon[now][0]=saveSon.FIR;
			onlySon[now][1]=saveSon.SEC;
		}
	}
}
signed main(){
	fastio;
	cin>>n>>m>>k;
	rb(i,1,k){
		int vi;
		cin>>vi;
		sp[vi]=1;
	}
	rb(i,1,n) R(c[i]);
	rb(i,1,m){
		int wi;
		R(wi);
		w[i]=wi;
	}
	vector<mp> edges;
	rb(i,1,m){
		int u,v;
		R2(u,v);
		id[II(u,v)]=id[II(v,u)]=i;
		edges.PB(II(u,v));
		g[u].PB(II(v,w[i]));
		g[v].PB(II(u,w[i]));
	}
	dfs(1,0,1);//
//	cout<<cntBcc<<endl;
//	rb(i,1,n) cout<<belong[i]<<" ";cout<<endl;
//	rb(i,1,n)
//		belong[i]=i;
	rb(i,1,n)
		cBcc[belong[i]]+=c[i];
	rb(i,1,n)
		spBcc[belong[i]]|=sp[i];
	rb(i,1,n)
		g[i].clear();
	rep(i,m){
		int u,v;
		u=edges[i].FIR;
		v=edges[i].SEC;
		v=belong[v];
		u=belong[u];
		if(u!=v){
			g[u].PB(II(v,w[i+1]));
			g[v].PB(II(u,w[i+1]));
		}
	}
	dfsInit(1,0);
	dfsDp(1,0);
	change_root(1,0);
	rb(i,1,n){
		cout<<res[belong[i]]<<" ";
	}cout<<endl;
	return 0;
}