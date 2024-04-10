// Codeforces Beta Round #59
// Problem D -- Dividing Island
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 111;

int a, b, c, d, n, x[N];
char res[N][N];

int main () {
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", x + i);
    }
    printf("YES\n");
    for (int i = 0; i < max(b, d); ++ i) { 
        for (int j = 0; j < a + c; ++ j) {
            res[i][j] = '.';
        }
    }
    int k = 0;
    for (int j = 0; j < a + c; ++ j) {        
        int h = j < a? b: d;        
        if ((j & 1) ^ (a & 1)) {
            for (int i = h - 1; i > -1; -- i) {
                while (x[k] == 0) {
                    k += 1;
                }
                res[i][j] = 'a' + k;
                x[k] -= 1;
            }
        } else {
            for (int i = 0; i < h; ++ i) {
                while (x[k] == 0) {
                    k += 1;
                }
                res[i][j] = 'a' + k;
                x[k] -= 1;
            }
        }
    }
    for (int i = 0; i < max(b, d); ++ i) {
        for (int j = 0; j < a + c; ++ j) {
            printf("%c", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}