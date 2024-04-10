#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n, x;
        scanf("%d %d", &n, &x);
        int sum = 0;
        int all = 0;
        for (int i = 1; i <= n;i ++)
        {
            int y;
            scanf("%d", &y);
            if (y == x) sum ++;
            else
                all += y;
        }
        if (n == sum) puts("0");
        else {
            if (all == (n - sum) * x) puts("1");
            else {
                if (sum >= 1) puts("1");
                else
                    puts("2");
            }
        }
    }
    return 0;
}