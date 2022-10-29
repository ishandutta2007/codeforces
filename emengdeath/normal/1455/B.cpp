#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int S = 2e6;
int f[S * 2 + 1];
vector<int> d;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int x;
        scanf("%d", &x);
        int ans = 0;
        for (int i = 1; !ans; i++)
            if (1ll * (i +  3) * i / 2 >= x + i) {
                x +=i;
                for (int j = i + 1; j >= 2;j --)
                    if (x >= j && x - j != 1) x -= j;
                if (!x)ans = i;
                else ans = i + 1;
            }
        printf("%d\n", ans);
    }
    return 0;
}