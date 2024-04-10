#include <bits/stdc++.h>


using namespace std;

char s[1010];
string c, s1, s2;
int dp[1010][55][55], f1[55][26], f2[55][26];
const int inf = 0x3f3f3f3f;

void kmp(string &str, int f[55][26]) {
    vector<int> fail(str.size() + 1);
    f[0][str[0]-'a'] = 1;
    for(int i = 1; i <= str.size(); i++) {
        fail[i] = (i > 1) ? f[fail[i-1]][str[i-1]-'a'] : 0;
        for(int c = 0; c < 26; c++)
            f[i][c] = (i < str.size() && str[i] - 'a' == c) ? i + 1 : f[fail[i]][c];
    }
}

int solve(int pos, int p1, int p2) {
    if(pos == c.size()) return (p1 == s1.size()) - (p2 == s2.size());

    int &x = dp[pos][p1][p2];
    if(x != inf) return x;
    x = -inf;

    if(c[pos] != '*') x = solve(pos + 1, f1[p1][c[pos]-'a'], f2[p2][c[pos]-'a']) + (p1 == s1.size()) - (p2 == s2.size());
    else for(int i = 0; i < 26; i++) {
        x = max(x, solve(pos + 1, f1[p1][i], f2[p2][i]) + (p1 == s1.size()) - (p2 == s2.size()));
    }

    return x;
}

int main() {
    scanf("%s", s); c = s;
    scanf("%s", s); s1 = s; kmp(s1, f1);
    scanf("%s", s); s2 = s; kmp(s2, f2);
    memset(dp, 0x3f, sizeof dp);
    printf("%d\n", solve(0, 0, 0));
    return 0;
}