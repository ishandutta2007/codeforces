#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;

struct entry {
    int x,y,idx;
    ld angle;
} e[100105];

int comp(entry a, entry b) {
    return a.angle < b.angle;
}

int n;

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d",&e[i].x,&e[i].y);
        e[i].idx = i;
        e[i].angle = atan2l(e[i].y, e[i].x);
    }
    sort(e,e+n,comp);

    ld ans = 2e9;
    int ansa = -1, ansb = -1;
    e[n] = e[0];
    e[n].angle += ld(acosl(ld(-1))) * ld(2);
    for (int i = 0; i < n; ++i) {
        ld cur = e[i+1].angle - e[i].angle;
        if (cur < ans) {
            ans = cur;
            ansa = e[i].idx + 1;
            ansb = e[i+1].idx + 1;
        }
    }

    printf("%d %d",ansa,ansb);

    return 0;
}