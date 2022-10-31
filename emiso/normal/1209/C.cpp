#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, t, d[MN], cor[MN], mini[MN];

int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &n);
        for(int i = 0; i < n; i++) {
            scanf("%1lld", &d[i]);
            cor[i] = 0;
        }

        mini[n-1] = d[n-1];
        for(int i = n-2; i >= 0; i--) {
            mini[i] = min(d[i], mini[i+1]);
        }

        ll ans = 1, miniL = 10, last = -1;
        for(int i = 0; i < n; i++) {
            if(d[i] > mini[i] || d[i] > miniL) {
                miniL = min(miniL, d[i]);
            } else if(last <= d[i]) {
                cor[i] = 1;
                last = d[i];
            }
        }

        for(int i = 0; i < n; i++) {
            if(cor[i] == 0) {
                if(last <= d[i]) {
                    cor[i] = 2;
                    last = d[i];
                } else ans = 0;
            }
        }

        if(!ans) puts("-");
        else {
            for(int i = 0; i < n; i++) printf("%lld", cor[i]);
            puts("");
        }
    }
    return 0;
}