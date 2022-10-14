#include <cstdio>
#include <cstring>
using namespace std;

const int N = 5000 + 1;

char text[N];
int sum[N][N];

int main() {
    scanf("%s", text);
    int n = strlen(text);
    for (int middle = 0; middle <= (n - 1) << 1; ++ middle) {
        int left = middle >> 1;
        int right = middle - left;
        while (left >= 0 && right < n) {
            if (text[left] != text[right]) {
                break;
            }
            sum[left][right] ++;
            left --;
            right ++;
        }
    }
    for (int i = n - 1; i >= 0; -- i) {
        for (int j = i; j < n; ++ j) {
            long long result = sum[i][j];
            if (j - i + 1 > 1) {
                result += sum[i + 1][j];
                result += sum[i][j - 1];
            }
            if (j - i + 1 > 2) {
                result -= sum[i + 1][j - 1];
            }
            sum[i][j] = result;
        }
    }
    int q;
    scanf("%d", &q);
    while (q --) {
        int l, r;
        scanf("%d%d", &l, &r);
        l --;
        r --;
        printf("%d\n", sum[l][r]);
    }
    return 0;
}