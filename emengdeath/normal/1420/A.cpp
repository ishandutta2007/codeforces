#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e5;
int a[N];
int n, T;
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        bool sig = 1;
        for (int i = 1; i<= n;i ++) {
            scanf("%d", &a[i]);
            if (i != 1) {
                sig &= (a[i] < a[i - 1]);
            }
        }
        !sig?puts("YES"):puts("NO");
    }
    return 0;
}