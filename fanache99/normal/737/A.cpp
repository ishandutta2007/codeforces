#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int SIZE = 1 << 17;
const int MAXN = 200000;
const int INF = 2000000000;

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

int g[1 + MAXN + 1], sum[1 + MAXN + 1];
int v[1 + MAXN], c[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read(), k = Read(), s = Read(), t = Read();
    for (int i = 1; i <= n; i++) {
        c[i] = Read();
        v[i] = Read();
    }
    for (int i = 1; i <= k; i++)
        g[i] = Read();
    sort(g + 1, g + k + 1);
    g[k + 1] = s - g[k];
    for (int i = k; i >= 1; i--)
        g[i] = g[i] - g[i - 1];
    k++;
    sort(g + 1, g + k + 1);
    for (int i = 1; i <= k; i++)
        sum[i] = sum[i - 1] + g[i];
    int answer = INF;
    for (int i = 1; i <= n; i++)
        if (v[i] >= g[k]) {
            int left = 1, right = k, where = 0;
            while (left <= right) {
                int middle = (left + right) / 2;
                if (g[middle] * 2 <= v[i]) {
                    where = middle;
                    left = middle + 1;
                }
                else
                    right = middle - 1;
            }
            int period = 2 * s - sum[where] - (1LL * v[i] * (k - where) - (sum[k] - sum[where]));
            if (period <= t)
                answer = min(answer, c[i]);
        }
    if (answer == INF)
        answer = -1;
    printf("%d\n", answer);
    return  0;
}