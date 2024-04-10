#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 100000;

int v[1 + MAXN + 1];
int answer[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    for (int i = n; i >= 1; i--)
        answer[i] = v[i] + v[i + 1];
    for (int i = 1; i <= n; i++)
        printf("%d ", answer[i]);
    return 0;
}