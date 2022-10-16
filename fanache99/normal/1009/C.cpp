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

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m;
    long long sum = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, d;
        scanf("%d%d", &x, &d);
        sum += n * x;
        if (d >= 0)
            sum += 1LL * d * n * (n - 1) / 2;
        else
            if (n % 2)
                sum += 1LL * d * (n / 2) * ((n / 2) + 1);
            else
                sum += 1LL * d * (n / 2) * ((n / 2) - 1) + 1LL * d * (n / 2);
    }
    printf("%.15f\n", 1.0 * sum / n);
    return 0;
}