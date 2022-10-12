#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int maxn = 1000005;
ll n, s, t, out = 0;
ll a[maxn], f[maxn], res[maxn];
array<ll, 3> q[maxn];

bool cmp(array<ll, 3>& x, array<ll, 3>& y) {
    return x[0]/s == y[0]/s ? x[1] < y[1] : x[0] < y[0];
}

void ins(ll x) {
    f[x]++; out += x*(2*f[x]-1);
}

void rem(ll x) {
    out -= x*(2*f[x]-1); f[x]--;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> t; s = sqrt(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < t; i++) {
        cin >> q[i][0] >> q[i][1]; q[i][2] = i;
    }
    sort(q, q+t, cmp);
    int x = 0, y = -1;
    for (int i = 0; i < t; i++) {
        auto& [l, r, j] = q[i]; l--, r--;
        while (x < l) rem(a[x++]);
        while (x > l) ins(a[--x]);
        while (y > r) rem(a[y--]);
        while (y < r) ins(a[++y]);
        res[j] = out;
    }
    for (int i = 0; i < t; i++)
        cout << res[i] << "\n"; 
}