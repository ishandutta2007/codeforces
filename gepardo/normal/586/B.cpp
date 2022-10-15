#include <iostream>
#include <vector>

using namespace std;

int a[2][1000], b[1000], q[2][1000], w[2][1000];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < 2; i++)
        for (int j = 1; j < n; j++)
        {
            if (i == 0) cin >> a[i][j]; else cin >> a[i][n - j];
        }
    for (int i = 0; i < n; i++) cin >> b[i];
    q[0][0] = 0; q[1][0] = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 1; j < n; j++)
            q[i][j] = q[i][j - 1] + a[i][j];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
                 w[i][j] = q[i][j] + b[j] + q[1 - i][n - 1 - j];
            else w[i][j] = q[i][j] + b[n - 1 - j] + q[1 - i][n - 1 - j];
        }
    }
    int res = 123456789;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == (n - 1 - j)) continue;
            int sum = w[0][i] + w[1][j];
            if (sum < res) res = sum;
        }
    cout << res;
}