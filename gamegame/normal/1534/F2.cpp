#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=4e5+50;
const ll mod=1e9+7;
int n,m,z;
int bad[N];
int xc[N];
stack<int>s;
vector<pair<int,int> >sand[N];
vector<int>adj[N],rev[N],nadj[N];
bool vis[N];
int scc[N];
int mn[N],mx[N];
bool need[N];
void add(int u,int v){
	//cout << "add " << u << ' ' << v << endl;
	adj[u].push_back(v);
	rev[v].push_back(u);
}
void dfs(int u){
	vis[u]=true;
	for(auto c:adj[u]){
		if(!vis[c]) dfs(c);
	}
	s.push(u);
}
void dfs2(int u,int rt){
	scc[u]=rt;
	for(auto c:rev[u]){
		if(scc[c]==0) dfs2(c,rt);
	}
}
int in[N];
int t;
pair<int,int>hard[N];
int l[N];
int dp[N];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=n; i>=1 ;i--){
		for(int j=1; j<=m ;j++){
			char c;cin >> c;
			if(c=='#'){
				sand[j].push_back({i,++z});
				xc[z]=j;
			}
		}
	}
	for(int i=1; i<=m ;i++) cin >> bad[i];
	for(int j=1; j<=m ;j++) reverse(sand[j].begin(),sand[j].end());
	for(int j=1; j<=m ;j++){
		for(int k=0; k<sand[j].size() ;k++){
			if(k+1!=sand[j].size()){
				add(sand[j][k+1].se,sand[j][k].se);
			}
			if(k!=0 && sand[j][k-1].fi+1==sand[j][k].fi){
				add(sand[j][k-1].se,sand[j][k].se);
			}
			auto it=lower_bound(sand[j-1].begin(),sand[j-1].end(),pair<int,int>{sand[j][k].fi,0});
			if(it!=sand[j-1].end()) add(it->se,sand[j][k].se);
			it=lower_bound(sand[j+1].begin(),sand[j+1].end(),pair<int,int>{sand[j][k].fi,0});
			if(it!=sand[j+1].end()) add(it->se,sand[j][k].se);
		}
	}
	for(int i=1; i<=z ;i++){
		if(!vis[i]) dfs(i);
	}
	int ans=0;
	while(!s.empty()){
		int x=s.top();s.pop();
		if(scc[x]) continue;
		dfs2(x,x);need[x]=true;ans++;
	}
	for(int i=1; i<=z ;i++){
		for(auto u:rev[i]){
			if(scc[u]==scc[i]) continue;
			in[scc[i]]++;
			if(need[scc[i]]){
				need[scc[i]]=false;
				ans--;
			}
		}
	}
	
	for(int i=1; i<=z ;i++){
		mn[i]=1e9;mx[i]=0;
		if(scc[i]==i && need[i]){
			hard[++t]={xc[i],i};
			//cout << xc[i] << ' ' << i << ' ' << "SCC" << endl;
		}
	}
	sort(hard+1,hard+t+1);
	for(int i=1; i<=t ;i++){
		mn[hard[i].se]=mx[hard[i].se]=i;
	}
	for(int i=1; i<=z ;i++){
		if(scc[i]==i && in[i]==0) s.push(i);
	}
	for(int i=1; i<=z ;i++){
		for(auto c:adj[i]){
			nadj[scc[i]].push_back(c);
		}
	}
	while(!s.empty()){
		int i=s.top();s.pop();
		//cout << i << " " << mn[i] << ' ' << mx[i] << endl;
		for(auto u:nadj[i]){
			if(scc[u]==scc[i]) continue;
			mn[scc[u]]=min(mn[scc[u]],mn[i]);
			mx[scc[u]]=max(mx[scc[u]],mx[i]);
			if(--in[scc[u]]==0){
				s.push(scc[u]);
			}
		}
	}
	for(int i=1; i<=m ;i++){
		if(bad[i]!=0){
			int x=sand[i][bad[i]-1].se;
			x=scc[x];
			//cout << i << ' ' << x << ' ' << mn[x] << ' ' << mx[x] << endl;
			l[mx[x]+1]=max(l[mx[x]+1],mn[x]);
		}
	}
	for(int i=1; i<=m+1 ;i++){
		l[i]=max(l[i],l[i-1]);
		dp[i]=dp[l[i]]+1;
	}
	cout << dp[m+1]-1 << '\n';
}