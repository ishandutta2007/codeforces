#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int tests;
    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        int s, i, e, answer;
        scanf("%d%d%d", &s, &i, &e);
        if (i + e - s < 0)
            answer = e + 1;
        else {
            int limit = (i + e - s) / 2 + 1;
            if (limit > e)
                answer = 0;
            else
                answer = e - limit + 1;
        }
        printf("%d\n", answer);
    }
    return 0;
}