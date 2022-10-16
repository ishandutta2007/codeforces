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

const int MAXN = 16;

int answer = 0;
int v[1 + MAXN];

bool Check(int a, int b) {
    for (int i = a + 1; i <= b; i++)
        if (v[i] < v[i - 1])
            return false;
    return true;
}

void Backtracking(int a, int b) {
    if (Check(a, b)) {
        answer = max(answer, (b - a + 1));
        return;
    }
    int m = (a + b) / 2;
    Backtracking(a, m);
    Backtracking(m + 1, b);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    Backtracking(1, n);
    printf("%d\n", answer);
    return 0;
}