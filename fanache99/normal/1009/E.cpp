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

const int MAXN = 1000000;
const int MOD = 998244353;

int a[1 + MAXN];
int power2[1 + MAXN];

void Add(int &x, int y) {
    x += y;
    if (x >= MOD)
        x -= MOD;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    power2[0] = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        power2[i] = power2[i - 1];
        Add(power2[i], power2[i]);
    }
    int sum = 0, answer = 0;
    for (int i = 1; i <= n; i++) {
        Add(answer, (1LL * a[i] * power2[n - i]) % MOD);
        Add(answer, sum);
        if (i != n)
            Add(sum, (1LL * a[i] * power2[n - i - 1]) % MOD);
    }
    printf("%d\n", answer);
    return 0;
}