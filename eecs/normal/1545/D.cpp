#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int m, K, x[maxn][maxn], s[maxn];
long long s2[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin >> m >> K;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x[i][j], s[i] += x[i][j];
            s2[i] += 1LL * x[i][j] * x[i][j];
        }
    }
    int sv = (s[K - 1] - s[0]) / (K - 1);
    for (int i = 1; i < K - 1; i++) {
        if (s[i] == s[0] + sv * i) continue;
        int pos = i + 1;
        while (2 * pos - 4 * i == 0) pos++;
        long long sv2 = ((s2[pos] - s2[0]) / pos * 2 - (s2[i + 1] - s2[i - 1])) / (2 * pos - 4 * i);
        long long _s2 = s2[i - 1] + (s2[i + 1] - s2[i - 1]) / 2 - sv2;
        for (int j = 0; j < m; j++) {
            int _x = x[i][j] + s[0] + sv * i - s[i];
            if (s2[i] - 1LL * x[i][j] * x[i][j] + 1LL * _x * _x == _s2) {
                cout << i << " " << _x << endl; break;
            }
        }
    }
    return 0;
}