#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9+7;
const ll INF = 0x7f7f7f7f;
const ll INFLL = 0x7f7f7f7f7f7f7f7f;

#define End return 0; }
#define of ios::sync_with_stdio(0); cin.tie(0);
#define story int main() {
#define The

ll rect(ll h, ll v) {
	return (h+1)*(v+1)*(h+v)/2;
}

The story of lame:

ll m, b;
cin >> m >> b;
ll a = m*b;
ll ans = 0;
for (int i = 0; i <= b; i++) {
	ans = max(ans, rect(i*m, b-i));
}
cout << ans << endl;

The End