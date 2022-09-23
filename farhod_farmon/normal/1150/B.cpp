#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 55;
const long long mod = 998244353;

using namespace std;

int n;
char c[N][N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        cin >> c[i][j];
                        if(c[i][j] == '.'){
                                c[i][j] = 1;
                        } else{
                                c[i][j] = 0;
                        }
                }
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        if(c[i][j] && c[i - 1][j] && c[i + 1][j] && c[i][j - 1] && c[i][j + 1]){
                                c[i][j] = c[i - 1][j] = c[i + 1][j] = c[i][j - 1] = c[i][j + 1] = 0;
                        }
                }
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        if(c[i][j]){
                                cout << "NO" << "\n";
                                return 0;
                        }
                }
        }
        cout << "YES" << "\n";
}