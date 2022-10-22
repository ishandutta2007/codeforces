#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x7f7f7f7f;

#define End return 0; }
#define of ios::sync_with_stdio(0); cin.tie(0);
#define story int main() {
#define The

The story of wabbits:

int ans = -INF;
int n, k, f, t;
cin >> n >> k;
for (int i = 0; i < n; i++) {
	cin >> f >> t;
	ans = max(ans, f - ((t > k) ? t-k : 0));
}
cout << ans << endl;

The End