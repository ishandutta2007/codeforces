#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <set>
#include <complex>

using namespace std;

const int SIZE = 1 << 10;

int pointer = SIZE;
char buffer[SIZE];

char Advance() {
    if (pointer == SIZE) {
        fread(buffer, 1, SIZE, stdin);
        pointer = 0;
    }
    return buffer[pointer++];
}

int Read() {
    int answer = 0;
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer;
}

const int MAXN = 1000;

char s[1 + MAXN];
string dp[1 + MAXN][2];
int dad[1 + MAXN][2];
int answer[1 + MAXN];

string Reverse(string a) {
    reverse(a.begin(), a.end());
    return a;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    dp[1][0] = dp[1][1] = s[1];
    for (int i = 2; i <= n; i++) {
        if (dp[i - 1][0] + s[i] <= s[i] + Reverse(dp[i - 1][1])) {
            dp[i][0] = dp[i - 1][0] + s[i];
            dad[i][0] = 0;
        }
        else {
            dp[i][0] = s[i] + Reverse(dp[i - 1][1]);
            dad[i][0] = 1;
        }
        if (Reverse(dp[i - 1][1] + s[i]) <= Reverse(s[i] + Reverse(dp[i - 1][0]))) {
            dp[i][1] = dp[i - 1][1] + s[i];
            dad[i][1] = 0;
        }
        else {
            dp[i][1] = s[i] + Reverse(dp[i - 1][0]);
            dad[i][1] = 1;
        }
    }
    for (int i = n, j = 0; i >= 1; i--) {
        answer[i] = dad[i][j];
        if (dad[i][j] == 1)
            j = 1 - j;
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", answer[i]);
    return 0;
}