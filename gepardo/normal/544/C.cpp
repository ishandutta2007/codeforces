#include <iostream>

using namespace std;

int pdp[512][512], qdp[512][512];
int v[512];

int main()
{
    int n, m, b, mod; cin >> n >> m >> b >> mod;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 0; i <= n; i++) qdp[i][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= b; k++)
                pdp[j][k] = qdp[j][k];
        for (int k = 0; k <= b; k++) qdp[0][k] = 0;
        for (int j = 1; j <= n; j++)
            for (int k = 0; k <= b; k++)
                if (k >= v[j]) qdp[j][k] = (qdp[j - 1][k] + pdp[j][k - v[j]]) % mod;
                    else qdp[j][k] = qdp[j - 1][k];
    }
    int res = 0;
    for (int k = 0; k <= b; k++) res = (res + qdp[n][k]) % mod;
    cout << res;
}