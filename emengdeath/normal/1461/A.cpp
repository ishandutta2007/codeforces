#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n , k;
        scanf("%d %d", &n, &k);
        while (n --) {
            printf("%c", 'a' + n % 3);
        }
        puts("");
    }
    return 0;
}