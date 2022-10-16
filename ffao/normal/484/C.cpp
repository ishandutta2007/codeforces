#include <cstdio>
#include <cstring>

int n;
char ss[2][1100000];
int to[1100000];
int from[1100000];
int dist[1100000];
int next[1100000][30];
int q, t, k, d;

int getAfter(int atPos, int remainingShuffles) {
    int j = 0;
    while (remainingShuffles) {
        if (remainingShuffles & (1<<j)) {
            atPos = next[atPos][j];
            remainingShuffles ^= (1<<j);
        }
        j++;
    }
    return atPos;
}

int main() {
    scanf("%s", ss[0]);
    n = strlen(ss[0]);
    ss[1][n] = '\0';

    for (scanf("%d", &t); t; t--) {
        q^=1;
        scanf("%d %d", &k, &d);

        int cnt = 0;
        for (int mod = 0; mod < d; mod++) {
            for (int p = mod; p < k; p+=d) {
                next[p][0] = cnt-1;
                if (cnt != 0) from[cnt-1] = p;
                cnt++;
            }
        }
        from[k-1] = 0;
        next[0][0] = 0;

        int p = 1, j = 1;
        while (p <= n) {
            for (int i = 0; i < k; i++) {
                next[i][j] = next[next[i][j-1]][j-1];
            }
            p <<= 1;
            j++;
        }

        for (int i = 0; i < k; i++) dist[i] = -1;

        int dd = 0;
        int v = 0;
        while (dist[v] == -1) {
            dist[v] = dd;
            dd++;
            v = from[v];
        }
        
        for (int i = 0; i < n; i++) {
            int firstShuffle, atPos;

            if (i < k) {
                firstShuffle = 0;
                atPos = i;
            }
            else {
                firstShuffle = i-k+1;
                atPos = k-1;
            }

            int remainingShuffles = (n-k+1) - firstShuffle;
            if (dist[atPos] != -1 && dist[atPos] <= remainingShuffles) {
                ss[q][firstShuffle+dist[atPos]] = ss[q^1][i];
            }
            else {
                int finalPos = getAfter(atPos, remainingShuffles);
                ss[q][n-k+finalPos+1] = ss[q^1][i];
            }
        }

        printf("%s\n", ss[q]);
    }
}