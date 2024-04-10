#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100;

int n, b[N][N], a[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            scanf("%d", &b[i][j]);
            if (i < j) {
                a[i] |= b[i][j];
                a[j] |= b[i][j];
            }
        }
    }
    for (int i = 0; i < n; ++ i) {
        printf("%d ", a[i]);
    }
    puts("");
    return 0;
}