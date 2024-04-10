#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;
int p[9];
int a[9][9];
int u[1005];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    int mmask = 1;
    for (int i = 0; i < n; ++i) {
        p[i] = i;
        mmask *= 6;
        for (int j = 0; j < 6; ++j)
            cin >> a[i][j];
    }

    do {
        int mask = mmask;
        while (mask--) {
            int cur = 0;
            int qqq = mask;
            for (int i = 0; i < n; ++i) {
                cur = cur * 10 + a[p[i]][qqq % 6];
                qqq /= 6;
                u[cur] = 1;
            }
        }
    } while (next_permutation(p, p + n));

    for (int i = 1; i <= 1000; ++i) {
        if (!u[i]) {
            cout << i - 1 << endl;
            break;
        }
    }


    return 0;
}