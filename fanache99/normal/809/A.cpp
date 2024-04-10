#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <queue>

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

const int MAXN = 300000;
const int MOD = 1000000007;

int v[1 + MAXN];

void Add(int &x, int y) {
    x += y;
    if (x >= MOD)
        x -= MOD;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read();
    for (int i = 1; i <= n; i++)
        v[i] = Read();
    sort(v + 1, v + n + 1);
    int sum = 0, power2 = 1, powerSum = 0, answer = 0;
    for (int i = 2; i <= n; i++) {
        Add(sum, sum);
        Add(powerSum, power2);
        Add(sum, (1LL * (v[i] - v[i - 1]) * powerSum) % MOD);
        Add(power2, power2);
        Add(answer, sum);
    }
    printf("%d\n", answer);
    return 0;
}