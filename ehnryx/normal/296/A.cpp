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

The story of lame:

int count[1001];
memset(count, 0, sizeof(count));
int n, a;
cin >> n;
for (int i = 0; i < n; i++) {
	cin >> a;
	count[a]++;
}
int bad = 0;
for (int i = 1; i <= 1000; i++) {
	bad = max(bad, count[i]);
}
if (bad > (n+1)/2) cout << "NO" << endl;
else cout << "YES" << endl;

The End