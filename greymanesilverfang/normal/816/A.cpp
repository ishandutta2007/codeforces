#include <stdio.h>
using namespace std;
const int H[17] = {0, 1, 2, 3, 4, 5, 10, 11, 12, 13, 14, 15, 20, 21, 22, 23, 24},
          M[17] = {0, 10, 20, 30, 40, 50, 1, 11, 21, 31, 41, 51, 2, 12, 22, 32, 0};

int main() {
    int h, m; scanf("%d:%d", &h, &m);
    int i = 0; while ((H[i] < h || H[i] == h && M[i] < m)) i++;
    printf("%d", (H[i] - h) * 60 + M[i] - m);
    return 0;
}