#include <bits/stdc++.h>
using namespace std;

int n, a[1005], ans;
int deg10[15];
int u[1001005];
bool good = true;

void brute(int cur, int idx, int k) {
    if (!good) return;
    if (idx == 6) {
        if (k == 0) {
            if (u[cur])
                good = false;
            else
                u[cur] = 1;
        }
        return;
    }

    if (6 - idx > k)
        brute(cur, idx + 1, k);

    if (k > 0) {
        int curdigit = cur / deg10[idx] % 10;
        for (int i = 0; i <= 9; ++i) {
            if (i == curdigit)
                continue;
            brute(cur + (i - curdigit) * deg10[idx], idx + 1, k - 1);
        }
    }
}

int main()
{
    deg10[0] = 1;
    for (int i = 1; i <= 9; ++i)
        deg10[i] = deg10[i - 1] * 10;

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int k = 6; k >= 0; --k) {
        good = true;
        for (int i = 0; i < 1001005; ++i)
            u[i] = 0;

        for (int i = 0; good && i < n; ++i)
            brute(a[i], 0, k);

        if (good) {
            cout << k;
            return 0;
        }
    }

    return 0;
}