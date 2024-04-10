#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n, k;
        int a[100];
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n ; i ++) {
            scanf("%d", &a[i]);
        }   
        int l = 0;     
        while (k --) {
            while (!a[l] && l + 1 < n - 1) l ++;
            if (!a[l]) break;
            a[l] --;
            a[n - 1] ++;
        }
        for (int i = 0; i < n; i ++)
            printf("%d%c", a[i], " \n"[i == n - 1]);
    }
    return 0;
}