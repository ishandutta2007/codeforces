#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string S; cin >> S;
    vector< vector<int> > A(260);

    for (int i = 0; i < int(S.size()); ++i)
        A[int(S[i])].push_back(i);

    int last = -1;
    for (int i = 'z'; i >= 'a'; --i)
        for (vector<int>::iterator it = A[i].begin(); it != A[i].end(); ++it) {
            if (*it < last)
                continue;

            last = *it;
            cout << char(i);
        }

}