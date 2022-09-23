#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 550;
const long long mod = 1000000007;

using namespace std;

int n;
char a[N];
int d[N][N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = n; i >= 1; i--){
                d[i][i] = 1;
                for(int j = i + 1; j <= n; j++){
                        d[i][j] = min(d[i + 1][j], d[i][j - 1]) + 1;
                        if(a[i] == a[i + 1] || a[i] == a[j]){
                                d[i][j] = min(d[i][j], d[i + 1][j]);
                        }
                        if(a[j] == a[j - 1] || a[i] == a[j]){
                                d[i][j] = min(d[i][j], d[i][j - 1]);
                        }
                        for(int h = i; h < j; h++){
                                d[i][j] = min(d[i][j], d[i][h] + d[h + 1][j]);
                        }
                }
        }
        cout << d[1][n] << "\n";
}