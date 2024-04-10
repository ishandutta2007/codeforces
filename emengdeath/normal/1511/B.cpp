#include <algorithm>
#include <cstdio>
using namespace std;
int bits(int x) {
    int cnt = 0;
    while (x) ++cnt, x /= 10;
    return cnt;
}
int a[10], b[10];
int main() {
    int T;
    scanf("%d", &T);

    for (int i = 2; bits(i) <= 9; i *= 2)
        a[bits(i)] = i;
    for (int i = 3; bits(i) <= 9; i *= 3)
        b[bits(i)] = i;    
    while (T --) {
        int A, B, c;
        scanf("%d %d %d", &A, &B, &c);
        int v = 1;
        for (int i = 2; i <= c; i ++) v *= 10;
        printf("%d %d\n", v * a[A - c + 1], v * b[B - c + 1]);
    }
}