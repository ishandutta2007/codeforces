#include <iostream>
#include <cstdio>

using namespace std;

int n, m, x[1000] = {0}, y[1000] = {0}, l[2002];
string s[1000];
bool dir[2002];

int main(void)
{
    int i, j, k;
    cin >> n >> m;
    for (i = 0; i < n; ++i)
        cin >> s[i];
    i = j = 0;
    dir[0] = true;
    l[0] = 0;
    x[0] = 1;
    while (true)
    {
        if (dir[i])
            for (k = 0; k < m; ++k)
                if ((s[l[i]][k] == '#') && !y[k])
                {
                    y[k] = x[l[i]] + 1;
                    dir[++j] = false;
                    l[j] = k;
                }
        if (!dir[i])
            for (k = 0; k < n; ++k)
                if ((s[k][l[i]] == '#') && !x[k])
                {
                    x[k] = y[l[i]] + 1;
                    if (k == n - 1)
                    {
                        cout << x[k] - 1;
                        return 0;
                    }
                    dir[++j] = true;
                    l[j] = k;
                }
        ++i;
        if (i > j)
        {
            cout << "-1";
            return 0;
        }
    }
    return 0;
}