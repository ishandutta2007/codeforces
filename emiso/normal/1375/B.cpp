#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, t, m, lixo;

int main() {
    scanf("%lld", &t);
    st:

    scanf("%lld %lld", &n, &m);
    int can = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%lld", &lixo);
            if(i > 0 && i + 1 < n && j > 0 && j + 1 < m) {
                if(lixo > 4) can = 0;
            } else {
                if(i == 0 || i + 1 == n) {
                    if(j == 0 || j + 1 == m) {
                        if(lixo > 2) can = 0;
                    } else {
                        if(lixo > 3) can = 0;
                    }
                } else if(j == 0 || j + 1 == m) {
                    if(lixo > 3) can = 0;
                } else assert(false);
            }
        }
    }

    if(can == 0) puts("NO");
    else {
        puts("YES");
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || i + 1 == n) {
                    if(j == 0 || j + 1 == m) printf("2 ");
                    else printf("3 ");
                } else {
                    if(j == 0 || j + 1 == m) printf("3 ");
                    else printf("4 ");
                }
            }
            puts("");
        }
    }

    if(--t) goto st;
    return 0;
}