#include<bits/stdc++.h>

using namespace std;

const int maxN = 1000009;
int N;
char s[maxN];

int dp[20][20];
void buildByDp(string &s, int i, int j) {
    if (i > j)
        return ;
    if (i == j) {
        printf("%c", s[i - 1]);
        return ;
    }
    if (dp[i][j] == dp[i + 1][j - 1] + 2 && s[i - 1] == s[j - 1]) {
        printf("%c", s[i - 1]);
        buildByDp(s, i + 1, j - 1);
        printf("%c", s[j - 1]);
        return ;
    }
    if (dp[i][j] == dp[i + 1][j]) buildByDp(s, i + 1, j);
    else buildByDp(s, i, j - 1);
}

void solve(string s) {
    int l = s.length();
    for (int i=l; i>=1; i--) {
        dp[i][i] = 1;
        for (int j=i + 1; j<=l; j++) {
            dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            if (s[i - 1] == s[j - 1])
                dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 2);
        }
    }
    if (dp[1][l] < l / 2) {
        printf("IMPOSSIBLE\n");
        exit(0);
    }
    buildByDp(s, 1, l);
}

void solve(int i, int j) {
    if (j <= i + 6) {
        string ss;
        for (int k=i; k<=j; k++)
            ss.push_back(s[k]);
        solve(ss);
        return ;
    }
    for (int k=i; k<=i + 1; k++)
        for (int p=j-1; p<=j; p++)
            if (s[k] == s[p]) {
                printf("%c", s[k]);
                solve(k + 1, p - 1);
                printf("%c", s[p]);
                return ;
            }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%s", s + 1), N = strlen(s + 1);
solve(1, N);
printf("\n");
return 0;
}