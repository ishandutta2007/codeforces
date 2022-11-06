// Almost Fault-Tolerant Database (https://codeforces.com/contest/1492/problem/E)
// begin "cp-lib/boilerplate.hpp"
#include <bits/stdc++.h>

#define _choose(_1, _2, _3, chosen, ...) chosen
#define _rep(i, l, r)     for (int i = l; i < r; ++i)
#define _rep0(i, r)       _rep(i, 0, r)
#define _repr(i, r, l)    for (int i = r; i >= l; --i)
#define _repr0(i, r)      _repr(i, r, 0)
#define rep(...)          _choose(__VA_ARGS__, _rep, _rep0, suppress_warning)(__VA_ARGS__)
#define repr(...)         _choose(__VA_ARGS__, _repr, _repr0, suppress_warning)(__VA_ARGS__)
#define all(a)      ::begin(a),::end(a)
#define sz(c)       int(::size(c))
#define trav(a, b)  for(auto& a : b)

using namespace std;

using ll = long long;
using ld = long double;
using u64 = uint64_t;
using u32 = uint32_t;

[[maybe_unused]] static constexpr int INF = int(1e9 + 5);
[[maybe_unused]] static constexpr ll INFL = ll(INF) * INF;
[[maybe_unused]] static mt19937 rng(u32(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count()));

namespace cp_lib {}
// end "cp-lib/boilerplate.hpp"

using namespace cp_lib;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // comp first and other rows
    // - n*m
    // if all pairs have <= 2 diffs
    // - take first row
    // else
    // - there is some row pair with 4 or 3 diffs
    // case 3:
    // - guess which two pos are correct for exactly one of my two rows (factor 3 choose 2)
    // - guess which row is correct on which of those twos pos's (factor 2)
    // - 3 choose 2 * 2 * n*m = 6 * n * m
    // case 4:
    // - guess which two pos are correct in first row
    // - other two pos must be correct in other row of 4-diff-pair
    // - 4 choose 2 * n*m = 6 * n * m

    auto print = [](auto vec) {
        cout << "Yes\n";
        trav(ai, vec)
            cout << ai << ' ';
        cout << '\n';
        exit(0);
    };

    int n, m; cin >> n >> m;
    auto a = vector(n, vector(m, 0));
    rep(i, n) rep(j, m) cin >> a[i][j];

    rep(i, 1, n) {
        vector<int> pos;
        rep(j, m)
            if (a[0][j] != a[i][j])
                pos.push_back(j);
        if (sz(pos) > 4)
            cout << "No\n", exit(0);
        if (sz(pos) < 3)
            continue;

        vector<int> guess(m);
        if (sz(pos) == 3) {
            trav(x, pos) {
                int y = (x == pos[0] ? pos[1] : pos[0]),
                    z = (x == pos[2] ? pos[1] : pos[2]);
                rep(b, 2) {
                    bool possible = true;
                    guess = a[0];
                    if (b)
                        guess[y] = a[0][y], guess[z] = a[i][z];
                    else
                        guess[z] = a[0][z], guess[y] = a[i][y];

                    int val_x = -1;
                    rep(j, n) {
                        int diff = 0;
                        rep(k, m)
                            if (k != x)
                                diff += (guess[k] != a[j][k]);
                        if (diff > 2) {
                            possible = false;
                            break;
                        } else if (diff == 2) {
                            if (val_x != -1 && val_x != a[j][x]) {
                                possible = false;
                                break;
                            }
                            val_x = a[j][x];
                        }
                    }

                    if (possible) {
                        guess[x] = (val_x == -1 ? 1 : val_x);
                        cout << "Yes\n";
                        trav(ai, guess)
                            cout << ai << ' ';
                        cout << '\n';
                        return 0;
                    }
                }
            }

            cout << "No\n";
            return 0;
        }

        rep(xi, 4) rep(yi, xi + 1, 4) {
            int x = pos[xi], y = pos[yi];
            guess = a[0];
            trav(j, pos) {
                if (j == x || j == y)
                    guess[j] = a[0][j];
                else
                    guess[j] = a[i][j];
            }

            bool possible = true;
            rep(j, n) {
                int diff = 0;
                rep(k, m)
                    diff += (guess[k] != a[j][k]);
                possible &= (diff <= 2);
            }

            if (possible) {
                cout << "Yes\n";
                trav(ai, guess)
                    cout << ai << ' ';
                cout << '\n';
                return 0;
            }
        }

        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";
    trav(ai, a[0])
        cout << ai << ' ';
    cout << '\n';

    return 0;
}

/*
10 7
1 1 1 1 1 2 2
1 1 1 1 2 2 1
1 1 1 2 2 1 1
1 1 2 2 1 1 1
1 2 2 1 1 1 1
1 1 1 1 1 1 2
2 2 1 1 1 1 1
1 1 1 1 1 1 1
2 1 1 1 1 1 1
1 1 1 1 1 1 1
*/