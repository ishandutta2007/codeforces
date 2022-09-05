#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, w[10], o[maxn], id[maxn], f[maxn][maxn], len[maxn], s[11][maxn];
string A, B[maxn];
vector<int> buc[10];

void chk(int &x, int y) {
    if (x < y) x = y;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> A >> n;
    len[0] = A.size();
    reverse(A.begin(), A.end());
    while (A.size() <= 1005) A.push_back('0');
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
        len[i] = B[i].size();
        reverse(B[i].begin(), B[i].end());
        while (B[i].size() <= 1005) B[i].push_back('0');
    }
    for (int i = 0; i < 10; i++) {
        cin >> w[i];
    }
    memset(f, -0x3f, sizeof(f));
    iota(id + 1, id + n + 1, 1);
    f[0][0] = 0;
    for (int i = 0; i < 1005; i++) {
        for (int c = 0; c <= 10; c++) {
            for (int j = 1; j <= n; j++) {
                s[c][j] = s[c][j - 1] + (i >= max(len[0], len[id[j]]) && !c ? 0 : w[(B[id[j]][i] - '0' + c) % 10]);
            }
        }
        for (int j = 0; j < 10; j++) {
            buc[j].clear();
        }
        for (int j = 1; j <= n; j++) {
            o[id[j]] = j;
            buc[B[id[j]][i] - '0'].push_back(id[j]);
        }
        for (int j = 9, k = 0; ~j; j--) {
            for (int x : buc[j]) id[++k] = x;
        }
        for (int c = 0; c < 10; c++) {
            if (A[i] != '?' && c != A[i] - '0') continue;
            if (i == len[0] - 1 && !c) continue;
            for (int j = 0, k = 1; j <= n; j++) if (f[i][j] >= 0) {
                for (; k <= n && B[id[k]][i] - '0' + (o[id[k]] <= j) + c > 9; k++);
                chk(f[i + 1][k - 1], f[i][j] + s[c + 1][j] + s[c][n] - s[c][j]);
            }
        }
    }
    cout << *max_element(f[1005], f[1005] + n + 1) << '\n';
    return 0;
}