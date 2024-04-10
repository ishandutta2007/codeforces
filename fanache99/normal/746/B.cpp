#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2000;

char s[1 + MAXN];
char sol[1 + MAXN];
bool out[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d\n%s", &n, s + 1);
    for (int i = n; i >= 1; i--) {
        int x = i / 2 + i % 2, y = 0;
        for (int j = 1; j <= n; j++) {
            if (!out[j])
                y++;
            if (y == x) {
                out[j] = true;
                sol[j] = s[n - i + 1];
                break;
            }
        }
    }
    printf("%s\n", sol + 1);
    return 0;
}