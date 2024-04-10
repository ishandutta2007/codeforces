#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int Q; cin >> Q;

    while (Q--) {
        string S; cin >> S;

        string T; cin >> T;

        int N = S.size();
        int M = T.size();
        bool found = false;
        for (int i = 0; i < N && !found; ++i)
            for (int j = 0; j < M && !found; ++j) {
                if (j > i || M - j > i + 1)
                    continue;
                bool good = true;
                for (int k = j; k >= 0 && good; --k)
                    if (T[k] != S[i - (j - k)])
                        good = false;
                for (int k = j; k < M && good; ++k)
                    if (T[k] != S[i - (k - j)])
                        good = false;
                if (good)
                    found = true;
            }
        if (found)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}