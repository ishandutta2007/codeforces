#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0)
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define pre(a) cout<<fixed; cout.precision(a);
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll INF = 1e18;
const int inf = 1e9;

int a1, a2, k1, k2, n;

int main() {
	fast;

	cin >> a1 >> a2 >> k1 >> k2;
	cin >> n;

	if(k1 > k2) swap(a1, a2), swap(k1, k2);

	int ans, ans2;
	int cnt = a1 * (k1-1) + a2 * (k2-1);
	cout << max(0, n - cnt) << " ";

	ans = min(a1, n / k1);
	n -= ans * k1;
	ans += min(a2, n / k2);

	cout << ans;
}