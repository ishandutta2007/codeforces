#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

const int SIZE = 1 << 17;

char buffer[SIZE];
int pointer = SIZE;

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

int dp[200][200];
string s[200];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    int l = s[1].size();
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < l; j++)
            dp[i][j] = 1000000000;
    for (int i = 1; i <= n; i++)
        s[i] = s[i] + s[i];
    for (int j = 0; j < l; j++)
        dp[1][j] = j;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < l; j++)
            for (int k = 0; k < l; k++)
                if (s[i].substr(j, l) == s[i - 1].substr(k, l))
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + j);
    int answer = 1000000000;
    for (int i = 0; i < l; i++)
        answer = min(answer, dp[n][i]);
    if (answer == 1000000000)
        cout << "-1\n";
    else
        cout << answer << "\n";
    return  0;
}