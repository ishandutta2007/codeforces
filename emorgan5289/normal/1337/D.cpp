#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 2000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; fin >> t;
    while (t--) {
        array<ll, 3> n; fin >> n[0] >> n[1] >> n[2];
        array<vector<ll>, 3> a;
        for (int i = 0; i < 3; i++) {
            a[i].assign(n[i], 0);
            for (auto& x : a[i]) fin >> x;
            sort(all(a[i]));
        }
        array<ll, 3> p = {0, 1, 2};
        ll out = inf_ll;
        for (int j = 0; j < 6; j++) {
            for (int i = 0; i < n[p[0]]; i++) {
                ll x = a[p[0]][i];
                auto iy = upper_bound(all(a[p[1]]), x);
                auto iz = lower_bound(all(a[p[2]]), x);
                if (iy == a[p[1]].begin() || iz == a[p[2]].end())
                    continue;
                ll y = *(--iy), z = *iz;
                out = min(out, (x-y)*(x-y) + (z-y)*(z-y) + (x-z)*(x-z));
            }
            next_permutation(all(p));
        }
        cout << out << "\n";
    }
}