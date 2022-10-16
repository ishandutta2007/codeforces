#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 200000;
int v[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        if (v[i] > 2)
            if (v[i] % 2 == 1)
                v[i] = 1;
            else
                v[i] = 2;
        sum += v[i];
    }
    if (sum % 2 == 1) {
        printf("NO\n");
        return 0;
    }
    for (int i = 1; i <= n; i++)
        if (v[i] == 1) {
            if (i == n || v[i + 1] == 0) {
                printf("NO\n");
                return 0;
            }
            v[i] = 0;
            v[i + 1]--;
        }
    printf("YES\n");
    return 0;
}