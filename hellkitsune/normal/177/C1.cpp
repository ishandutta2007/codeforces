#include <iostream>

using namespace std;

int n, k, m, cnt;
bool fr[2000][2000] = {{false}};
bool en[2000][2000] = {{false}};
int c[2000] = {0}, d[2000];

void go(int i)
{
    c[i] = 1;
    d[cnt++] = i;
    for (int j = 0; j < n; ++j)
        if (!c[j] && fr[i][j])
            go(j);
}

int main(void)
{
    int i, j, t, mx = 0;
    cin >> n >> k;
    for (i = 0; i < k; ++i)
    {
        cin >> j >> t;
        --j;
        --t;
        fr[j][t] = true;
        fr[t][j] = true;
    }
    cin >> m;
    for (i = 0; i < m; ++i)
    {
        cin >> j >> t;
        --j;
        --t;
        en[j][t] = true;
        en[t][j] = true;
    }
    for (i = 0; i < n; ++i)
        if (!c[i])
        {
            cnt = 0;
            go(i);
            if (cnt < mx)
                continue;
            bool flag = true;
            for (i = 0; flag && (i < cnt - 1); ++i)
                for (j = i + 1; flag && (j < cnt); ++j)
                    if (en[d[i]][d[j]])
                        flag = false;
            if (flag)
                mx = cnt;
        }
    cout << mx;
    return 0;
}