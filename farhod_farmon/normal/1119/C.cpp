#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 550;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int a[N][N];
int b[N][N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cin >> a[i][j];
                }
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cin >> b[i][j];
                }
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        if(i + 1 <= n && j + 1 <= m){
                                if(a[i][j]){
                                        a[i][j] ^= 1;
                                        a[i + 1][j] ^= 1;
                                        a[i][j + 1] ^= 1;
                                        a[i + 1][j + 1] ^= 1;
                                }
                                if(b[i][j]){
                                        b[i][j] ^= 1;
                                        b[i + 1][j] ^= 1;
                                        b[i][j + 1] ^= 1;
                                        b[i + 1][j + 1] ^= 1;
                                }
                        }
                        if(a[i][j] != b[i][j]){
                                cout << "No" << "\n";
                                return 0;
                        }
                }
        }
        cout << "Yes" << "\n";
}