#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
    int x;
    scanf("%d", &x);
    return x;
}

const int N = 555;
int dp[N][N];

int main(){

    int n = nxt();
    vector<itn> a(n);
    for (int i = 0; i < n; i++)
        a[i] = nxt();
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    for (int k = 1; k < n; k++){
        for (int i = 0; i + k < n; i++){
            int j = i + k;
            dp[i][j] = INT_MAX;
            for (int ij = i; ij < j; ij++)
                dp[i][j] = min(dp[i][j], dp[i][ij] + dp[ij + 1][j]);
            int ij = 0;
            while (i + ij < n && j - ij >= 0 && a[i + ij] == a[j - ij] && i + ij <= j - ij){
                ij++;
                if (i + ij < n && j - ij >= 0)
                dp[i][j] = min(dp[i][j], dp[i + ij][j - ij]);
            }
            if (i + ij > j - ij)
                dp[i][j] = 1;
        }
    }

    cout << dp[0][n - 1] << "\n";

    return 0;
}