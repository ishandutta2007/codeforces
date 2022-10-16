#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 100000;
const int SQRT = 200;
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

int v[1 + MAXN];
int dp[1 + SQRT][1 + MAXN];

void Precompute(int n) {
    for (int i = 1; i <= SQRT; i++)
        for (int j = n; j >= 1; j--)
            if (j + v[j] + i > n)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i][j + v[j] + i] + 1;
}

int Query(int p, int k, int n) {
    int answer = 0;
    while (p <= n) {
        p = p + v[p] + k;
        answer++;
    }
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read();
    for (int i = 1; i <= n; i++)
        v[i] = Read();
    Precompute(n);
    int q = Read();
    for (int i = 1; i <= q; i++) {
        int p = Read(), k = Read();
        if (k > SQRT)
            printf("%d\n", Query(p, k, n));
        else
            printf("%d\n", dp[k][p]);
    }
    return 0;
}