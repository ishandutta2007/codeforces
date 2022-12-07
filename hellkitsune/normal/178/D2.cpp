#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool found = false;
int n, k, s, g[16], c[16], a[4][4], sum1 = 0, sum2 = 0, hsum[4] = {0}, vsum[4] = {0};
vector<int> v;

void go(int x, int y, bool col)
{
    if ((x == 3) && (y == 1) && (sum2 != s))
        return;
    for (int i = 0; i < k; ++i)
        if (c[i] && !found)
        {
            --c[i];
            a[x][y] = g[i];
            hsum[x] += g[i];
            vsum[y] += g[i];
            if (x == y)
                sum1 += g[i];
            if (x == n - y - 1)
                sum2 += g[i];
            if (col)
            {
                if (x < n - 1)
                    go(x + 1, y, true);
                else
                {
                    if (y == n - 1)
                    {
                        if ((sum1 == s) && (hsum[n - 1] == s) && (vsum[n - 1] == s) && (sum2 == s))
                            found = true;
                    }
                    else
                        if (vsum[y] == s)
                            go(y + 1, y + 1, false);
                }
            }
            else
            {
                if (y < n - 1)
                    go(x, y + 1, false);
                else
                {
                    if (x == n - 1)
                    {
                        if ((sum1 == s) && (hsum[n - 1] == s) && (vsum[n - 1] == s) && (sum2 == s))
                            found = true;
                    }
                    else
                        if (hsum[x] == s)
                            go(x + 1, x, true);
                }
            }
            hsum[x] -= g[i];
            vsum[y] -= g[i];
            if (x == y)
                sum1 -= g[i];
            if (x == n - y - 1)
                sum2 -= g[i];
            ++c[i];
        }
}

int main()
{
    int j;
    cin >> n;
    for (int i = 0; i < n * n; ++i)
    {
        cin >> j;
        v.push_back(j);
        s += j;
    }
    s /= n;
    sort(v.begin(), v.end());
    g[0] = v[0];
    c[0] = 1;
    k = 1;
    for (int i = 1; i < (int)v.size(); ++i)
    {
        if (v[i] == v[i - 1])
            ++c[k - 1];
        else
        {
            c[k] = 1;
            g[k] = v[i];
            ++k;
        }
    }
    go(0, 0, false);
    cout << s << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}