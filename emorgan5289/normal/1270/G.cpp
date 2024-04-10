#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n+1), v(n+1, 0), r;
        for (int i = 1; i <= n; i++)
            cin >> a[i], a[i] = i-a[i];
        int j = 1, x = 1;
        while (!v[x])
            v[x] = j++, x = a[x];
        for (int i = 1; i <= n; i++)
            if (v[i] >= v[x]) r.pb(i);
        cout << r.size() << "\n";
        for (auto& i : r) cout << i << " ";
        cout << "\n";
    }
}