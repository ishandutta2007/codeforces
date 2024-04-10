#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef pair<int, int> pii;
typedef long long ll;

int n;
ll k;
int f[50][100105];
ll w[50][100105], mn[50][100105];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> f[0][i];
    for (int i = 0; i < n; ++i) {
        cin >> w[0][i];
        mn[0][i] = w[0][i];
    }

    for (int h = 1; h < 50; ++h) {
        for (int i = 0; i < n; ++i) {
            f[h][i] = f[h-1][f[h-1][i]];
            w[h][i] = w[h-1][i] + w[h-1][f[h-1][i]];
            mn[h][i] = min(mn[h-1][i], mn[h-1][f[h-1][i]]);
        }
    }

    for (int i = 0; i < n; ++i) {
        ll cur = k;
        int curv = i;
        ll answ = 0;
        ll ansmn = 9e18;
        int curlvl = 0;
        while (cur) {
            if (cur % 2) {
                answ += w[curlvl][curv];
                ansmn = min(ansmn, mn[curlvl][curv]);
                curv = f[curlvl][curv];
            }
            cur /= 2;
            ++curlvl;
        }
        cout << answ << " " << ansmn << "\n";
    }

    return 0;
}