#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

struct Str {
    int a, c;
    ll ac;

    Str combine(const Str& other) const {
        return Str{other.a, c, ac + other.ac + (a && other.c)};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, x, n, m;
    cin >> k >> x >> n >> m;
    for (int c1 = 0; c1 <= 1; ++c1) {
        for (int a1 = 0; a1 <= 1; ++a1) {
            for (int ac1 = 0; 2 * ac1 <= n - c1 - a1; ++ac1) {
                for (int c2 = 0; c2 <= 1; ++c2) {
                    for (int a2 = 0; a2 <= 1; ++a2) {
                        for (int ac2 = 0; 2 * ac2 <= m - c2 - a2; ++ac2) {
                            Str s1{a1, c1, ac1};
                            Str s2{a2, c2, ac2};
                            for (int i = 3; i <= k; ++i) {
                                Str s3 = s1.combine(s2);
                                s1 = s2;
                                s2 = s3;
                            }
                            if (s2.ac == x) {
                                auto getStr = [](int c, int a, int ac, int len) {
                                    string ans = c ? "C" : "";
                                    for (int i = 0; i < ac; ++i)
                                        ans += "AC";
                                    for (int i = 0; i < len - a - c - 2 * ac; ++i)
                                        ans += "B";
                                    ans += a ? "A" : "";
                                    return ans;
                                };
                                string ans1 = getStr(c1, a1, ac1, n);
                                string ans2 = getStr(c2, a2, ac2, m);
                                cout << ans1 << endl;
                                cout << ans2 << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "Happy new year!\n";
}