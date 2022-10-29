#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int x, y;
        scanf("%d %d", &x ,&y);
        if (x * 2 <= y) {
            printf("%d %d\n", x , x * 2);
        } else {puts("-1 -1");}
    }
    return 0;
}