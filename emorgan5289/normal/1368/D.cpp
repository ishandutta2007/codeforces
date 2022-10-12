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

const int maxn = 200005;
ll a[maxn], b[maxn], f[64];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < 60; j++)
            if (a[i]&(1<<j)) f[j]++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 60; j++)
            if (f[j]) {
                b[i] |= (1<<j); f[j]--;
            }
    }
    ll x = 0;
    for (int i = 0; i < n; i++)
        x += b[i]*b[i];
    cout << x << "\n";
}