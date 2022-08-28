#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll a, b, x;
int tag;
void dfs(ll b, ll a) {
    if (a == x) return tag = 1, void();
    if (a == b) return;
    b = min(b, a - b);
    ll to = a % b;
    if (to < b) to += b;
    if (x >= to && x <= a && x % b == to % b) tag = 1;
    dfs(min(to, b), max(to, b));
}
void rmain() {
    cin >> a >> b >> x;
    tag = 0;
    dfs(min(a, b), max(a, b));
    cout << (tag ? "YES" : "NO") << endl;
}
int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) rmain();
}