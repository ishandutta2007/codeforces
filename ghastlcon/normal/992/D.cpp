#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 200020
#define oo 2000000000000000000LL
#define int long long
using namespace std;

int a[N];
vector<int> z;
int f[N];

signed main(void)
{
    int n, k;
    int i, j, p;
    int t, s, d, o;

    scanf("%I64d %I64d", &n, &k);
    for(i = 0; i < n; i ++)
    {
        scanf("%I64d", &a[i]);
        if(a[i] != 1)
            z.push_back(i);
        f[i] = -1;
    }
    for(i = 0; i < (signed)z.size(); i ++)
        for(j = i ? z.at(i - 1) : 0; j < z.at(i); j ++)
            f[j] = z.at(i);
    // for(i = 0; i < n; i ++) cout << f[i] << ' '; cout << endl;

    for(i = o = 0; i < n; i ++)
        if(a[i] == 1)
        {
            o += k == 1;
            if(f[i] != -1)
            {
                for(j = f[i], p = f[i] - 1, t = 1, s = f[i] - i;j != -1;p = j, j = f[j])
                {
                    if(oo / t < a[j])
                        break;
                    t *= a[j];
                    s += a[j] + j - p - 1;

                    if(!(t % k) && s <= t / k)
                    {
                        d = f[j] == -1 ? n - j - 1 : f[j] - j - 1;
                        o += s + d >= t / k;
                    }
                }
            }
        }
        else
        {
            if(f[i] == -1)
                o += k == 1;
            else
            {
                for(j = i, p = i - 1, t = 1, s = 0;j != -1;p = j, j = f[j])
                {
                    if(oo / t < a[j])
                        break;
                    t *= a[j];
                    s += a[j] + j - p - 1;

                    if(!(t % k) && s <= t / k)
                    {
                        d = f[j] == -1 ? n - j - 1 : f[j] - j - 1;
                        o += s + d >= t / k;
                    }
                }
            }
        }
        printf("%I64d\n", o);

    return 0;
}