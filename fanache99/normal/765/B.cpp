#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;

const int MAXS = 500;

char s[1 + MAXS];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int x = 0;
    for (int i = 1; i <= n; i++)
        if (s[i] - 'a' > x) {
            printf("NO\n");
            return 0;
        }
        else
            if (s[i] - 'a' == x)
                x++;
    printf("YES\n");
    return 0;
}