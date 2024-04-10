#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

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

const int MAXN = 1000;

char s[1 + MAXN];
bool dp[1 + MAXN][1 + 2 * MAXN];
char dad[1 + MAXN][1 + 2 * MAXN];

void Print(int n, int k) {
    for (int i = n; i >= 1; i--) {
        if (s[i] == '?')
            s[i] = dad[i][k];
        if (s[i] == 'W')
            k--;
        if (s[i] == 'L')
            k++;
    }
    printf("%s\n", s + 1);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", s + 1);
    if (s[n] == 'D') {
        printf("NO\n");
        return 0;
    }
    dp[0][k] = true;
    for (int i = 1; i < n; i++)
        for (int j = -(k - 1); j <= k - 1; j++)
            if (s[i] == 'W')
                dp[i][j + k] |= dp[i - 1][j + k - 1];
            else
                if (s[i] == 'L')
                    dp[i][j + k] |= dp[i - 1][j + k + 1];
                else
                    if (s[i] == 'D')
                        dp[i][j + k] |= dp[i - 1][j + k];
                    else
                        if (dp[i - 1][j + k - 1]) {
                            dp[i][j + k] = true;
                            dad[i][j + k] = 'W';
                        }
                        else
                            if (dp[i - 1][j + k + 1]) {
                                dp[i][j + k] = true;
                                dad[i][j + k] = 'L';
                            }
                            else
                                if (dp[i - 1][j + k]) {
                                    dp[i][j + k] = true;
                                    dad[i][j + k] = 'D';
                                }
    if (s[n] == 'W')
        if (!dp[n - 1][k - 1 + k])
            printf("NO\n");
        else
            Print(n, 2 * k);
    if (s[n] == 'L')
        if (!dp[n - 1][-(k - 1) + k])
            printf("NO\n");
        else
            Print(n, 0);
    if (s[n] == '?')
        if (dp[n - 1][k - 1 + k]) {
            dad[n][k + k] = 'W';
            Print(n, 2 * k);
        }
        else
            if (dp[n - 1][-(k - 1) + k]) {
                dad[n][0] = 'L';
                Print(n, 0);
            }
            else
                printf("NO\n");
    return 0;
}