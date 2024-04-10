#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int x, y, answer = 0;
    scanf("%d%d", &x, &y);
    int a = y, b = y, c = y;
    while (a != x || b != x || c != x) {
        a = min(x, b + c - 1);
        int a0, b0, c0;
        c0 = max(a, max(b, c));
        a0 = min(a, min(b, c));
        b0 = a + b + c - a0 - c0;
        a = a0;
        b = b0;
        c = c0;
        answer++;
    }
    printf("%d\n", answer);
    return 0;
}