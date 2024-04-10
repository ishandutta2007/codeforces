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

const int MAXN = 400000;

int v[1 + MAXN + 1];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, bits;
    scanf("%d%d", &n, &bits);
    bits = (bits * 8) / n;
    int limit = 1;
    for (int i = 1; i <= bits && limit <= n; i++)
        limit *= 2;
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    sort(v + 1, v + n + 1);
    int answer = n;
    for (int i = 1, j = 1, distinct = 1; i <= n; i++) {
        while (j < n && (v[j + 1] == v[j] || distinct < limit)) {
            if (v[j + 1] != v[j])
                distinct++;
            j++;
        }
        answer = min(answer, n - (j - i + 1));
        if (v[i] != v[i + 1])
            distinct--;
    }
    printf("%d\n", answer);
    return 0;
}