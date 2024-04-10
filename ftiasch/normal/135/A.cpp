#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 111111;

int n, a[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
    }
    sort(a, a + n);
    if (a[n - 1] == 1) {
        for (int i = 0; i < n; ++ i) {
            printf("%d%c", i == n - 1? 2: 1,
                    i == n - 1? '\n': ' ');
        }
    } else {
        for (int i = 0; i < n; ++ i) {
            printf("%d%c", i == 0? 1: a[i - 1],
                    i == n - 1? '\n': ' ');
        }
    }
    return 0;
}