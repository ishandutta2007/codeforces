#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int INF = 1e9 + 13;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] % k > 0)
            mp[(k - a[i] % k) % k]++;
    }

    int x = 0;
    li ans = 0;

    while(!mp.empty()) {
        auto it = mp.lower_bound(x);

        int res = 0;
        if(it == mp.end()) {
            it = mp.begin();
            res = k - (x - it->f);
        } else {
            res = it->f - x;
        }

//        cout << x << ' ' << res + 1 << endl;

        ans += res + 1;
        x = (it->f + 1) % k;
        it->s--;

        if(it->s == 0) {
            mp.erase(it);
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

}