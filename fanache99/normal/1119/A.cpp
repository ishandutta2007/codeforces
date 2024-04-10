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

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, answer = 0, a = 0, pa, b = 0, pb;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (!a) {
            a = x;
            pa = i;
        }
        else {
            if (!b && x == a)
                continue;
            if (!b && x != a) {
                b = x;
                pb = i;
            }
            if (x != a)
                answer = max(answer, i - pa);
            else
                answer = max(answer, i - pb);
        }
    }
    printf("%d\n", answer);
    return 0;
}