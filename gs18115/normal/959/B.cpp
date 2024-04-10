#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

string s, a;
long long n, k, i, sum, x, j, y, m0, m[123456], c[123456], d[123456];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> m0;
    map <string, long long> b;
    for (i = 1; i <= n; i ++)
    {
        cin >> s;
        b[s] = i;
    }
    for (i = 1; i <= n; i ++)
    {
        cin >> c[i];
    }
    for (i = 1; i <= k; i ++)
    {
        cin >> x;
        m[i] = 2000000000;
        for (j = 0; j < x; j ++)
        {
            cin >> y;
            d[y] = i;
            if (m[i] > c[y])
            {
                m[i] = c[y];
            }
        }
    }
    for (i = 1; i <= m0; i ++)
    {
        cin >> a;
        sum += m[d[b[a]]];
    }
    cout << sum;
    return 0;
}