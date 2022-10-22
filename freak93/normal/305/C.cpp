#include <iostream>
#include <map>

using namespace std;

int main() {
    int N; cin >> N;

    map<int, int> M;
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        ++M[x];
    }

    int answer = 0;
    for (auto it = M.begin(); it != M.end(); ++it) {
        if (it -> second > 1)
            M[it -> first + 1] += it -> second / 2;
        it -> second %= 2;
        if (it -> second == 0)
            ++answer;
    }

    cerr << answer << "\n";
    answer += M.rbegin()->first + 1 - M.size();
    cout << answer << "\n";
}