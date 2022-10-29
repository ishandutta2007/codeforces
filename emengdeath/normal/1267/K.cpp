#include <bits/stdc++.h>
#define L 100
using namespace std;
int T, c[L];
long long C[L][L], n;
int main() {
    for(int i = 0; i < L; ++ i) {
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; ++ j)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
    scanf("%d", &T);
    while(T --) {
        scanf("%I64d", &n);
        int l = 1;
        while(n) ++ l, ++ c[n % l], n /= l;
        long long ans = 1;
        for(int i = l - 1, k = 0; i >= 0; -- i) {
            if(i >= 1) ++ k;
            ans *= C[k][c[i]];
            k -= c[i];
        }
        if(c[0] && !c[l - 1]) {
            -- c[0], -- l;
            long long tmp = 1;
            for(int i = l - 1, k = 0; i >= 0; -- i) {
                if(i >= 1) ++ k;
                tmp *= C[k][c[i]];
                k -= c[i];
            }
            ans -= tmp;
        }
        cout << ans - 1 << endl;
        for(int i = 0; i < l; ++ i) c[i] = 0;
    }
}