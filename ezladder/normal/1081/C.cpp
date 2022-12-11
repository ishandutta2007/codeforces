#include <bits/stdc++.h>
                  
using namespace std;
          
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

const int mod = 998244353;

int n, m, k;
int dp[2007][2007];

void add(int &a, int b){
    a += b;
    if (a >= mod) a -= mod;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    dp[0][0] = m;
    for (int i = 0; i < n; i++) for (int j = 0; j <= k; j++){
        add(dp[i + 1][j], dp[i][j]);
        add(dp[i + 1][j + 1], dp[i][j] * (ll)(m - 1) % mod);
    }
    cout << dp[n - 1][k];
}