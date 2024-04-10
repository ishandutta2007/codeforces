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

The story of this_contest_is_getting_creepy:

int ans;
unsigned ll l, r, m;
cin >> l >> r;
m = l^r;
for (ans = 0; m; ans++) {
	m = m >> 1;
} 
cout << (1LL<<ans) - 1 << endl;

The End