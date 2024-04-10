#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const int mod = 31607;

using namespace std;

int n;
long long c[N];
long long f[N];
long long d[N];

void upd(long long *t, int x, int y)
{
        x += 1;
        while(x < N){
                t[x] += y;
                x += x & -x;
        }
}

long long get(long long *t, int x)
{
        x += 1;
        long long res = 0;
        while(x > 0){
                res += t[x];
                x -= x & -x;
        }
        return res;
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n;
        long long res = 0;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;

                res += 1ll * x * (i - 1) + get(d, x);
                upd(c, x, 1);
                upd(f, x, x);

                for(int j = 0; j < N; j += x){
                        upd(d, j, -j);
                        upd(d, min(N - 1, j + x), j);

                        res += get(f, min(N - 2, j + x - 1)) - (j == 0 ? 0 : get(f, j - 1));
                        res -= (get(c, min(N - 2, j + x - 1)) - (j == 0 ? 0 : get(c, j - 1))) * j;
                }

                cout << res << " ";
        }
}