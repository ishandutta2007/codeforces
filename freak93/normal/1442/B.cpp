#include <iostream>
#include <vector>
#include <set>

using namespace std;

static const int kModulo = 998'244'353;

int main() {
    ios::sync_with_stdio(false);

    int T; cin >> T;
    while (T--) {
        int N, K; cin >> N >> K;
        vector<int> pos(N);
        for (int i = 0; i < N; ++i) {
            int x; cin >> x;
            pos[x - 1] = i;
        }

        set<int> S;
        for (int i = 0; i < N; ++i)
            S.insert(i);

        int answer = 1;
        vector<int> B(K);
        for (int i = 0; i < K; ++i) {
            cin >> B[i];
            B[i] = pos[B[i] - 1];
        }

        vector<bool> will_be_deleted(N + 1, false);
        for (auto &x : B)
            will_be_deleted[x] = true;
        will_be_deleted[N] = true;
        for (int i = 0; i < K; ++i) {
            auto it = S.lower_bound(B[i]);
            int before = N;
            if (it != S.begin())
                before = *prev(it,  1);
            int after = N;
            if (++it != S.end())
                after = *it;
            if (will_be_deleted[before] && will_be_deleted[after]) {
                answer = 0;
            } else if (will_be_deleted[before]) {
                S.erase(after);
            } else if (will_be_deleted[after]) {
                S.erase(before);
            } else {
                S.erase(before);
                answer = answer * 2 % kModulo;
            }
            will_be_deleted[B[i]] = false;
        }

        cout << answer << "\n";
    }
}