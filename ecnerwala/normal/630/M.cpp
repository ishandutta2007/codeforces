#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll normalize(ll v) { v %= 360; if(v < 0) v += 360; return min(v, 360 - v); }
int main() {
ll n; cin >> n;
ll res = 0;
for(ll i = 1; i <= 4; i++) {
if(normalize(n - 90 * i) < normalize(n - 90 * res)) res = i;
}
cout << res << '\n';
}