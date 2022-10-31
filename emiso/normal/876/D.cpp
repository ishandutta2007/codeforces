#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int bit[MN], n, p, ans = 1;

void upd(int idx) {
    for(; idx < MN; idx += (idx & -idx)) bit[idx] += 1;
}

int query(int idx) {
    int sum = 0;
    for(; idx; idx -= (idx & -idx)) sum += bit[idx];
    return sum;
}

int rquery(int l, int r) {
    return query(r) - query(l - 1);
}

int main() {
    scanf("%d", &n);

    printf("%d", ans);
    for(int i = 0; i < n; i++) {
        scanf("%d", &p);
        upd(p);

        if(rquery(p, n) != n - p + 1)
            ans++;

        else {
            int l = 1, r = p;
            while(l < r) {
                int m = (l + r) >> 1;
                if(rquery(m, p) == p - m + 1) {
                    r = m;
                }
                else l = m + 1;
            }
            ans -= (p - l);
        }

        printf(" %d", ans);
    }
    puts("");

    return 0;
}