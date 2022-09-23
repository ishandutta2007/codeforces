#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 550;
const long long mod = 998244353;

using namespace std;

int n;
int a[N];
int c[N][N];
int d[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];

        for(int i = n; i >= 1; i--){
                c[i][i] = a[i];
                for(int j = i + 1; j <= n; j++){
                        for(int h = i; h < j; h++){
                                if(c[i][h] && c[i][h] == c[h + 1][j]) c[i][j] = c[i][h] + 1;
                        }
                }
        }

        for(int i = 1; i <= n; i++){
                d[i] = i;
                for(int j = 0; j < i; j++){
                        if(c[j + 1][i]) d[i] = min(d[i], d[j] + 1);
                }
        }
        cout << d[n] << "\n";
}