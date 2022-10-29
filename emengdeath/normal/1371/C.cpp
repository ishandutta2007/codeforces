#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
    int T;
    scanf("%d", &T);
    while (T --) {
        long long a, b, n, m;
        scanf("%lld %lld %lld %lld", &a, &b, &n, &m);
        if (n + m > a + b) {
            puts("No");
            continue;
        }
        if (a > b) swap(a, b);
        if (a >= m) puts("Yes");
        else
            puts("No");
    }
    return 0;
}