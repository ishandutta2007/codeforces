#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n,m,z;
int f[1000001];
bool b[1000001];
bool vis[1000001];
bool dead[1000001];
int cl[1000001];
vector<int>ch[1000001];
vector<int>cyc;
pair<int,int>s[1000001];
void dfs(int x,int y,int w){
	dead[x]=true;
	//cout << "dfs " << x << ' ' << y << ' ' << w << endl;
	cl[x]=cyc[cyc.size()%w];
	cyc.push_back(x);
	for(auto cur:ch[x]){
		if(cur==y) continue;
		dfs(cur,y,w);
	}
	cyc.pop_back();
}
void solve(){
	cin >> n >> m;
	z=n*m;
	for(int i=1; i<=z ;i++){
		vis[i]=false;
		dead[i]=false;
		char c;cin >> c;
		b[i]=c-48;
		b[i]=!b[i];
		ch[i].clear();
	}
	for(int i=1; i<=z ;i++){
		char c;cin >> c;
		if(c=='U') f[i]=i-m;
		if(c=='L') f[i]=i-1;
		if(c=='R') f[i]=i+1;
		if(c=='D') f[i]=i+m;
		ch[f[i]].push_back(i);
	}
	for(int i=1; i<=z ;i++){
		if(vis[i]) continue;
		int cur=i;
		while(!vis[cur]){
			vis[cur]=true;
			cur=f[cur];
		}
		if(dead[cur]) continue;
		int x=cur;
		cyc.clear();
		while(f[x]!=cur){
			x=f[x];
			cyc.push_back(x);
		}
		cyc.push_back(cur);
		reverse(cyc.begin(),cyc.end());
		dfs(cur,cur,cyc.size());
	}
	for(int i=1; i<=z ;i++){
		s[i]={cl[i],b[i]};
		//cout << cl[i] << ' ';
	}
	sort(s+1,s+z+1);
	int ans=0;
	int god=0;
	for(int i=1; i<=z ;i++){
		if(s[i].fi!=s[i-1].fi || s[i].se!=s[i-1].se){
			ans+=s[i].se;
		}
		if(s[i].fi!=s[i-1].fi) god++;
	}
	cout << god << ' ' << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;
	while(t--){
		solve();
	}
}