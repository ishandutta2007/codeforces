#include <algorithm>
#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;
const int N = 101;
bitset<101> f;
int T;
int n, m;
int a[N];
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &m);
        int sum = 0;
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
            if (i > 1 && a[i] != a[i - 1])
                sum ++;
        }
        if (m == 1) {
            if (sum)
                puts("-1");
            else
                puts("1");
        }
        else {
            printf("%d\n", max(1,(sum + m - 2) / (m - 1)));
        }
    }
    return 0;
}