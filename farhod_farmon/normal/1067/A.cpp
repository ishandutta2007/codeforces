#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int mod = 998244353;

using namespace std;

int n;
int a[N];
int d[N][202][2];
int s[N][202][2];

void add(int &x, int y)
{
        x += y;
        while(x >= mod){
                x -= mod;
        }
        while(x < 0){
                x += mod;
        }
}

int main()
{
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        if(a[1] == -1){
                for(int j = 1; j <= 200; j++){
                        d[1][j][0] = 1;
                        s[1][j][0] = j;
                }
        }
        else{
                d[1][a[1]][0] = 1;
                for(int j = a[1]; j <= 200; j++){
                        s[1][j][0] = 1;
                }
        }
        for(int i = 2; i <= n; i++){
                int l = 1, r = 200;
                if(a[i] != -1){
                        l = r = a[i];
                }
                for(int j = l; j <= r; j++){
                        add(d[i][j][0], s[i - 1][j - 1][0]);
                        add(d[i][j][0], s[i - 1][j - 1][1]);
                        add(d[i][j][1], s[i - 1][200][1]);
                        add(d[i][j][1], - s[i - 1][j - 1][1]);
                        add(d[i][j][1], d[i - 1][j][0]);
                }
                for(int j = 1; j <= 200; j++){
                        add(s[i][j][0], s[i][j - 1][0]);
                        add(s[i][j][0], d[i][j][0]);
                        add(s[i][j][1], s[i][j - 1][1]);
                        add(s[i][j][1], d[i][j][1]);
                }
        }
        int ans = 0;
        for(int i = 1; i <= 200; i++){
                add(ans, d[n][i][1]);
        }
        cout << ans << "\n";
}