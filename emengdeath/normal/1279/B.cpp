#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e6 ;
int a[N];
int n;
int s;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &s);
        for (int i = 1; i <= n; i ++)
            scanf("%d", &a[i]);
        long long all = 0;
        int r = 0;
        while (r + 1 <= n && all <= s) all += a[++r];
        if (all <= s) {
            printf("0\n");
            continue;
        }
        int mx = 1;
        for (int i = 1; i <= r; i ++)
            if (a[i] > a[mx]) mx = i;
        printf("%d\n", mx);
    }
    return 0;
}