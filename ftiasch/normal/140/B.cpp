#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 333;

int n, card[N][N], rank[N][N], prefer[N][2], get[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n + 1; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            scanf("%d", &card[i][j]);
            rank[i][card[i][j]] = j;
        }
        card[i][n + 1] = n + 1;
        rank[i][n + 1] = n + 1;
    }
    for (int j = 1; j <= n; ++ j) {
        prefer[0][0] = card[n + 1][n + 1];
        prefer[0][1] = card[n + 1][n + 1];
        for (int i = 1; i <= n; ++ i) {
            prefer[i][0] = prefer[i - 1][0];
            prefer[i][1] = prefer[i - 1][1];
            if (rank[n + 1][i] < rank[n + 1][prefer[i][0]]) {
                prefer[i][1] = prefer[i][0];
                prefer[i][0] = i;
            } else if (rank[n + 1][i] < rank[n + 1][prefer[i][1]]) {
                prefer[i][1] = i;
            }
        }
        for (int i = 1; i <= n; ++ i) {
//printf("(%d, %d)", prefer[i][0], prefer[i][1]);
            if (prefer[i][0] == j) {
                get[i] = prefer[i][1];
            } else {
                get[i] = prefer[i][0];
            }
//printf("%d, ", get[i]);
        }        
//printf("\n");
        int orz = n + 1;
        for (int i = 1; i <= n; ++ i) {
            if (rank[j][orz] > rank[j][get[i]]) {
                orz = get[i];
            }
        }
        for (int i = 1; i <= n; ++ i) {
            if (get[i] == orz) {
                printf("%d%c", i, j == n? '\n': ' ');
                break;
            }
        }
    }
    return 0;
}