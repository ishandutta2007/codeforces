#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, top[2];
char s[maxn];
vector<int> V[2][maxn];

int main() {
    scanf("%s", s + 1), n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            if (top[1]) {
                V[1][top[1]].push_back(i);
                swap(V[0][++top[0]], V[1][top[1]--]);
            } else {
                V[0][++top[0]].push_back(i);
            }
        } else {
            if (!top[0]) {
                printf("-1\n"), exit(0);
            } else {
                V[0][top[0]].push_back(i);
                swap(V[1][++top[1]], V[0][top[0]--]);
            }
        }
    }
    if (top[1]) {
        printf("-1\n"), exit(0);
    }
    printf("%d\n", top[0]);
    for (int i = 1; i <= top[0]; i++) {
        auto v = V[0][i];
        printf("%d ", v.size());
        for (int x : v) printf("%d ", x);
        printf("\n");
    }
    return 0;
}