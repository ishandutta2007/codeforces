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

int phi[1 + MAXN];

int Gcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        phi[i] = i - 1;
    long long limit = 0;
    for (int i = 1; i <= n; i++) {
        limit += phi[i];
        for (int j = 2 * i; j <= n; j += i)
            phi[j] -= phi[i];
    }
    if (m < n - 1 || m > limit) {
        printf("Impossible\n");
        return 0;
    }
    printf("Possible\n");
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (Gcd(i, j) == 1) {
                printf("%d %d\n", i, j);
                m--;
                if (m == 0)
                    return 0;
            }
    return 0;
}