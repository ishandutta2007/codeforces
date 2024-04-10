// Example program
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 2000;
const int MAXM = 2000;
const int SIGMA = 26;

char a[1 + MAXN + 1][1 + MAXM + 1];
int cSmall[SIGMA], cBig[SIGMA], lSmall[SIGMA], lBig[SIGMA];

bool Check(int n, int m, int ch) {
    if (cBig[ch] == -1)
        return true;
    if (cSmall[ch] != cBig[ch] && lSmall[ch] != lBig[ch])
        return false;
    int dl, dc;
    if (cSmall[ch] == cBig[ch]) {
        dl = 1;
        dc = 0;
    }
    else {
        dl = 0;
        dc = 1;
    }
    int l = lSmall[ch], c = cSmall[ch];
    while (l <= lBig[ch] && c <= cBig[ch]) {
        if (a[l][c] == '.' || a[l][c] - 'a' < ch)
            return false;
        l += dl;
        c += dc;
    }
    return true;
}

int main() {
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < SIGMA; i++) {
            cSmall[i] = lSmall[i] = 2 * MAXN;
            cBig[i] = lBig[i] = -1;
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i] + 1;
            for (int j = 1; j <= m; j++) {
                if (a[i][j] == '.')
                    continue;
                int x = a[i][j] - 'a';
                lSmall[x] = min(lSmall[x], i);
                lBig[x] = max(lBig[x], i);
                cSmall[x] = min(cSmall[x], j);
                cBig[x] = max(cBig[x], j);
            }
        }
        bool bad = false;
        int howMany = SIGMA - 1;
        while (howMany >= 0 && lBig[howMany] == -1)
            howMany--;
        for (int i = 0; i <= howMany; i++)
            if (!Check(n, m, i))
                bad = true;
        if (bad)
            cout << "NO\n";
        else {
            cout << "YES\n" << howMany + 1 << "\n";
            for (int i = 0; i <= howMany; i++)
                if (cBig[i] != -1)
                    cout << lSmall[i] << " " << cSmall[i] << " " << lBig[i] << " " << cBig[i] << "\n";
                else
                    cout << lSmall[howMany] << " " << cSmall[howMany] << " " << lSmall[howMany] << " " << cSmall[howMany] << "\n";
        }
    }
    return 0;
}