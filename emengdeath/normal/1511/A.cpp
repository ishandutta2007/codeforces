#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int ans = 0;
        int n;
        int sig = 1;
        scanf("%d", &n);
        while (n --) {
            int x;
            scanf("%d", &x);
            sig |= (x == 1);
            ans += (x == 1 || (x == 3 && sig));
        }
        printf("%d\n", ans);
    }
    return 0;
}