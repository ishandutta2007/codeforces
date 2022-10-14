#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100;

int n, a[N + 1];

int main() {
    scanf("%d", &n);
    if (n <= 2) {
        puts("-1");
    } else {
        int answer = 0;
        for (int i = 1; i <= n; ++ i) {
            scanf("%d", a + i);
        }
        for (int i = n; i >= 3; -- i) {
            if (i % 2 == 1) {
                while (a[i] > 0 || a[i - 1] > 0) {
                    answer ++;
                    a[i] --;
                    a[i - 1] --;
                    a[i >> 1] --;
                }
            }
        }
        while (a[1] > 0) {
            answer ++;
            a[1] --;
        }
        for (int i = 1; i <= n; ++ i) {
            if (a[i] > 0) {
                puts("-1");
                return 0;
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}