#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

const int N = 22222;

int n, a[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
    }
    int result = INT_MIN;
    for (int d = 1; d < n; ++ d) {
        if (n % d == 0 && n / d >= 3) {
            for (int i = 0; i < d; ++ i) {
                int total = 0;
                int j = i;
                do {
                    total += a[j];
                    j = (j + d) % n;
                } while (j != i);
                result = max(result, total);
            }
        }
    }
    printf("%d\n", result);
    return 0;
}