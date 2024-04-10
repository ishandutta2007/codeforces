#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

void query(int i, int j, int k) {
    cout << "? " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
}

void answer(int i, int j) {
    cout << "! " << i + 1 << ' ' << j + 1 << endl;
}

int receive() {
    int x;
    cin >> x;
    if (x == -1) exit(0);
    return x;
}

void solve() {
    int n = receive();

    vector<pii> rd1;
    for (int i = 2; i < n; i++) {
        query(0, 1, i);
        rd1.emplace_back(receive(), i);
    }
    sort(rd1.rbegin(), rd1.rend());

    int x = rd1[0].second;
    int y = rd1[1].second;

    int rd1_max = rd1[0].first;
    int rd1_min = rd1[n - 3].first;
    if (rd1_max == rd1_min) {
        query(x, y, 0);
        int xy0 = receive();
        query(x, y, 1);
        int xy1 = receive();

        if (xy0 < rd1_max && xy1 < rd1_max) {
            answer(0, 1);
            return;
        }
    }

    vector<pii> rd2;
    for (int i = 0; i < n; i++) {
        if (i == x || i == y) continue;
        query(x, y, i);
        rd2.emplace_back(receive(), i);
    }
    sort(rd2.rbegin(), rd2.rend());

    int rd2_max = rd2[0].first;
    int rd2_min = rd2[n - 3].first;
    if (rd2_max == rd2_min) {
        answer(x, y);
    } else {
        answer(x, rd2[0].second);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}