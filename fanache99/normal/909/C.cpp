//#inlude <iostream>
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
#include <cstring>

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

const int MAXN = 5000;
const int MOD = 1000000007;

int dp[2][1 + MAXN];

void Add(int &x, int y) {
    x += y;
    if (x >= MOD)
        x -= MOD;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, now = 0, before = 1;
    dp[now][1] = 1;
    scanf("%d\n", &n);
    char last = 's';
    for (int i = 1; i <= n; i++) {
        char ch;
        scanf("%c\n", &ch);
        swap(now, before);
        if (last == 'f')
            for (int j = 1; j <= n; j++)
                dp[now][j] = dp[before][j - 1];
        else {
            int sum = 0;
            for (int j = n; j >= 1; j--) {
                Add(sum, dp[before][j]);
                dp[now][j] = sum;
            }
        }
        last = ch;
    }
    int answer = 0;
    for (int j = 1; j <= n; j++)
        Add(answer, dp[now][j]);
    printf("%d\n", answer);
    return 0;
}