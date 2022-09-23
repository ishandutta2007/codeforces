#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 300300;

using namespace std;

int n, a[N];

const int G = 300;
long long f[G];
long long d[G];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        scanf("%d", &n);
        //n = N - 300;
        for(int i = 1; i <= n; i++){
                scanf("%d", a + i);

                //a[i] = 2000;

                a[i] /= 100;
        }

        long long inf = 1e18;
        for(int i = 0; i < G; i++) d[i] = f[i] = inf;
        d[0] = 0;
        for(int i = 1; i <= n; i++){
                int x = a[i], y = a[i] / 10;
                for(int j = 0, nj; j < G; j++){
                        nj = j - min(j, x);
                        f[nj] = min(f[nj], d[j] + x - min(j, x));
                        if(j + y < G)f[j + y] = min(f[j + y], d[j] + x);
                }
                for(int j = 0; j < G; j++){
                        d[j] = f[j];
                        f[j] = inf;
                }
        }
        long long res = inf;
        for(int i = 0; i < G; i++) res = min(res, d[i]);

        cout << res * 100 << "\n";
}