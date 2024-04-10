#include <algorithm>
#include <cstdio>
using namespace std;
long long all;
int n;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int m;
        scanf("%d %d", &n, &m);
        all = 0;
        for (int i=0; i < n; i ++) {
            int x;
            scanf("%d", &x);
            all += x;
        }
        printf("%d\n",(int)min(all, 1ll * m));
    }
    return 0;
}