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
pair<ll, ll> a[maxn];
priority_queue<ll> pq;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        ll out = 0;
        for (int i = 0; i < n; i++) {
            auto& [m, p] = a[i];
            cin >> m >> p;
            out += p;
        }
        sort(a, a+n);
        int x = 0;
        for (int i = 0; i < n; i++) {
            while (x < n && a[x].first <= i)
                pq.push(a[x++].second);
            if (!pq.empty()) {
                out -= pq.top(); pq.pop();
            }
        }
        cout << out << "\n";
        while (!pq.empty()) pq.pop();
    }
}