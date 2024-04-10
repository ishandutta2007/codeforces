#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        long long n;
        scanf("%lld", &n);
        if (n & 1) {
            puts("-1");
            continue;
        }
        long long v = 1;
        for (int i = 1; i <= 59; i++) v *= 2;
        vector<int> a;
        n -= 2;
        a.push_back(1);
        for (int i = 58; i >= 1; v /= 2, i --)
            while (n >= (v - 2)) {
                n -= (v - 2);
                for (int j = 1; j < i;j  ++)
                    a.push_back(0);
                a.push_back(1);
            }
        if (n || a.size() > 2000) {
            puts("-1");
            continue;
        }
        printf("%d\n", (int)a.size());
        for (auto u:a)
            printf("%d ", u);
        puts("");
    }
    return 0;
}