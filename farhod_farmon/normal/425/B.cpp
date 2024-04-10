#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 110;

using namespace std;

int n;
int m;
int k;
int a[N];
int b[N];
int c[N][N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    int ans = 1e9;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> c[i][j];
        }
    }
    if(n <= k){
        for(int h = 0; h < (1 << n); h++){
            for(int i = 1; i <= n; i++){
                if(h & (1 << i - 1))
                    a[i] = 1;
                else
                    a[i] = 0;
            }
            int cnt = 0;
            for(int j = 1; j <= m; j++){
                int x = 0, y = 0;
                for(int i = 1; i <= n; i++){
                    if(a[i] ^ 1 != c[i][j])
                        x++;
                    if(a[i] != c[i][j])
                        y++;
                }
                cnt += min(x, y);
            }
            ans = min(ans, cnt);
        }
    }
    else{
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++)
                b[j] = c[i][j];
            int cnt = 0;
            for(int i = 1; i <= n; i++){
                int x = 0, y = 0;
                for(int j = 1; j <= m; j++){
                    if(1 ^ b[j] != c[i][j])
                        x++;
                    if(b[j] != c[i][j])
                        y++;
                }
                cnt += min(x, y);
            }
            ans = min(ans, cnt);
        }
    }
    if(ans > k)
        ans = -1;
    cout << ans << endl;
}