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

int v[1 + 2 * MAXN];
pair<int, int> preffix[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, q, biggest = 0;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        if (v[i] >= biggest)
            biggest = v[i];
    }
    int a = 1, b = n, p = 0;
    while (v[a] != biggest) {
        p++;
        preffix[p] = make_pair(v[a], v[a + 1]);
        int x = max(v[a], v[a + 1]), y = min(v[a], v[a + 1]);
        a++;
        v[a] = x;
        b++;
        v[b] = y;
    }
    for (int i = 1; i <= q; i++) {
        long long x;
        scanf("%I64d", &x);
        if (x <= p)
            printf("%d %d\n", preffix[x].first, preffix[x].second);
        else {
            x -= p;
            x %= (n - 1);
            if (x == 0)
                x = n - 1;
            printf("%d %d\n", v[a], v[a + x]);
        }
    }
    return 0;
}