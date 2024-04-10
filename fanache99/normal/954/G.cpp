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

const int MAXN = 500000;
const long long INF = 2000000000000000000LL;

int v[1 + MAXN];
long long initial[1 + MAXN + 1], sum[1 + MAXN + 1];

bool Check(long long limit, int n, int r, long long k) {
    for (int i = 1; i <= n; i++)
        sum[i] = 0;
    long long need = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] += sum[i - 1];
        long long current = sum[i] + initial[i];
        if (current < limit) {
            need += limit - current;
            if (need > k)
                return false;
            sum[i] += limit - current;
            sum[min(n + 1, i + 2 * r + 1)] -= limit - current;
        }
    }
    return true;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, r;
    long long k;
    scanf("%d%d%I64d", &n, &r, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        initial[max(1, i - r)] += v[i];
        initial[min(n + 1, i + r + 1)] -= v[i];
    }
    long long left = INF, right = INF;
    for (int i = 1; i <= n; i++) {
        initial[i] += initial[i - 1];
        left = min(left, initial[i]);
    }
    long long answer = left;
    while (left <= right) {
        long long middle = (left + right) / 2;
        if (Check(middle, n, r, k)) {
            answer = middle;
            left = middle + 1;
        }
        else
            right = middle - 1;
    }
    printf("%I64d\n", answer);
    return 0;
}