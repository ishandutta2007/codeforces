#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n;
        int a[1000];
        scanf("%d", &n);
        for (int i= 0; i < n; i ++)
            scanf("%d", &a[i]);
        sort(a, a+n);
        for (int i = n - 1; i >= 0; i--)
            printf("%d%c", a[i], " \n"[i ==0]);
    }
    return 0;
}