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

const int MAXN = 100;
const int TARGET = 2048;

int v[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int tests;
    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &v[i]);
        sort(v + 1, v + n + 1);
        while (n > 0 && v[n] > TARGET)
            n--;
        while (v[n] != TARGET) {
            bool found = false;
            for (int i = 1; i < n; i++)
                if (v[i] == v[i + 1]) {
                    swap(v[i + 1], v[n]);
                    n--;
                    v[i] *= 2;
                    found = true;
                    break;
                }
            if (!found) {
                printf("NO\n");
                break;
            }
            sort(v + 1, v + n + 1);
        }
        if (v[n] == TARGET)
            printf("YES\n");
    }
    return 0;
}