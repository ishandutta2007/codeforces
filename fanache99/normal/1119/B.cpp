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

const int MAXN = 1000;

int a[1 + MAXN], v[1 + MAXN];

bool Ok(int n, int h) {
    for (int i = 1; i <= n; i++)
        v[i] = a[i];
    sort(v + 1, v + n + 1);
    int sum = 0;
    for (int i = n; i >= 1; i -= 2) {
        sum += v[i];
        if (sum > h)
            return false;
    }
    return true;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, h;
    scanf("%d%d", &n, &h);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = n; i >= 1; i--)
        if (Ok(i, h)) {
            printf("%d\n", i);
            return 0;
        }
    return 0;
}