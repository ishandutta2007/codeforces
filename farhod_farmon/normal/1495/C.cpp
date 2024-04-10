#include <bits/stdc++.h>

using namespace std;

#ifdef zxc
#include "debug.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug_arr(...) 42
#endif

#define fi first
#define se second

const int N = 505;
const int mod = 1e9 + 7;

int n, m;
int any[N];
char a[N][N];

void solve()
{
        cin >> n >> m;

        for(int i = 1; i <= n; i++){
                any[i] = -1;
                for(int j = 1; j <= m; j++){
                        cin >> a[i][j];
                        if(a[i][j] == 'X'){
                                any[i] = j;
                        }
                }
        }

        int st = 1;
        if(n % 3 == 0){
                st = 2;
        }

        for(int i = st; i <= n; i += 3){
                for(int j = 1; j <= m; j++){
                        a[i][j] = 'X';
                }
                int h = -1;
                if(i + 1 <= n && h == -1){
                        h = any[i + 1];
                }
                if(i + 2 <= n && h == -1){
                        h = any[i + 2];
                }
                if(h == -1){
                        h = 1;
                }

                a[i + 1][h] = a[i + 2][h] = 'X';
        }

        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cout << a[i][j];
                }
                cout << "\n";
        }
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}