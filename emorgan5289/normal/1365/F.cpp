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

const int maxn = 505;
int a[maxn], b[maxn];
pair<int, int> pa[maxn], pb[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < n/2; i++) {
            if (a[i] < a[n-1-i]) swap(a[i], a[n-1-i]);
            if (b[i] < b[n-1-i]) swap(b[i], b[n-1-i]);
            pa[i] = {a[i], a[n-1-i]};
            pb[i] = {b[i], b[n-1-i]};
        }
        sort(pa, pa+n/2); sort(pb, pb+n/2);
        bool v = n%2 == 0 || a[n/2] == b[n/2];
        for (int i = 0; i < n/2; i++)
            v = v && pa[i] == pb[i];
        cout << (v ? "Yes" : "No") << "\n";
    }
}