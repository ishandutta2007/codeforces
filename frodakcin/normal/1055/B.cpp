#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

const int MAXN = 1e5 + 100;

int N, M, L;
int l[MAXN];

int main() {
    scanf("%d%d%d", &N, &M, &L);
    
    int ans = 0;
    for(int i = 1;i <= N;i++) {
        scanf("%d", l + i);
        if(l[i] > L) {
            ans++;
            if(i > 1 and l[i-1] > L) ans--;
        }
    }
    
    while(M--) {
        int q;
        scanf("%d", &q);
        if(q == 0) printf("%d\n", ans);
        else if(q == 1) {
            int p, d;
            scanf("%d%d", &p, &d);
            
            if(l[p] <= L and (l[p] += d) > L) {
                ans++;
                if(p > 1 and l[p-1] > L) ans--;
                if(p < N and l[p+1] > L) ans--;
            }
        } else assert(false);
    }
    
    return 0;
}