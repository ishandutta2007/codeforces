#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, ans, a[MN];
map<vector<int>, int> cache;
int seq[] = {-1, 0, 4, 5, 4, 3};

int ask(int a, int b, int c) {
    if (a > b) swap(b, a);
    if (b > c) swap(b, c);
    if (a > b) swap(b, a);

    if (cache.count({a, b, c})) return cache[{a, b, c}];
    int x;
    printf("? %d %d %d\n", a, b, c);
    fflush(stdout);
    //x = max({seq[a], seq[b], seq[c]}) - min({seq[a], seq[b], seq[c]});
    scanf("%d", &x);
    return cache[{a, b, c}] = x;
}

int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &n);
        cache.clear();
        
        int maxi = 3;
        for (int i = 3; i <= n; i++) {
            if (ask(1, 2, i) > ask(1, 2, maxi)) maxi = i;
        }

        int piv = (maxi == 3) ? 4 : 3;
        if (ask(1, piv, maxi) < ask(1, 2, maxi) && ask(2, piv, maxi) < ask(1, 2, maxi)) {
            printf("! 1 2\n");
            fflush(stdout);
            continue;
        }
        
        if (ask(1, piv, maxi) < ask(1, 2, maxi)) {
            piv = 2;
        } else if (ask(2, piv, maxi) < ask(1, 2, maxi)) {
            piv = 1;
        } else if (ask(1, piv, maxi) == ask(1, 2, maxi) && ask(2, piv, maxi) == ask(1, 2, maxi)) {
            piv = 1; // ?? 
        }

        int best = piv;
        piv = (best == 1) ? 2 : 1;

        for (int i = 3; i <= n; i++) {
            if (i == maxi || i == piv) continue;
            if (ask(piv, i, maxi) > ask(piv, best, maxi))
                best = i;
        }
        
        printf("! %d %d\n", best, maxi);
        fflush(stdout);
    }
    return 0;
}