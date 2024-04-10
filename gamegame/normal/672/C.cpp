#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int x[100010], y[100010];
double d[100010], a[100010], b[100010], s;
pair<double, int> pa[100010], pb[100010];

int main()
{
    int ax, ay, bx, by, tx, ty, n;
    scanf("%d%d%d%d%d%d%d", &ax, &ay, &bx, &by, &tx, &ty, &n);

    for(int i=0; i<n; ++i) {
        scanf("%d%d", x+i, y+i);
        d[i]=hypot(tx-x[i], ty-y[i]);
        a[i]=hypot(ax-x[i], ay-y[i]);
        b[i]=hypot(bx-x[i], by-y[i]);
        pa[i]=make_pair(a[i], i);
        pb[i]=make_pair(b[i], i);
        s+=d[i];
    }
    sort(pa, pa+n);
    sort(pb, pb+n);

    double res=1e40;
    for(int i=0; i<n; ++i) {
        res=min(res, a[i]+2*s-d[i]);
        res=min(res, b[i]+2*s-d[i]);
    }

    if (n>1) {
        for(int i=0; i<min(n, 1000); ++i) {
            for(int j=0; j<min(n, 1000); ++j) {
                int ka=pa[i].second, kb=pb[j].second;
                if (ka!=kb) res=min(res, a[ka]-d[ka]+b[kb]-d[kb]+2*s);
            }
        }
    }
    printf("%.12f\n", res);
}