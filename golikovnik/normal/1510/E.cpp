#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 102;
const int INF = 0x3f3f3f3f;

template<class T>
bool smin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

struct sequence {
        int mass;
        double x;
        double y;
};

sequence add(sequence x, sequence y) {
    if (y.mass == 0) return x;
    if (x.mass == 0) return y;
    return {x.mass + y.mass, (x.x * x.mass + y.x * y.mass) / (x.mass + y.mass),
            (x.y * x.mass + y.y * y.mass) / (x.mass + y.mass)};
}

sequence makeSequence(int m, int n) {
    sequence cur{0, 0, 0};
    int bal = 0;
    for (int i = 0; i < n; ++i) {
        if (m >> i & 1) {
            cur = add(cur, sequence{2 * bal, i + 0.5, bal / 2.0});
            cur = add(cur, sequence{1, i + 2.0 / 3, bal + 1.0 / 3});
            bal++;
        } else {
            bal--;
            cur = add(cur, sequence{2 * bal, i + 0.5, bal / 2.0});
            cur = add(cur, sequence{1, i + 1.0 / 3, bal + 1.0 / 3});
        }
    }
    return cur;
}

vector<vector<vector<pair<sequence, int>>>> gen(int n) {
    vector<vector<vector<pair<sequence, int>>>> ans(n + 1);
    for (int m = 0; m < (1 << n); ++m) {
        int bal = 0;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (m >> i & 1) bal++; else bal--;
            if (bal < 0) ok = false;
        }
        if (ok) {
            auto seq = makeSequence(m, n);
            while (ans[bal].size() <= seq.mass) ans[bal].emplace_back();
            ans[bal][seq.mass].emplace_back(seq, m);
        }
    }
    return ans;
}

#include <ext/pb_ds/assoc_container.hpp>
using ui64 = uint64_t;

struct chash {
    static auto const C = ui64(7e18) + 23;

    ui64 operator()(ui64 x) const {
        return __builtin_bswap64(x * C);
    }

    ui64 operator()(pair<ll, ll> x) const {
        return (*this)(x.first) * 31 + (*this)(x.second);
    }
};

template <class K, class V>
using hash_map = __gnu_pbds::gp_hash_table<K, V, chash>;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;

    int n;
    double X, Y;
    cin >> n >> X >> Y;
    int half = n / 2;
    auto sequences = gen(half);

    int MUL = 1e8;

    vector<vector<hash_map<pair<ll, ll>, int>>> sequencesMap(half + 1);
    for (int b = 0; b <= half; ++b) {
        sequencesMap[b].resize(sequences[b].size());
        for (int m = 0; m < int(sequences[b].size()); ++m) {
            for (int i = 0; i < int(sequences[b][m].size()); ++i) {
                auto[seq, id] = sequences[b][m][i];
                sequencesMap[b][m][{ll(round(seq.x * MUL)), ll(round(seq.y * MUL))}] = id;
            }
        }
    }

    for (int bal = 0; bal <= half; ++bal) {
        for (int m1 = 0; m1 < int(sequences[bal].size()); ++m1) {
            for (auto[seq1, mask1] : sequences[bal][m1]) {
                for (int m2 = 1; m2 < int(sequences[bal].size()); ++m2) {
                    auto x1 = seq1.x;
                    auto y1 = seq1.y;
                    auto x2 = double(X * (m1 + m2) - x1 * m1) / m2;
                    auto y2 = double(Y * (m1 + m2) - y1 * m1) / m2;
                    auto mx2 = int(round((n - x2) * MUL));
                    auto my2 = int(round((y2) * MUL));
                    for (int dx = -1; dx <= 1; ++dx) {
                        for (int dy = -1; dy <= 1; ++dy) {
                            auto it = sequencesMap[bal][m2].find({mx2 + dx, my2 + dy});
                            if (it != sequencesMap[bal][m2].end()) {
                                auto mask2 = it->second;
                                for (int i = 0; i < half; ++i) {
                                    if (mask1 >> i & 1) cout << "("; else cout << ")";
                                }
                                for (int i = 0; i < half; ++i) {
                                    if (mask2 >> (half - i - 1) & 1) cout << ")"; else cout << "(";
                                }
                                cout << '\n';
                                exit(0);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

/*
3
6 2
1 1 2 2 3
6 6
1 1 2 2 3
6 4
1 2 3 4 5
*/