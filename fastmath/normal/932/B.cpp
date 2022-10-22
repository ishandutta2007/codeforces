#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <random>
#include <algorithm>
#include <time.h>

using namespace std;

const int MAXN = 1e6 + 7;

inline int f(int n){
    int res = 1;
    while (n){
        if (n % 10) res *= n % 10;
        n /= 10;
    }
    return res;
}

int dp[MAXN];
int pref[10][MAXN];

signed main(){
    ios_base::sync_with_stdio(false);

    for (int i = 1; i <= 9; ++i){
        dp[i] = i;
    }

    for (int i = 10; i < MAXN; ++i){
        dp[i] = dp[f(i)];
    }

    for (int k = 1; k <= 9; ++k){
        for (int i = 1; i < MAXN; ++i){
             pref[k][i] = pref[k][i - 1] + (dp[i] == k);
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i){
        int l, r, k;
        cin >> l >> r >> k;
        cout << pref[k][r] - pref[k][l - 1] << '\n';
    }
    
    return 0;
}