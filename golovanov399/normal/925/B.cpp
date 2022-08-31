#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;

using li = long long;
using ld = long double;

#define all(v) (v).begin(), (v).end()

void solve(bool read);

int main() {
    auto t0 = clock();
#ifdef YA
    assert(freopen("input.txt", "r", stdin));
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    cout.precision(20);
    cout << fixed;

    solve(true);
#ifdef YA1
    while (true) solve(false);
#endif

#ifdef YA
    cerr << endl << endl << (clock() - t0) / (double)CLOCKS_PER_SEC << endl;
#endif
}

#define int li

void solve(bool __attribute__((unused)) read) {
    int n;
    array<int, 2> x = {};
    cin >> n >> x[0] >> x[1];

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(all(a));
    reverse(all(a));

    for (int i = 0; i < n; ++i) {
        for (int t = 0; t < 2; ++t) {
            // a[i] is min taken for x[t]
            int kt = (x[t] + a[i].first - 1) / a[i].first;
            //cout << "at " << i + 1 << " need " << kt << endl;
            if (kt >= i + 1) {
                continue;
            }

            int kOther = i + 1 - kt;
            if (a[kOther - 1].first * kOther >= x[1 - t]) {
                int k1 = kt;
                int k2 = kOther;
                vector<int> ind1, ind2;
                for (int j = i; j >= i - kt + 1; --j) {
                    ind1.push_back(a[j].second + 1);
                }
                for (int j = i - kt; j >= 0; --j) {
                    ind2.push_back(a[j].second + 1);
                }

                if (t == 1) {
                    swap(k1, k2);
                    swap(ind1, ind2);
                }

                cout << "Yes\n";
                cout << k1 << " " << k2 << "\n";
                for (int x: ind1) cout << x << " ";
                cout << "\n";
                for (int x: ind2) cout << x << " ";
                cout << "\n";
                exit(0);
            }
        }
    }

    cout << "No\n";
}