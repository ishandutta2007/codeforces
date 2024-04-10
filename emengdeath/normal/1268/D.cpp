#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 2001;
int ind[N], outd[N], sum[N];
int ing[N][N], outg[N][N];
int n;
bool check_scc(int* in, int* out){
    for (int i = 0; i <= n; i ++)
        sum[i] = 0;
    for (int i= 1; i <= n; i ++)
        sum[out[i]] ++;
    int all = 0;
    int i = 0;
    for (int j = n; j >= 1; j --) {
        all += sum[j] * j;
        i += sum[j];
        if (i == n || !i) continue;
        if (all == i * (i - 1) / 2 + (n - i) * i) return 0;
    }
    return 1;
}
void change(int x) {
    swap(ind[x], outd[x]);
    for (int u = 1; u <= n; u ++)
        if (ing[x][u] == 1) {
            outd[u]--, ind[u]++;
            outg[u][x] = 0;
            ing[u][x] = 2;
            ing[x][u] = 0;
            outg[x][u] = 2;
        }
    for (int u = 1; u <= n; u ++)
        if (outg[x][u] == 1) {
            outd[u]++, ind[u]--;
            outg[x][u] = 0;
            ing[u][x] = 0;
            ing[x][u] = 2;
            outg[u][x] = 2;
         }
    for (int i = 1; i <= n; i ++)
        ing[i][x] = min(ing[i][x], 1), ing[x][i] = min(ing[x][i], 1), outg[i][x] = min(outg[i][x], 1), outg[x][i] = min(outg[x][i], 1);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            char c;
            scanf(" %c", &c);
            if (c == '1')
                ind[j] ++, outd[i] ++, ing[j][i] = 1, outg[i][j] = 1;
        }
    }
    if (check_scc(ind, outd)) {
        printf("0 1\n");
        return 0;
    }
    int sum = 0;
    for (int i = 1; i <= n; i ++) {
        change(i);
        if (check_scc(ind, outd))
            sum ++;
        change(i);
    }
    if (sum) {
        printf("1 %d\n", sum);
        return 0;
    }
    if (n <= 6) {
        for (int i= 1;i <= n; i ++)
            for (int j = i + 1; j <= n; j ++) {
                change(i);
                change(j);
                if (check_scc(ind, outd))
                    sum ++;
                change(i);
                change(j);
            }
    }
    if (sum) {
        printf("2 %d\n", sum * 2);
        return 0;
    }
    puts("-1");
    return 0;
}