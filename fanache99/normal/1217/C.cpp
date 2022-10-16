#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;

char s[1 + MAXN];
int one[1 + MAXN];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int tests;
    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        scanf("%s", s + 1);
        int n = strlen(s + 1), answer = 0, ones = 0;
        int limit = 0;
        while (1 << (limit + 1) <= n)
            limit++;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '1') {
                ones++;
                one[ones] = i;
            }
            int x = 0;
            for (int j = ones; j >= 1 && i - one[j] <= limit; j--) {
                x = x + (1 << (i - one[j]));
                int a = i - one[j] + 1, b = i - (one[j - 1] + 1) + 1;
                if (a <= x && x <= b)
                    answer++;
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}