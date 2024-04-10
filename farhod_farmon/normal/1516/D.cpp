#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 100100;

int n, q;
int a[N];
int f[N];
int t[N][20];
int c[N], bad;

void upd(int x, int g)
{
        while(x > 1){
                int y = f[x];
                while(x % y == 0){
                        x /= y;
                }

                c[y] += g;
                if(g == 1){
                        bad += (c[y] == 2);
                } else{
                        bad -= (c[y] == 1);
                }
        }
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        for(int i = 2; i < N; i++){
                if(f[i]){
                        continue;
                }
                for(int j = i; j < N; j += i){
                        if(!f[j]){
                                f[j] = i;
                        }
                }
        }

        cin >> n >> q;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }

        t[n + 1][0] = n + 1;

        for(int i = n, j = n + 1; i >= 1; i--){
                upd(a[i], 1);
                while(bad){
                        j -= 1;
                        upd(a[j], -1);
                }
                t[i][0] = j;
        }

        for(int i = 1; i < 20; i++){
                for(int j = 1; j <= n + 1; j++){
                        t[j][i] = t[t[j][i - 1]][i - 1];
                }
        }

        for(int i = 0; i < q; i++){
                int l, r, res = 0;
                cin >> l >> r;

                for(int i = 19; i >= 0; i--){
                        if(t[l][i] <= r){
                                l = t[l][i];
                                res += (1 << i);
                        }
                }

                cout << res + 1 << "\n";
        }
}