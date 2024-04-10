#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, m, ans = 0, l1[MN], l2[MN], r1[MN], r2[MN], l[2], r[2];

int main() {
    scanf("%d",&n);
    r[0] = r[1] = 1100000000;

    for(int i=0; i<n; i++) {
        scanf("%d %d",&l1[i], &r1[i]);
    }

    scanf("%d",&m);
    for(int i=0; i<m; i++) {
        scanf("%d %d",&l2[i], &r2[i]);
    }

    for(int i=0; i<n; i++) {
        l[0] = max(l[0], l1[i]);
        r[0] = min(r[0], r1[i]);
    }

    for(int i=0; i<m; i++) {
        l[1] = max(l[1], l2[i]);
        r[1] = min(r[1], r2[i]);
    }

    ans = max(max(l[0] - r[1], 0), max(l[1] - r[0],0));

    printf("%d\n", ans);
    return 0;
}