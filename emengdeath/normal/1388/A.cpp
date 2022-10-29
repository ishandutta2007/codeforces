#include <algorithm>
#include <cstdio>
using namespace std;
int n;
const int S = 5;
int d[S] = {6 , 10, 14, 15, 21};
bool work(int a, int b, int c) {
    int x = n - a-  b - c;
    if (x <= 0 || x == a || x == b || x == c) return 0;
    puts("YES");
    printf("%d %d %d %d\n", a, b,c, x);
    return 1;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d",&n);
        bool sig = 1;
        for (int i = 0; i < S && sig; i ++)
            for (int j = i + 1; j < S && sig;j ++)
                for (int k= j + 1; k < S && sig; k ++)
                    sig &= !work(d[i], d[j], d[k]);
        if (sig)puts("NO");
    }
    return 0;
}