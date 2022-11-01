#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define all(a) (a).begin(), (a).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<int> a(t), cnt(t);
    for (int i = 0; i < t; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    if (*max_element(all(cnt)) == 1) {
        cout << 1 << ' ' << t << endl
             << 1 << ' ' << 1;
        return 0;
    }
    vector<int> inf_board(t);
    inf_board[0] = 1;
    for (int i = 1; i < t; ++i) {
        inf_board[i] = 4 * i;
    }
    for (int i = 0; i < t; ++i) {
        if (cnt[i] > inf_board[i]) {
            cout << -1;
            return 0;
        }
    }
    vector<int> d;
    for (int i = 1; i * i <= t; ++i) {
        if (t % i == 0) {
            d.push_back(i);
            d.push_back(t / i);
        }
    }
    vector<int> kek(t + 1);
    kek[0] = 0;
    for (int i = 1; i <= t; ++i) {
        kek[i] = 2 * i - 1;
    }
    for (int n : d) {
        int m = t / n;
        int row = -1;
        for (int i = 0; i < t; ++i) {
            if (cnt[i] < inf_board[i]) {
                row = i;
                break;
            }
        }
        if (row == -1) {
            continue;
        }
        int dist1 = row - 1;
        int dist2 = n - row;
        int col = -1;
        for (int i = row; i < t; ++i) {
            int estimated = inf_board[i];
            if (i >= dist1) {
                estimated -= kek[i - dist1];
            }
            if (i >= dist2) {
                estimated -= kek[i - dist2];
            }
            if (cnt[i] < estimated) {
                col = i;
                break;
            }
        }
        if (col == -1 || col > m) {
            continue;
        }
        --row, --col;
        vector<int> new_cnt(t);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ++new_cnt[abs(i - row) + abs(j - col)];
            }
        }
        if (cnt != new_cnt) {
            continue;
        }
        cout << n << ' ' << m << endl
             << row + 1 << ' ' << col + 1 << endl;
        return 0;
    }
    cout << -1;
    return 0;
}