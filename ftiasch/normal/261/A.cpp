#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 100000;

int n, m, q[N], a[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", q + i);
    }
    int min_q = *std::min_element(q, q + n);
    scanf("%d", &m);
    for (int i = 0; i < m; ++ i) {
        scanf("%d", a + i);
    }
    std::sort(a, a + m);
    int answer = 0;
    for (int i = m - 1; i >= 0;) {
        int left = min_q;
        while ((left --) && i >= 0) {
            answer += a[i --];
        }
        left = 2;
        while ((left --) && i >= 0) {
            i --;
        }
    }
    printf("%d\n", answer);
    return 0;
}