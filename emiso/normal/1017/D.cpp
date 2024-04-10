#include <bits/stdc++.h>

using namespace std;

int n, m, q, x, z, freq[1 << 12], w[13], quant[1 << 12][101], mx;
char s[13];

int to_int() {
    int res = 0;
    for(int i = 0; i < n; i++, res *= 2)
        res += (s[i] == '1');
    return res / 2;
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    mx = (1 << n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &w[n-i-1]); // cuidado
    }

    for(int i = 0; i < m; i++) {
        scanf("%s", &s);
        freq[to_int()]++;
    }

    for(int i = 0; i < mx; i++) {
        for(int j = 0; j < mx; j++) {
            int W = 0, k = i ^ j;
            for(int d = 0; d < n; d++) {
                if( ((1 << d) & k) == 0) W += w[d];
            }
            if(W <= 100) quant[i][W] += freq[j];
        }
    }

    while(q--) {
        scanf("%s %d", &s, &z);
        x = to_int();
        int ans = 0;
        for(int i = 0; i <= z; i++)
            ans += quant[x][i];
        printf("%d\n", ans);
    }

    return 0;
}