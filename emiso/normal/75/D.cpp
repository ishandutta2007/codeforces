#include <bits/stdc++.h>

using namespace std;

struct s {
    long long tot, l, r, sum;

    void print() {
        printf("%lld %lld %lld %lld\n", tot, l, r, sum);
    }
} sm[250050];

vector<int> a[55];
int b[250050], n, m, l, x;

void compute(int id) {
    long long best = a[id][0], cur = 0, rite = 0;
    for(int i =0; i < a[id].size(); i++) {
        sm[id].tot += a[id][i];

        cur += a[id][i];
        best = max(best, cur);
        if(cur < 0) cur = 0;

        rite = max(rite, sm[id].tot);
    }
    sm[id].sum = best;
    sm[id].r = rite;

    cur = 0;
    rite = 0;
    for(int i = a[id].size()-1; i>=0; i--) {
        cur += a[id][i];
        rite = max(rite, cur);
    }
    sm[id].l = rite;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++) {
        scanf("%d", &l);
        for(int j=0;j<l;j++) {
            scanf("%d", &x);
            a[i].push_back(x);
        }
        compute(i);
        //sm[i].print();
    }

    long long ans = -9999999999999999, sum = 0;

    for(int i=0;i<m;i++) {
       scanf("%d", &b[i]);
       b[i]--;
       ans = max(ans, sm[b[i]].sum);
    }

    for(int i=0;i<m;i++) {
       if(ans >= 0) ans = max(ans, sum + sm[b[i]].r);

       sum = max(0LL, max(sum + sm[b[i]].tot, sm[b[i]].l));
    }

    printf("%lld\n", ans);

    return 0;
}