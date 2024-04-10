/*
AuThOr GaRyMr
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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
const int MAXN=2e5+10;
const int MAXM=4e5+10; 
const int MAX_LOG=18;
int m;
int p[19][MAXN],n,depth[MAXN];
mp sq[MAXN];int dp[MAX_LOG+1][MAXN];
vector<int> each[MAXN];
void init(){
	rb(i,1,MAX_LOG){
		rb(j,1,n){
			p[i][j]=p[i-1][p[i-1][j]];
		}
	}
}
int lca(int u,int v){
	if(depth[u]>depth[v]) swap(u,v);
	rb(i,0,MAX_LOG){
		if(((depth[v]-depth[u])>>i)&1){
			v=p[i][v];
		}
	}
	if(u==v) return u;
	rl(i,MAX_LOG,0){
		if(p[i][u]!=p[i][v]){
			u=p[i][u];
			v=p[i][v];
		}
	}
	return p[0][u];
}
void dfs(int now,int dpp){
	depth[now]=dpp;
	for(int it:each[now]){
		dfs(it,dpp+1);
	}
}
int Cnt=0;
void dfs2(int now){
	sq[now].FIR=++Cnt;
	for(int it:each[now]){
		dfs2(it);
	}
	sq[now].SEC=++Cnt;
}
int hest[MAXN];
int dfs3(int now){
	for(int it:each[now]){
		hest[now]=min(hest[now],dfs3(it));
	}
	return dp[0][now]=hest[now];
} 
bool cmp(int A,int B){
	return A<B;
}
int U,V;
int query(int u,int v,int col=0){
	//uv 
	int tmp=0;
	if(u==v){
		return 0;
	}
	rl(i,MAX_LOG,0){
		if(dp[i][u]!=INF)
		if(dp[i][u]>v){
			u=dp[i][u];
			tmp+=(1<<i);
		}
	}
	if(dp[0][u]>v){
		return -1;
	}
	if(col==1){
		U=u;
	}
	if(col==2){
		V=u;
	}
	return tmp+1;
}
vector<mp> better[MAXN];vector<int> sup[MAXN];
struct BIT{
	int bit[MAXN+MAXN+10]={0},n;
	int sum(int i){
		int s=0;
		while(i>0){
			s+=bit[i];
			i-=i &(-i);
		}
		return s;
	}
	int query(int l,int r){
		return sum(r)-sum(l-1);
	}
	void add(int i,int x=1){
		while(i<=n){
			bit[i]+=x;
			i+= i&(-i);	
		}
	}
}rmq;
int res[MAXN];
void update(int now){
	vector<int> shuzu;
	rep(i,better[now].size()){
		shuzu.PB(rmq.query(sq[better[now][i].FIR].FIR,sq[better[now][i].FIR].SEC));
	}
	for(auto it:each[now]){
		update(it);
	}
	for(auto it:sup[now]){
		rmq.add(sq[it].FIR);
	}rep(i,better[now].size()){
		if(rmq.query(sq[better[now][i].FIR].FIR,sq[better[now][i].FIR].SEC)>shuzu[i]){
			res[better[now][i].SEC]--;
		}
	}
}
int main(){
	fastio;
	cin>>n;
	rmq.n=n<<1;
	rb(i,2,n)
		cin>>p[0][i],each[p[0][i]].PB(i);
	rb(i,1,n){
		sort(ALL(each[i]));//Make sure that the numbers in the vector is in order!!
	}
	dfs(1,1);
	init();
	dfs2(1);
	cin>>m;
	memset(hest,0x3f,sizeof(hest));
	rb(i,1,m){
		int u,v;
		cin>>u>>v;
		if(depth[u]>depth[v]) swap(u,v);
		int l=lca(u,v);
		if(l!=v)
		{
			hest[u]=min(hest[u],l);
			hest[v]=min(hest[v],l);
			if(sq[u].FIR>sq[v].FIR){
				swap(u,v);
			}
			sup[u].PB(v);
		}
		else{
			hest[u]=min(hest[u],v);
		}
	}
	dfs3(1);
	rb(i,1,MAX_LOG){
		rb(j,1,n){
			if(dp[i-1][j]!=INF&&dp[i-1][dp[i-1][j]]!=INF){
				dp[i][j]=dp[i-1][dp[i-1][j]];
			}
		}
	}
	int q;
	cin>>q;
	int i=1;
	memset(res,63,sizeof(res));
	while(i<=q){
		int u,v;
		cin>>u>>v;
		if(depth[u]<depth[v]){
			swap(u,v);
		}
		int l=lca(u,v);
		if(l==v){
			res[i]=query(u,v);
		}
		else{
			if(query(u,l)<0||query(v,l)<0){
				res[i]=-1;
			}
			else{
				res[i]=query(u,l,1)+query(v,l,2);
				if(sq[U].FIR>sq[V].FIR){
					swap(U,V);
				} 
				better[U].PB(II(V,i));
			}
		}
		i++;
	}
	update(1);
	rb(i,1,q){
		cout<<res[i]<<endl;
	}
	return 0;
}