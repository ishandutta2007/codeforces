#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 100100;
const ll mod = 998244353        ;

using namespace std;

int n;
int k;
int len;
int a[N];
int d[N][102];
int s[N][102];
int all[N];

bool nat(int l, int r, int x)
{
        return s[r][x] - s[l - 1][x] == r - l + 1;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k >> len;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                for(int j = 1; j <= k; j++){
                        s[i][j] = s[i - 1][j];
                }
                if(a[i] != -1){
                        s[i][a[i]]++;
                }
                else{
                        for(int j = 1; j <= k; j++){
                                s[i][j]++;
                        }
                }
        }
        if(len == 1){
                cout << 0 << "\n";
                return 0;
        }
        if(a[1] != -1){
                d[1][a[1]] = 1;
        }
        else{
                for(int j = 1; j <= k; j++){
                        d[1][j] = 1;
                }
        }
        for(int i = 1; i <= k; i++){
                all[1] += d[1][i];
        }
        all[0] = 1;
        for(int i = 2; i <= n; i++){
                for(int j = 1; j <= k; j++){
                        if(a[i] != -1 && a[i] != j){
                                continue;
                        }
                        d[i][j] = all[i - 1];
                        if(i >= len && nat(i - len + 1, i, j)){
                                int g = all[i - len] - d[i - len][j];
                                if(g < 0){
                                        g += mod;
                                }
                                d[i][j] -= g;
                                if(d[i][j] < 0){
                                        d[i][j] += mod;
                                }
                        }
                        all[i] += d[i][j];
                        if(all[i] >= mod){
                                all[i] -= mod;
                        }
                }
        }
        cout << all[n] << "\n";
}