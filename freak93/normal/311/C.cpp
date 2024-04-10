#include <iostream>
#include <vector>
#include <set>
#include <limits>

using namespace std;

const int kMaxN = 1000005;

long long H, A[kMaxN];
int N, M, K, C[kMaxN], good[kMaxN];

set< pair<int, int> > S;
vector<long long> OP;

void mark() {
    vector<long long> shortest(K, numeric_limits<long long>::max());
    shortest[0] = 0;

    set< pair<long long, int> > D;
    D.insert({0, 0});
    while (!D.empty()) {
        auto v = *D.begin();
        D.erase(D.begin());
        if (v.first > H)
            continue;
        for (auto &x : OP) {
            int y = (v.second + x) % K;
            if (shortest[y] > v.first + x) {
                D.erase({shortest[y], y});
                shortest[y] = v.first + x;
                D.insert({shortest[y], y});
            }
        }
    }

    S.clear();
    for (int i = 0; i < N; ++i)
        if (good[i] != -1) {
            if (shortest[A[i] % K] <= A[i]) {
                good[i] = 1;
                S.insert({C[i], -i});
            } else
                good[i] = 0;
        }
}

int main() {
    cin.sync_with_stdio(false);
    cin >> H >> N >> M >> K;

    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> C[i];
        --A[i];
    }

    mark();
    for (int i = 0; i < M; ++i) {
        int type; cin >> type;
        if (type == 1) {
            long long x; cin >> x;
            OP.push_back(x);
            mark();
            continue;
        }

        if (type == 2) {
            int x, y; cin >> x >> y;
            --x;
            S.erase({C[x], -x});
            C[x] -= y;
            if (good[x] == 1)
                S.insert({C[x], -x});
            continue;
        }

        if (S.size()) {
            cout << S.rbegin() -> first << "\n";
            good[-(S.rbegin() -> second)] = -1;
            S.erase(*S.rbegin());
        } else {
            cout << 0 << "\n";
        }
    }
}