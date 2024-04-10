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
    int tests;
    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        int c, m, x;
        scanf("%d%d%d", &c, &m, &x);
        if (c > m)
            swap(c, m);
        if (x >= c)
            printf("%d\n",c);
        else {
            int left = x, right = c, answer = x;
            while (left <= right) {
                int middle = (left + right) / 2;
                if (middle - x <= max(0, c - middle) + max(0, m - middle)) {
                    answer = middle;
                    left = middle + 1;
                }
                else
                    right = middle - 1;
            }
            printf("%d\n", answer);
        }
    }
    return 0;
}