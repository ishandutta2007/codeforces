#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1 << 17;
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
const long long INF = 1000000000000000000LL;

long long v[1 + MAXN];
long long delta[1 + MAXN - 1];
long long sum[1 + MAXN - 1];

void Precompute(int n) {
    sort(v + 1, v + n + 1);
    for (int i = 1; i < n; i++)
        delta[i] = v[i + 1] - v[i] + 1;
    sort(delta + 1, delta + (n - 1) + 1);
    delta[0] = 1;
    for (int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + 1LL * (n - i + 1) * (delta[i] - delta[i - 1]);
}

long long Query(int n, long long x) {
    if (x >= delta[n - 1])
        return sum[n - 1] + (x - delta[n - 1] + 1);
    if (x < delta[1])
        return 1LL * n * x;
    int left = 1, right = n - 1, best;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (x >= delta[middle]) {
            best = middle;
            left = middle + 1;
        }
        else
            right = middle - 1;
    }
    return sum[best] + 1LL * (x - delta[best] + 1) * (n - best);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%I64d", &v[i]);
    Precompute(n);

    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        long long a, b;
        scanf("%I64d%I64d", &a, &b);
        printf("%I64d ", Query(n, b - a + 1));
    }
    return 0;
}