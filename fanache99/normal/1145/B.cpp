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

int good[43] = {0, 2, 3, 4, 5, 6, 8, 12, 30, 32, 33, 34, 35, 36, 38, 40, 42, 43, 44, 45, 46, 48, 50, 52, 53, 54, 55, 56, 58, 60, 62, 63, 64, 65, 66, 68, 80, 82, 83, 84, 85, 86, 88};

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 43; i++)
        if (n == good[i]) {
            printf("YES\n");
            return 0;
        }
    printf("NO\n");
    return 0;
}