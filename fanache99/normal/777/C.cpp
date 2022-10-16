//#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 100000;

int dp[1 + MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a, best;
    a.resize(n + 1);
    best.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        a[i].resize(m + 1);
        best[i].resize(m + 1);
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = i;
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] >= a[i - 1][j])
                best[i][j] = best[i - 1][j] + 1;
            else
                best[i][j] = 1;
            dp[i] = min(dp[i], i - best[i][j] + 1);
        }
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        if (dp[y] <= x)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}