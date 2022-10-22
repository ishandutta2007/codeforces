#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string S; cin >> S;

    vector<int> mex(S.size());
    mex[0] = 0;
    mex[1] = 1;
    for (int i = 2; i < int(S.size()); ++i) {
        vector<int> found(2 * S.size(), 0);
        found[mex[i - 2]] = 1;
        for (int j = 0; j + 2 < i; ++j)
            found[mex[j] ^ mex[i - j - 3]] = 1;
        for (int j = 0; j < int(S.size()); ++j)
            if (found[j] == 0) {
                mex[i] = j;
                break;
            }
    }

    auto sg = [&](const string &S) {
        int now = 0;
        int answer = 0;
        for (int i = 1; i < int(S.size()) - 1; ++i)
            if (S[i - 1] == S[i + 1])
                ++now;
            else {
                answer ^= mex[now];
                now = 0;
            }
        answer ^= mex[now];
        return answer;
    };

    if (!sg(S)) {
        cout << "Second\n";
        return 0;
    }

    cout << "First\n";

    for (int i = 1; i < int(S.size()); ++i)
        if (S[i - 1] == S[i + 1]) {
            if (not (sg(S.substr(0, i)) ^ sg(S.substr(i + 1)))) {
                cout << i + 1 << "\n";
                return 0;
            }
        }

}