#include <cstdio>

using namespace std;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m;
    scanf("%d %d\n", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char ch;
            scanf("%c ", &ch);
            if (ch == 'C' || ch == 'M' || ch == 'Y') {
                printf("#Color");
                return 0;
            }
        }
    printf("#Black&White");
    return 0;
}