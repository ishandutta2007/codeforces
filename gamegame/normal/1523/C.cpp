#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;
int a[N];
int last[N];
vector<int>ch[N];
vector<int>ans[N];
int p[N];
void dfs(int id){
	//cout << "dfs " << id << endl;
	
	ans[id]=ans[p[id]];
	if(a[id]!=1){
		ans[id].pop_back();
	}
	ans[id].push_back(a[id]);
	for(auto c:ch[id]) dfs(c);
}
int gg[N];
int ff[N];
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		ch[i].clear();gg[i]=1,ff[i]=i;
	}
	stack<int>s;s.push(0);
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		if(a[i]==1){
			p[i]=ff[s.top()];
			s.push(i);
		}
		else{
			while(!s.empty() && gg[s.top()]!=a[i]-1) s.pop();
			p[i]=ff[s.top()];
			ff[s.top()]=i;
			gg[s.top()]++;
		}
		ch[p[i]].push_back(i);
	}
	dfs(1);
	for(int i=1; i<=n ;i++){
		for(int j=0; j<ans[i].size() ;j++){
			cout << ans[i][j];
			if(j==ans[i].size()-1) cout << '\n';
			else cout << '.';
		}
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}