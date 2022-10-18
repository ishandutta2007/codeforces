#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, q, c, xa, ya, xb, yb, t;
int sx[100105], sy[100105], sz[100105];
int sum[15][105][105];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> q >> c;
    for (int i = 0; i < n; ++i)
        cin >> sx[i] >> sy[i] >> sz[i];
    for (int i = 0; i <= c; ++i) {
        for (int j = 0; j < n; ++j)
            sum[i][sy[j]][sx[j]] += (sz[j] + i) % (c + 1);
        for (int y = 1; y <= 100; ++y)
            for (int x = 1; x <= 100; ++x)
                sum[i][y][x] += sum[i][y - 1][x] + sum[i][y][x - 1] - sum[i][y - 1][x - 1];
    }

    while (q--) {
        cin >> t >> xa >> ya >> xb >> yb;
        t %= c + 1;
        cout << sum[t][yb][xb] - sum[t][yb][xa - 1] - sum[t][ya - 1][xb] + sum[t][ya - 1][xa - 1] << "\n";
    }

    return 0;
}