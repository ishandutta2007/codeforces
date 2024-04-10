#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
ll n,m;
vector<int>v[2];
int ans[N];
void solve(){
	cin >> n;
	v[0].clear();
	v[1].clear();
	int k=0;
	for(int i=1; i<=n ;i++){
		char c;cin >> c;
		int x=c-'0';
		if(v[x].empty()) v[x].push_back(++k);
		ans[i]=v[x].back();
		v[1-x].push_back(v[x].back());
		v[x].pop_back();
	}
	cout << k << '\n';
	for(int i=1; i<=n ;i++) cout << ans[i] << ' ';
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
	
}