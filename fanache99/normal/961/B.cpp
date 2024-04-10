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

const int MAXN = 100000;

int v[1 + MAXN], sum[1 + MAXN], t[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    int answer = 0, best = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
        sum[i] = sum[i - 1];
        if (t[i])
            answer += v[i];
        else
            sum[i] += v[i];
    }
    for (int i = k; i <= n; i++)
        best = max(best, sum[i] - sum[i - k]);
    printf("%d\n", answer + best);
    return 0;
}