#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N; cin >> N;

    vector<int> answer(N, 0);
    for (int i = 2; i <= N; ++i) {
        cout << "? ";
        for (int j = 1; j < N; ++j)
            cout << i << " ";
        cout << 1 << "\n";
        cout.flush();

        int k; cin >> k;
        if (k == 0)
            continue;
        answer[k - 1] = -(i - 1);
    }

    for (int i = 1; i < N; ++i) {
        cout << "? ";
        for (int j = 1; j < N; ++j)
            cout << i << " ";
        cout << N << "\n";
        cout.flush();

        int k; cin >> k;
        if (k == 0)
            continue;
        answer[k - 1] = N - i;
    }

    int delta = *min_element(answer.begin(), answer.end());
    cout << "!";
    for (auto &x : answer)
        cout << " " << x - delta + 1;
    cout.flush();
}