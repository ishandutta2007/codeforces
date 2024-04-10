#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e6;
int n;
int a[N];
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        int sum = 0;
        bool last = 0;
        for (int i = 1; i <= n; i ++) {
            int x;
            scanf("%d", &x);
            if (x != i)
            {
                if (!last) sum ++;
                last = 1;
            } else last = 0;
        }
        sum = min(sum, 2);
        printf("%d\n", sum);
    }
    return 0;
}