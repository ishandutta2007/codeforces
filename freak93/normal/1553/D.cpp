#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int Q; cin >> Q;

    while (Q--) {
        string S, T; cin >> S >> T;

        int best[2] = {0, 0};

        for (int i = 0; i < int(S.size()); ++i)
            for (int j = 0; j < 2; ++j)
                if (best[j] < int(T.size()) && S[i] == T[best[j]] && i % 2 == (j + best[j]) % 2)
                    ++best[j];

        if (T.size() <= S.size() && best[(S.size() - T.size()) % 2] == int(T.size()))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}