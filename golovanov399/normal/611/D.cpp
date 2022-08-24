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

const int mod = 1000000007;

const int N = 5555;
char a[N][N];
int dp[N][N];
int S[N][N];

int main(){

    int n = nxt();
    string s;
    cin >> s;
    for (int k = 1; k + k <= n; k++){
        queue<int> ar;
        for (int i = 0; i + k < n; i++){
            while (!ar.empty() && ar.front() + k <= i)
                ar.pop();
            if (s[i] < s[i + k]){
                while (!ar.empty()){
                    int x = ar.front();
                    a[x][x + k] = 1;
                    ar.pop();
                }
                if (i + k + k <= n)
                    a[i][i + k] = 1;
            } else if (s[i] > s[i + k]){
                while (!ar.empty()){
                    ar.pop();
                }
            } else {
                if (i + k + k <= n)
                    ar.push(i);
            }
        }
    }

    // for (int i = 0; i < n; i++){
    //  for (int j = 0; j < n; j++){
    //      cerr << (int)a[i][j] << " ";
    //  }
    //  cerr << "\n";
    // }

    dp[0][0] = 1;
    for (int i = 0; i <= n; i++){
        S[0][i] = 1;
    }
    for (int i = 1; i <= n; i++){
        S[i][0] = 0;
        for (int j = 1; j <= i; j++){
            if (s[i - j] == '0'){
                dp[i][j] = 0;
            } else {
                dp[i][j] = S[i - j][j - 1];
                if (i - j - j >= 0 && a[i - j - j][i - j] && s[i - j - j] != '0')
                    dp[i][j] = (dp[i][j] + dp[i - j][j]) % mod;
            }
            S[i][j] = (S[i][j - 1] + dp[i][j]) % mod;
        }
        for (int j = i + 1; j <= n; j++){
            S[i][j] = S[i][j - 1];
        }
    }

    // for (int i = 0; i <= n; i++){
    //  for (int j = 0; j <= n; j++){
    //      cerr << dp[i][j] << " ";
    //  }
    //  cerr << "\n";
    // }

    printf("%d\n", S[n][n]);

    return 0;
}