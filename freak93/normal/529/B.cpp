#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N; cin >> N;

    vector<int> W(N), H(N);
    for (int i = 0; i < N; ++i)
        cin >> W[i] >> H[i];
    int answer = numeric_limits<int>::max();
    for (int h = 1; h <= 1000; ++h) {
        bool bad = false;
        vector<int> win;
        int total = 0;
        int necessary = 0;
        for (int i = 0; i < N; ++i) {
            if (W[i] > h && H[i] > h)
                bad = true;
            if (H[i] > h) {
                ++necessary;
                total += H[i];
            } else {
                total += W[i];
                if (W[i] <= h)
                    win.push_back(W[i] - H[i]);
            }
        }

        if (bad)
            continue;
        if (necessary > N / 2)
            continue;
        sort(win.begin(), win.end(), greater<int>());
        for (int i = 0; i < N / 2 - necessary && i < int(win.size()) && win[i] > 0; ++i)
            total -= win[i];
        answer = min(answer, total * h);
    }

    cout << answer << "\n";
}