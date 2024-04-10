#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;

using namespace std;

int n;
int a[N][N];
int b[N];

bool good(int x)
{
        b[1] = x;
        for(int i = 2; i <= n; i++){
                b[i] = a[1][i] / b[1];
        }
        for(int i = 2; i <= n; i++){
                for(int j = i + 1; j <= n; j++){
                        if(1ll * b[i] * b[j] != 1ll * a[i][j]){
                                return false;
                        }
                }
        }
        return true;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        cin >> a[i][j];
                }
        }
        int G = a[1][2];
        for(int i = 3; i <= n; i++){
                G = __gcd(G, a[1][i]);
        }
        int res = 0;
        for(int i = 1; i * i <= G; i++){
                if(G % i == 0){
                        if(good(i)){
                                res = i;
                                break;
                        } else if(good(G / i)){
                                res = G / i;
                                break;
                        }
                }
        }
        cout << res << " ";
        for(int i = 2; i <= n; i++){
                cout << a[1][i] / res << " ";
        }
}