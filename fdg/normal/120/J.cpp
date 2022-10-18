#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <memory.h>
#include <string>
#include <map>
#include <set>
#include <ctime>

using namespace std;

const int MAXN=400002;

struct pt {
    int x, y, id;
};

inline bool cmp_x (const pt & a, const pt & b) {
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

inline bool cmp_y (const pt & a, const pt & b) {
    return a.y < b.y;
}

pt a[MAXN];

double mindist;
int ansa, ansb;

inline void upd_ans (const pt & a, const pt & b) {
    if ((a.id/4)==(b.id/4)) return;
    double dist = sqrt ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + .0);
    if (dist < mindist)
        mindist = dist,  ansa = a.id,  ansb = b.id;
}

void rec (int l, int r) {
    if (r - l <= 3) {
        for (int i=l; i<=r; ++i)
            for (int j=i+1; j<=r; ++j)
                upd_ans (a[i], a[j]);
        sort (a+l, a+r+1, &cmp_y);
        return;
    }

    int m = (l + r) >> 1;
    int midx = a[m].x;
    rec (l, m),  rec (m+1, r);
    inplace_merge (a+l, a+m+1, a+r+1, &cmp_y);

    static pt t[MAXN];
    int tsz = 0;
    for (int i=l; i<=r; ++i)
        if (abs (a[i].x - midx) < mindist) {
            for (int j=tsz-1; j>=0 && a[i].y - t[j].y < mindist; --j)
                upd_ans (a[i], t[j]);
            t[tsz++] = a[i];
        }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,x,y,cnt=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        a[cnt].x=x; a[cnt++].y=y;
        a[cnt].x=-x; a[cnt++].y=y;
        a[cnt].x=x; a[cnt++].y=-y;
        a[cnt].x=-x; a[cnt++].y=-y;
    }
    for(int i=0;i<cnt;i++) a[i].id=i;
    sort (a, a+cnt, &cmp_x);
    mindist = 1E20;
    ansa=ansb=1000000;
    rec (0, cnt-1);
    cout << ansa/4+1 << " " << ansa%4+1 << " " << ansb/4+1 << " " << (3-ansb%4)+1 << endl;
    return 0;
}