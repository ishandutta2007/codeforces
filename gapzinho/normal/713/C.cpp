#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef long long ll;
typedef pair<int, int> ii;

const int ms = 3005, mod = 998244353;

int arr[ms];

void solve() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i] -= i;
	}
	priority_queue<int> pq;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		pq.push(arr[i]);
		pq.push(arr[i]);
		// cout << arr[i] << ' '
		ans += pq.top() - arr[i];
		pq.pop();
		// pq.pop();
	}
	cout << ans << endl;
}

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
	    
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int tc = 1;
    //cin >> tc;
    while(tc--)
        solve();
}