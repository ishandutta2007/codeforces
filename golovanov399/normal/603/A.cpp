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

const int N = 111111;
int dp[N][3][2];

int main(){

    int n = nxt();
    string s;
    cin >> s;
    for (int i = 0; i < n; i++){
        for (int x = 0; x < 3; x++){
            for (int y = 0; y < 2; y++){
                dp[i + 1][x][y] = dp[i][x][y];
            }
        }
        int c = s[i] - '0';
        for (int x = 0; x < 3; x++){
            for (int y = 0; y < 2; y++){
                if (y != c){
                    dp[i + 1][x][c] = max(dp[i + 1][x][c], dp[i][x][y] + 1);
                } else {
                    if (x < 2){
                        dp[i + 1][x + 1][c] = max(dp[i + 1][x + 1][c], dp[i][x][y] + 1);
                    }
                }
            }
        }
    }

    int mx = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            mx = max(mx, dp[n][i][j]);
        }
    }
    printf("%d\n", mx);

    return 0;
}