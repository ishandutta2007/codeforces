#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 110;
const long long mod = 998244353;

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
        int res = 1;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cin >> b[i][j];
                        if(a[i][j] > b[i][j]){
                                swap(a[i][j], b[i][j]);
                        }
                        res &= a[i][j] > a[i - 1][j];
                        res &= b[i][j] > b[i - 1][j];
                        res &= a[i][j] > a[i][j - 1];
                        res &= b[i][j] > b[i][j - 1];
                }
        }
        if(res){
                cout << "Possible" << "\n";
        } else{
                cout << "Impossible" << "\n";
        }
}