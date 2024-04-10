#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int x = min(a, min(b / 2, c / 4));
    printf("%d\n", 7 * x);
    return 0;
}