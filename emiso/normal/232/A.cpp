#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans[110][110], cont;

int main() {
    scanf("%lld", &n);

    int i;
    for(i = 1; i * (i-1) * (i-2) / 6 <= n && i <= 86; i++)
        for(int j = 1; j < i; j++)
            ans[i][j] = ans[j][i] = 1;

    cont = (i-1) * (i-2) * (i-3) / 6;
    int base = i - 1;

    for(; cont < n; i++) {
        int sz = 2;
        while(cont + sz * (sz + 1) / 2 <= n && sz < base) sz++;

        for(int j = 1; j <= sz; j++)
            ans[i][j] = ans[j][i] = 1;
        cont += sz * (sz - 1) / 2;
    }

    printf("%d\n", i-1);
    for(int k = 1; k < i; k++) {
        for(int j = 1; j < i; j++)
            printf("%lld", ans[k][j]);
        puts("");
    }

    int tmp = 0;
    for(int a = 1; a < i; a++) {
        assert(ans[a][a] == 0);
        for(int b = a + 1; b < i; b++) {
            assert(ans[a][b] == ans[b][a]);
            for(int c = b + 1; c < i; c++)
                if(ans[a][b] and ans[b][c] and ans[a][c])
                    tmp++;
        }
    }
    assert(tmp == n);

    return 0;
}