#include <bits/stdc++.h>
using namespace std;

char s[2005][2005];
int n = 2;

void add(int a, int b) {
    if (a != -1 && b != -1) {
        s[a][b] = s[b][a] = 'Y';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    int len = 0;
    for (int i = 0; i < 30; ++i)
        if (k & (1 << i))
            len = i;
    vector<int> last{0};
    int layers = 0;
    for (int i = len - 1; i >= 0; --i) {
        ++layers;
        n += 2;
        for (int x : last) {
            add(x, n - 2);
            add(x, n - 1);
        }
        last = {n - 2, n - 1};
        if (k & (1 << i)) {
            int cur = 0;
            for (int j = 0; j < layers; ++j) {
                ++n;
                add(cur, n - 1);
                cur = n - 1;
            }
            last.push_back(cur);
        }
    }
    for (int x : last)
        add(x, 1);
    cout << n << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!s[i][j])
                s[i][j] = 'N';
        }
        s[i][n] = 0;
        cout << s[i] << '\n';
    }
}