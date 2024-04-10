#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    int N, M, K; cin >> N >> M >> K;

    map<int, int> A, B;
    set<int> S;
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        A[x]++;
        S.insert(x);
    }

    for (int i = 0; i < M; ++i) {
        int x; cin >> x;
        B[x]++;
        S.insert(x);
    }

    int alice = 0, bob = 0;
    for (auto it = S.rbegin(); it != S.rend(); ++it) {
        alice += A[*it];
        bob += B[*it];

        if (alice > bob) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
}