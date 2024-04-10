#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef __int128 i128;
long long n;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    auto ask = [&](long long x, long long y) {
        cout << x << " " << y << endl;
        int z; cin >> z;
        if (!z) exit(0);
        return z;
    };
    vector<tuple<long long, long long, long long, long long>> cand;
    cand.emplace_back(1, n, 1, n);
    for (int q = 1; ; q++) {
        if (!(q % 100)) {
            ask(min(n, 827799669658611477LL), min(n, 979229254105574356LL));
        }
        i128 S = 0;
        long long mx1 = 0, mx2 = 0;
        for (auto &p : cand) {
            mx1 = max(get<1>(p), mx1), mx2 = max(get<3>(p), mx2);
            S += (i128)(get<1>(p) - get<0>(p) + 1) * (get<3>(p) - get<2>(p) + 1);
        }
        long long X, Y;
        if (S <= 6) {
            X = get<0>(cand[0]), Y = get<2>(cand[0]);
        } else {
            S /= 3;
            long long l = 1, r = mx1;
            while (l <= r) {
                long long mid = (l + r) >> 1;
                i128 num = 0;
                for (auto p : cand) if (get<0>(p) <= mid) {
                    num += (i128)(min(mid, get<1>(p)) - get<0>(p) + 1) * (get<3>(p) - get<2>(p) + 1);
                }
                if (num >= S) r = (X = mid) - 1;
                else l = mid + 1;
            }
            l = 1, r = mx2;
            while (l <= r) {
                long long mid = (l + r) >> 1;
                i128 num = 0;
                for (auto p : cand) if (get<2>(p) <= mid) {
                    num += (i128)(get<1>(p) - get<0>(p) + 1) * (min(mid, get<3>(p)) - get<2>(p) + 1);
                }
                if (num >= S) r = (Y = mid) - 1;
                else l = mid + 1;
            }
        }
        int z = ask(X, Y);
        vector<tuple<long long, long long, long long, long long>> ncand;
        if (z == 1) { // a > X
            for (auto &p : cand) if (get<1>(p) > X) {
                ncand.emplace_back(X + 1, get<1>(p), get<2>(p), get<3>(p));
            }
        } else if (z == 2) { // b > Y
            for (auto &p : cand) if (get<3>(p) > Y) {
                ncand.emplace_back(get<0>(p), get<1>(p), Y + 1, get<3>(p));
            }
        } else { // a < X or b < Y
            for (auto &p : cand) {
                if (get<1>(p) < X || get<3>(p) < Y) {
                    ncand.push_back(p); continue;
                }
                if (get<0>(p) < X) {
                    ncand.emplace_back(get<0>(p), X - 1, get<2>(p), get<3>(p));
                    get<0>(p) = X;
                }
                if (get<2>(p) < Y) {
                    ncand.emplace_back(get<0>(p), get<1>(p), get<2>(p), Y - 1);
                }
            }
        }
        cand.clear();
        for (int i = 0, j; i < ncand.size(); i = j) {
            i128 lst = get<1>(ncand[i]);
            for (j = i + 1; j < ncand.size() && get<0>(ncand[j]) == lst + 1 && get<2>(ncand[i]) == get<2>(ncand[j])
                && get<3>(ncand[i]) == get<3>(ncand[j]); j++) {
                lst = get<1>(ncand[j]);
            }
            cand.emplace_back(get<0>(ncand[i]), lst, get<2>(ncand[i]), get<3>(ncand[i]));
        }
    }
    return 0;
}