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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, p; cin >> n >> p;
    vector<int> a(n); for (auto& x : a) cin >> x;
    sort(all(a));
    int l, x = 0, y = 1e9+5;
    while (x < y) {
        int m = (x+y)/2, v = 1;
        for (int i = m; i < m+n; i++)
            v &= upper_bound(all(a), i)-a.begin()-i+m > 0;
        if (v) y = m;
        else x = m+1;
    }
    l = x, x = 0, y = 1e9+5;
    while (x < y) {
        int m = (x+y+1)/2, v = 1;
        for (int i = m; i < m+n; i++) {
            v &= upper_bound(all(a), i)-a.begin()-i+m < p;
        }
        if (v) x = m;
        else y = m-1;
    }
    cout << max(0, x-l+1) << "\n";
    for (int i = l; i <= x; i++)
        cout << i << " \n"[i==x];
}