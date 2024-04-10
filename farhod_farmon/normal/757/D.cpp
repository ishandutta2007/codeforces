#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 77;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
int c[N][N];
int d[N][1 << 20];
bool good[1 << 20];

int get(int l, int r)
{
        int x = 0;
        for(int i = l; i <= r; i++){
                x = x * 2 + a[i];
                if(x > 20){
                        return -1;
                }
        }
        return x - 1;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                char c;
                cin >> c;
                a[i] = c - '0';
        }
        for(int i = 1; i <= n; i++){
                for(int j = i; j <= n; j++){
                        c[i][j] = get(i, j);
                }
        }
        for(int i = 0; i < (1 << 20); i++){
                good[i] = true;
                int h = -1;
                for(int j = 0; j < 20; j++){
                        if(i & (1 << j)){
                                h = j;
                        }
                }
                for(int j = 0; j <= h; j++){
                        if((i & (1 << j)) == 0){
                                good[i] = false;
                        }
                }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
                for(int mask = 0; mask < (1 << 20); mask++){
                        for(int j = 1; j <= i; j++){
                                int x = c[j][i];
                                if(x == -1){
                                        continue;
                                }
                                d[i][mask | (1 << x)] += d[j - 1][mask];
                                if(d[i][mask | (1 << x)] >= mod){
                                        d[i][mask | (1 << x)] -= mod;
                                }
                        }
                }
                for(int j = 1; j <= i; j++){
                        int x = c[j][i];
                        if(x == -1){
                                continue;
                        }
                        d[i][1 << x]++;
                        if(d[i][1 << x] >= mod){
                                d[i][1 << x] -= mod;
                        }
                }
                for(int mask = 0; mask < (1 << 20); mask++){
                        if(good[mask]){
                                ans += d[i][mask];
                                if(ans >= mod){
                                        ans -= mod;
                                }
                        }
                }
        }
        cout << ans << "\n";
}