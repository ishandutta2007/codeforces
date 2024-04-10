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

const int MAXN = 300000;

char s[1 + MAXN];
int v[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int tests;
    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        int a, b, n, m = 0;
        scanf("%d%d\n%s", &a, &b, s + 1);
        n = strlen(s + 1);
        int i = 1;
        while (i <= n)
            if (s[i] == 'X')
                i++;
            else {
                int l = 0;
                while (i <= n && s[i] == '.') {
                    i++;
                    l++;
                }
                m++;
                v[m] = l;
            }
        n = m;
        sort(v + 1, v + n + 1);
        bool lost = false;
        for (int i = 1; i <= n; i++)
            if (v[i] >= b && v[i] < a)
                lost = true;
        for (int i = 1; i <= n; i++)
            if (v[i] > a + 4 * b - 2)
                lost = true;
        int found = 0;
        for (int i = 1; i <= n; i++)
            if (v[i] >= 2 * b)
                found++;
        if (found > 1)
            lost = true;
        int have = 0;
        for (int i = 1; i <= n; i++)
            if (v[i] >= a)
                have++;
        if (!found) {
            if (have % 2 == 0)
                lost = true;
        }
        else {
            bool possible = false;
            for (int i = 0; i <= v[n] - a; i++) {
                int j = v[n] - i - a;
                if (i >= b && i < a)
                    continue;
                if (j >= b && j < a)
                    continue;
                if (i >= 2 * b)
                    continue;
                if (j >= 2 * b)
                    continue;
                if (i >= a)
                    have++;
                if (j >= a)
                    have++;
                if (have % 2 == 1) {
                    possible = true;
                    break;
                }
                if (i >= a)
                    have--;
                if (j >= a)
                    have--;
            }
            if (!possible)
                lost = true;
        }
        if (lost)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}