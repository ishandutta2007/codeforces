#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e5+1;
ll n,m;
ll a[N],b[N];
queue<int>q[N];
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		q[a[i]].push(i);
	}
	int cur=0;
	vector<int>ans;
	while(cur<n){
		int nx=0;
		int bad=cur+1;
		while(!q[nx].empty()){
			bad=max(bad,q[nx].front());
			nx++;
		}
		ans.push_back(nx);
		for(int i=cur+1; i<=bad ;i++){
			q[a[i]].pop();
		}
		cur=bad;
	}
	cout << ans.size() << '\n';
	for(auto c:ans) cout << c << ' ';
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;
	while(t--) solve();
}