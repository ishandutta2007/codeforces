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
    int n, m;
    scanf("%d%d", &n, &m);
    int l1 = 1, l2 = n;
    while (l1 <= l2) {
        if (l1 < l2)
            for (int i = 1; i <= m; i++)
                printf("%d %d\n%d %d\n", l1, i, l2, m - i + 1);
        else {
            int a = 1, b = m;
            while (a <= b) {
                if (a < b)
                    printf("%d %d\n%d %d\n", l1, a, l1, b);
                else
                    printf("%d %d\n", l1, a);
                a++;
                b--;
            }
        }
        l1++;
        l2--;
    }
    return 0;
}