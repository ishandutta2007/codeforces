#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    int N, M; cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    vector<int> B(M);
    for (int i = 0; i < M; ++i)
        cin >> B[i];

    sort(B.begin(), B.end());

    int answer = 0;

    vector<int> have(32, 0);
    for (vector<int>::iterator it = A.begin(); it != A.end(); ++it) {
        int x = *it;
        for (int i = 0; i < 31; ++i)
            if ((1 << i) & x)
                ++have[i];
    }

    for (vector<int>::iterator it = B.begin(); it != B.end(); ++it) {
        int x = *it;
        if (have[x] < 0)
            return -1;
        if (!have[x]) {
            for (int i = x + 1; i < 31; ++i)
                if (have[i]) {
                    --have[i];
                    for (int j = x; j < i; ++j)
                        have[j] = 1;
                    break;
                }
            if (have[x])
                have[x] = 2;
        }

        if (!have[x])
            break;
        --have[x];
        ++answer;
    }

    cout << answer << "\n";
}