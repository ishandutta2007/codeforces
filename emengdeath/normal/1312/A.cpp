#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n, m;
        scanf("%d %d",&n, &m);
        if (n % m == 0)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}