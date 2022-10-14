#include <cstdio>
#include <cstring>

const int N = 100000 + 1;

int n, s, t, p[N];

int main() {
    scanf("%d%d%d", &n, &s, &t);
    for (int i = 1; i <= n; ++ i) {
        scanf("%d", p + i);
    }
    int answer = 0;
    int i = s;
    while (i != t) {
        answer ++;
        i = p[i];
        if (i == s) {
            puts("-1");
            return 0;
        }
    }
    printf("%d\n", answer);
    return 0;
}