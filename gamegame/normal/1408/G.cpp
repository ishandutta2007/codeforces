#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=1505;
const int M=N*N;
int n;
vector<pair<int,int> >adj[N];
typedef unsigned long long ull;
int a[N][N];
int mn[N][N];
bool god[N][N];
int id[N][N];
int sz=0;
map<pair<ull,ull>,int>mp;
int eu[N*N],ev[N*N];
ll dp[2*N][2*N];
int par[2*N];
vector<int>ch[2*N];
int csz[2*N];
void dfs(int id){
	csz[id]++;
	if(ch[id].empty()){
		dp[id][1]=1;
		return;
	}
	int bc=0;
	for(int i=0; i<ch[id].size() ;i++){
		int c=ch[id][i];
		dfs(c);
		csz[id]+=csz[c];
		if(csz[ch[id][bc]]<csz[c]) bc=i;
	}
	//cout << "doing " << id << endl;
	dp[id][0]=1;
	swap(ch[id][0],ch[id][bc]);
	int cum=0;
	for(auto c:ch[id]){
		for(int i=cum; i>=0 ;i--){
			for(int j=1; j<=csz[c] ;j++){
				dp[id][i+j]=(dp[id][i+j]+dp[id][i]*dp[c][j])%mod;
			}
			dp[id][i]=0;
		}
		cum+=csz[c];
	}
	dp[id][1]=(dp[id][1]+1)%mod;
}
vector<int>arin[N];
int pw[N];
int st[N];
void join(int x,int y){
	x=st[x];y=st[y];
	if(x==y){
		pw[x]--;return;
	}
	pw[x]+=arin[x].size()*arin[y].size();
	pw[x]--;
	pw[x]+=pw[y];
	for(auto c:arin[y]){
		arin[x].push_back(c);
		st[c]=x;
	}
	arin[y].clear();
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			cin >> a[i][j];
			adj[i].push_back({a[i][j],j});
			if(i<j){
				eu[a[i][j]]=i;
				ev[a[i][j]]=j;
			}
		}
		sort(adj[i].begin(),adj[i].end());
	}
	for(int i=1; i<=n ;i++){
		mn[i][0]=1e9;
		for(int j=1; j<=n ;j++){
			mn[i][j]=min(mn[i][j-1],adj[i][j-1].se);
		}
	}
	for(int i=1; i<=n ;i++){
		st[i]=i;
		pw[i]=0;
		arin[i].push_back(i);
		int x=i;
		if(pw[x]==0){
			sz++;
			for(auto c:arin[x]){
				id[c][arin[x].size()]=sz;
				god[c][arin[x].size()]=true;
			}
		}
	}
	for(int i=1; i<=n*(n-1)/2 ;i++){
		join(eu[i],ev[i]);
		int x=st[eu[i]];
		if(pw[x]==0){
			sz++;
			for(auto c:arin[x]){
				id[c][arin[x].size()]=sz;
				god[c][arin[x].size()]=true;
			}
		}
	}
	for(int i=1; i<=n ;i++){
		int prv=n;
		for(int j=n-1; j>=1 ;j--){
			if(!god[i][j]) continue;
			if(mn[i][j]!=i){
				prv=j;continue;
			}
			par[id[i][j]]=id[i][prv];
			ch[id[i][prv]].push_back(id[i][j]);
			//cout << id[i][j] << ' ' << id[i][prv] << endl;
			prv=j;
		}
	}
	dfs(sz);
	for(int i=1; i<=n ;i++) cout << dp[sz][i] << ' ';
	cout << '\n';
}