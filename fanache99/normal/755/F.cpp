#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <bitset>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int SIZE = 1 << 17;
const int MAXN = 1000000;

char buffer[SIZE];
int pos = SIZE;

char Advance() {
    if (pos == SIZE) {
        fread(buffer, 1, SIZE, stdin);
        pos = 0;
    }
    return buffer[pos++];
}

int Read() {
    int x = 0;
    char ch = Advance();
    while (ch < '0' || ch > '9')
        ch = Advance();
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = Advance();
    }
    return x;
}

int p[1 + MAXN], cycles[1 + MAXN];
bool seen[1 + MAXN];
bitset<1 + MAXN> dp;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read(), k = Read(), big = 0, remain;
    for (int i = 1; i <= n; i++)
        p[i] = Read();
    remain = k;
    for (int i = 1; i <= n; i++)
        if (!seen[i]) {
            int j = i, length = 0;
            while (!seen[j]) {
                length++;
                seen[j] = true;
                j = p[j];
            }
            cycles[length]++;
            int pairs = length / 2;
            if (remain >= pairs) {
                big += 2 * pairs;
                remain -= pairs;
            }
            else {
                big += 2 * remain;
                remain = 0;
            }
        }
    for (int i = 3; i <= n; i += 2)
        if (remain > cycles[i]) {
            remain -= cycles[i];
            big += cycles[i];
        }
        else {
            big += remain;
            break;
        }
    dp[0] = true;
    for (int i = 1; i <= n; i++)
        if (cycles[i]) {
            cycles[2 * i] += (cycles[i] - 1) / 2;
            cycles[i] %= 2;
            if (!cycles[i])
                cycles[i] = 2;
            for (int j = 1; j <= cycles[i]; j++)
                dp = dp | (dp << i);
        }
    int small = k;
    if (!dp[k])
        small++;
    printf("%d %d\n", small, big);
    return 0;
}