#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair
#define INF (99999999)

using namespace std;
typedef long long ll;

int n, l = -1, r = -1, c[MN], d[MN], flag = 1;

void addrating(int rat) {
    if(l != - INF)
        l += rat;
    if(r != INF)
        r += rat;
}

int main() {
    scanf("%d",&n);

    for(int i=0; i<n; i++) {
        scanf("%d %d",&c[i], &d[i]);

        if(!i) {
            if(d[i] == 1) {
                l = 1900;
                r = INF;
            }
            else {
                l = -INF;
                r = 1899;
            }
        }

        else {
            if(d[i] == 1 && r < 1900) flag = 0;
            if(d[i] == 2 && l >= 1900) flag = 0;

            if(d[i] == 1) l = max(l, 1900);
            if(d[i] == 2) r = min(r, 1899);
        }

        addrating(c[i]);
        //printf("%d %d\n", l, r);
    }

    if(!flag) printf("Impossible\n");
    else {
        if(r == INF) printf("Infinity\n");
        else printf("%d\n", r);
    }
    return 0;
}