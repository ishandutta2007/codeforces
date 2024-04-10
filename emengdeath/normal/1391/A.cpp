#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n;i ++)
            printf("%d%c", i, " \n"[ i == n]);
    }
    return 0;
}