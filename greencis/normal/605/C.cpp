#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,p,q,pti,a[100105],b[100105];
vector<int> up,down;
pii pt[300105];

inline void add_pt(int x, int y) {
    pt[pti++] = make_pair(x, y);
}

inline bool cw(ll ax, ll ay, ll bx, ll by, ll cx, ll cy) {
    return ax * (by - cy) + bx * (cy - ay) + cx * (ay - by) < 0;
}

inline bool ccw(ll ax, ll ay, ll bx, ll by, ll cx, ll cy) {
    return ax * (by - cy) + bx * (cy - ay) + cx * (ay - by) > 0;
}

int main()
{
    scanf("%d%d%d",&n,&p,&q);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d",a+i,b+i);
        add_pt(a[i], b[i]);
        add_pt(a[i], 0);
        add_pt(0, b[i]);
    }
    add_pt(0, 0);
    sort(pt, pt + pti);

    vector<int> up,down;
    up.push_back(0);
    down.push_back(0);
    for (int i = 1; i < pti; ++i) {
        if (i == pti - 1 || cw(pt[0].first, pt[0].second,
                               pt[i].first, pt[i].second,
                               pt[pti-1].first, pt[pti-1].second)) {
            while (up.size() > 1 && !cw(pt[up[up.size()-2]].first, pt[up[up.size()-2]].second,
                                        pt[up[up.size()-1]].first, pt[up[up.size()-1]].second,
                                        pt[i].first, pt[i].second))
                up.pop_back();
            up.push_back(i);
        }
        if (i == pti - 1 || ccw(pt[0].first, pt[0].second,
                                pt[i].first, pt[i].second,
                                pt[pti-1].first, pt[pti-1].second)) {
            while (down.size() > 1 && !ccw(pt[down[down.size()-2]].first, pt[down[down.size()-2]].second,
                                           pt[down[down.size()-1]].first, pt[down[down.size()-1]].second,
                                           pt[i].first, pt[i].second))
                down.pop_back();
            down.push_back(i);
        }
    }
    for (int i = (int)down.size() - 2; i > 0; --i)
        up.push_back(down[i]);

    ld dest_dist = 0;
    ld A1 = ld(q) / ld(p), B1 = -1, C1 = 0;
    for (int i = 1; i + 1 < up.size(); ++i) {
        ld A2 = pt[up[i]].second - pt[up[i+1]].second;
        ld B2 = pt[up[i+1]].first - pt[up[i]].first;
        ld C2 = -A2 * pt[up[i]].first - B2 * pt[up[i]].second;
        if (fabsl(A1 * B2 - A2 * B1) > ld(1e-9)) {
            ld xc = -(C1 * B2 - C2 * B1) / (A1 * B2 - A2 * B1);
            ld yc = -(A1 * C2 - A2 * C1) / (A1 * B2 - A2 * B1);
            if (((ld)pt[up[i]].first <= xc + ld(1e-9) && xc <= pt[up[i+1]].first + ld(1e-9) ||
                 (ld)pt[up[i+1]].first <= xc + ld(1e-9) && xc <= pt[up[i]].first + ld(1e-9)) &&
                ((ld)pt[up[i]].second <= yc + ld(1e-9) && yc <= pt[up[i+1]].second + ld(1e-9) ||
                 (ld)pt[up[i+1]].second <= yc + ld(1e-9) && yc <= pt[up[i]].second + ld(1e-9))) {
                dest_dist = max(dest_dist, hypotl(xc, yc));
            }
        }
    }

    cout << setprecision(17) << fixed << hypotl(p, q) / dest_dist;

    return 0;
}