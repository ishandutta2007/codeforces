#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 330;
const int mod = 1e9 + 7;

using namespace std;

int n, m;
int a[N][N];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                cin >> n >> m;
                for(int i = 1; i <= n; i++){
                        for(int j = 1; j <= m; j++){
                                a[i][j] = 3;
                        }
                }
                a[1][1] = a[1][m] = a[n][1] = a[n][m] = 2;
                for(int i = 2; i < n; i++){
                        for(int j = 2; j < m; j++){
                                a[i][j] = 4;
                        }
                }
                int res = 1;
                for(int i = 1; i <= n; i++){
                        for(int j = 1; j <= m; j++){
                                int x;
                                cin >> x;
                                if(x > a[i][j]){
                                        res = 0;
                                }
                        }
                }
                if(!res){
                        cout << "NO" << "\n";
                        continue;
                }
                cout << "YES" << "\n";
                for(int i = 1; i <= n; i++){
                        for(int j = 1; j <= m; j++){
                                cout << a[i][j] << " ";
                        }
                        cout << "\n";
                }
        }
}