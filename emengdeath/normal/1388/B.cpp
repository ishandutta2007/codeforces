#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
    int T;
    scanf("%d", &T);
    while (T --) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n;i ++) {
            if ((n - i) * 4 < n) {
                int x = min(n - (n - i) * 4, 10);
                printf("%d", 8);
            } else
                printf("9");
        }
        puts("");
    }
    return 0;
}