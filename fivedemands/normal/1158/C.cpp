#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=5e5+2;
int n,m;
int nxt[N];
bool die[N];
vector<int>ch[N];
int ans[N];
int ptr;
void dfs(int id){
	reverse(ch[id].begin(),ch[id].end());
	ans[id]=ptr;
	for(auto cur:ch[id]){
		ptr--;
		dfs(cur);
	}
}
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++) cin >> nxt[i];
	for(int i=1; i<=n+1 ;i++) die[i]=false;
	for(int i=1; i<=n+1 ;i++) ch[i].clear();
	stack<int>s;
	s.push(n+1);
	for(int i=n; i>=1 ;i--){
		if(nxt[i]!=-1){
			if(die[nxt[i]]){
				cout << "-1\n";
				return;
			}
			while(s.top()!=nxt[i]){
				die[s.top()]=true;
				s.pop();
			}
		}
		ch[s.top()].push_back(i);
		s.push(i);
	}
	ptr=n+1;
	dfs(n+1);
	for(int i=1; i<=n ;i++){
		cout << ans[i] << ' ';
	}
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;
	while(t--) solve();
}