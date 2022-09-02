#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef pair<double,int>Q;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll dp[100005][11][2];
vector<P1>zip[100005][11][2];
int t,n,m;
vector<int>edge[100005];
int par[100005],ran[100005];
void init(int n){ for(int i=0;i<n;i++) par[i] = i,ran[i] = 0; }
int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
void unite(int x,int y){
	x = find(x); y = find(y); if(x==y) return;
	if(ran[x] < ran[y]) par[x] = y;
	else{
		par[y] = x;
		if(ran[x] == ran[y]) ran[x]++;
	}
}
bool same(int x,int y){ return find(x)==find(y); }
int cnt[100005],cnte[100005],ans[100005];;
bool connect[100005];
void dfs(int v,int u){
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i]==u) continue;
		dfs(edge[v][i],v);
	}
	for(int num=0;num<=10;num++){
		ll t[4][2];
		vector<P1>vec[4][2];
		int cur = 0;
		rep(i,4)rep(j,2)t[i][j]=-1e18;
		t[0][0] = 0;
		for(int i=0;i<edge[v].size();i++){
			if(edge[v][i]==u) continue;
			for(int j=0;j<=10;j++) for(int k=0;k<2;k++){
				if(dp[edge[v][i]][j][k] < -1e17) continue;
				for(int a=0;a<2;a++){
					if(t[cur][a]<-1e17) continue;
					if(t[cur+1][k|a] < t[cur][a]+dp[edge[v][i]][j][k]+1LL*j*num){
						t[cur+1][k|a] = max(t[cur+1][k|a],t[cur][a]+dp[edge[v][i]][j][k]+1LL*j*num);
						vec[cur+1][k|a] = vec[cur][a];
						vec[cur+1][k|a].pb(mp(edge[v][i],mp(j,k)));
					}
				}
			}
			cur++;
		}
		dp[v][num][0|!!num] = max(dp[v][num][0|!!num],t[cur][0]-1LL*num*num);
		zip[v][num][0|!!num] = vec[cur][0];
		dp[v][num][1] = max(dp[v][num][1],t[cur][1]-1LL*num*num);
		zip[v][num][1] = vec[cur][1];
	}
}
void get(int v,int num,int ok,int u){
	{
		ans[v] = num;
		rep(i,zip[v][num][ok].size()){
			P1 pp = zip[v][num][ok][i];
			get(pp.fi,pp.sc.fi,pp.sc.sc,v);
		}
	}
}
int main(){
	cin>>t;
	rep(q,t){
		bool en = 0;
		cin>>n>>m;
		rep(i,n) edge[i].clear();
		init(n);
		rep(i,m){
			int a,b;cin>>a>>b; a--; b--;
			edge[a].pb(b);
			edge[b].pb(a);
			unite(a,b);
		}
		rep(i,n) cnt[i]=cnte[i]=0;
		rep(i,n){
			int c = find(i); cnt[c]+=2;
			rep(j,edge[i].size()){
				cnte[c]++;
			}
		}
		//cout<<cnt[find(0)]<<" " <<cnte[find(0)]<<endl; return 0;
		rep(i,n){
			if(cnt[i] && cnte[i] >= cnt[i]){
				puts("YES");
				rep(j,n){
					if(find(j) == i){
						printf("1 ");
					}
					else{
						printf("0 ");
					}
				}
				puts(""); en=1; break;
			}
		}
		if(en)continue;
		rep(i,n) connect[i] = 0;
		rep(i,n){
			if(edge[i].size()>=4){
				puts("YES");
				for(int j=0;j<edge[i].size();j++) connect[edge[i][j]] = 1;
				rep(j,n){
					if(j==i){
						printf("2 ");
					}
					else if(connect[j]){
						printf("1 ");
					}
					else{
						printf("0 ");
					}
				}
				puts(""); en=1; break;
			}
		}
		if(en)continue;
		//all connected component is tree which has no vertex whose degree is more than 3
		rep(i,n)rep(j,11)rep(k,2)dp[i][j][k]=-1e18;
		rep(i,n)ans[i]=0;
		rep(i,n){
			if(find(i) != i) continue;
			dfs(i,-1); //cout<<i<<endl; return 0;
			rep(j,11){
				if(dp[i][j][1] >= 0){
					puts("YES"); //cout<<dp[i][j][1]<<" " <<i << " " << j << endl;
					get(i,j,1,-1);
					rep(i,n) printf("%d ",ans[i]); puts("");
					en=1; break;
				}
			}
			if(en) break;
		}
		if(en) continue;
		puts("NO");
	}
}