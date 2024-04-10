#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 5020
using namespace std;

int c[N], f[N];
vector<int> g[N];

int main(void)
{
    int t, n, k;
    int i, j, m;

    cin >> t;
    while(t --)
    {
        cin >> n >> k;
        m = n;

        fill(c, c + n, 0);
        for(i = 0, j = 1; i < n && m > 0; i ++)
        {
            c[i] = min(m, j);
            m -= j;
            j *= 2;
        }

        // for(i=0;i<n;i++)cout<<c[i]<<' ';cout<<endl;
        for(i = m = 0; i < n; i ++)
            m += i * c[i];
        // cout<<"SUM "<<m<<endl;
        if(m > k || k > n * (n - 1) / 2)
        {
            printf("NO\n");
            continue;
        }

        for(; m < k; m ++)
        {
            // for(i = 0; i < n; i ++)
            //     cout << c[i] << ' '; cout << endl;
            for(i = n - 1; i >= 1; i --)
                if((c[i] - 1) * 2 >= c[i + 1] + 1)
                {
                    c[i] --;
                    c[i + 1] ++;
                    break;
                }
        }

        // for(i = 0; i < n; i ++)
        //     cout << c[i] << ' '; cout << endl; return 0;
        // for(i = 0; i < n - 1; i ++)
        //     if(c[i] * 2 < c[i + 1])
        //     {
        //         puts("FUCK");
        //         throw;
        //     }
        printf("YES\n");
        fill(f + 1, f + n + 1, 2);
        for(i = 0; i < n; i ++)
            g[i].clear();

        g[0].push_back(1);
        for(i = k = 1; i < n; i ++)
            for(j = 0; j < c[i]; j ++)
            {
                printf("%d ", g[i - 1].back());
                if(!-- f[g[i - 1].back()])
                    g[i - 1].pop_back();
                g[i].push_back(++ k);
            }
        printf("\n");
    }

    return 0;
}