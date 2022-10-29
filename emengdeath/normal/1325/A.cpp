#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int t;
    int a;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &a);
        if (a & 1) {
            a--;
            printf("%d %d\n", 1, a);
        } else {
            printf("%d %d\n", a/ 2, a/ 2);
        }
    }
}