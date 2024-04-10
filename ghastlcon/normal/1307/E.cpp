#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 5020
#define MOD 1000000007
using namespace std;

int a[N];
vector<int> b[2][N];

inline int CountPos(int x, int l, int r)
{
    return (int)(upper_bound(b[0][x].begin(), b[0][x].end(), r) - lower_bound(b[0][x].begin(), b[0][x].end(), l));
}

inline int CountCow(int x, int y)
{
    return (int)(upper_bound(b[1][x].begin(), b[1][x].end(), y) - b[1][x].begin());
}

int main(void)
{
    int n, m, x, y;
    int i, j, k;
    pair<int, int> o, t;

    cin >> n >> m;
    for(i = 1; i <= n; i ++)
    {
        cin >> a[i];
        b[0][a[i]].push_back(i);
    }
    for(i = 1; i <= m; i ++)
    {
        cin >> x >> y;
        b[1][x].push_back(y);
    }
    for(i = 1; i <= n; i ++)
        sort(b[1][i].begin(), b[1][i].end());

    o = make_pair(0, 1);
    for(i = 1; i <= n; i ++)
    {
        x = CountCow(i, (int)b[0][i].size());
        if(x)
        {
            o.first ++;
            o.second = (long long)o.second * x % MOD;
        }
    }

    for(k = 1; k <= n; k ++)
    {
        x = CountCow(a[k], CountPos(a[k], 1, k)) - CountCow(a[k], CountPos(a[k], 1, k) - 1);
        y = CountCow(a[k], CountPos(a[k], k + 1, n));
        t = make_pair(0, 1);

        if(x)
        {
            t.first ++;
            t.second = (long long)t.second * x % MOD;
            if(CountPos(a[k], k + 1, n) >= CountPos(a[k], 1, k))
                y --;
            if(y)
            {
                t.first ++;
                t.second = (long long)t.second * y % MOD;
            }

            for(i = 1; i <= n; i ++)
                if(i != a[k])
                {
                    x = CountCow(i, CountPos(i, 1, k));
                    y = CountCow(i, CountPos(i, k + 1, n));
                    if(!x && y)
                    {
                        t.first ++;
                        t.second = (long long)t.second * y % MOD;
                    }
                    else if(x && !y)
                    {
                        t.first ++;
                        t.second = (long long)t.second * x % MOD;
                    }
                    else if(x == 1 && y == 1)
                    {
                        t.first ++;
                        t.second = (long long)t.second * 2 % MOD;
                    }
                    else if(x && y)
                    {
                        t.first += 2;
                        t.second = (long long)t.second * (((long long)x * y - min(x, y)) % MOD) % MOD;
                    }
                }
        }

        // printf("at pos %d : %d,%d\n", k, t.first, t.second);

        if(t.first > o.first)
            o = t;
        else if(t.first == o.first)
            o.second = (o.second + t.second) % MOD;
    }
    cout << o.first << ' ' << (!o.first ? 1 : o.second) << endl;

    return 0;
}