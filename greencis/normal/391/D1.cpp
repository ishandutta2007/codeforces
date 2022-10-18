#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
using namespace std;

struct entry {
    int x1, y1, x2, y2, hor, beg, prior;
} e[300105], en[300105];

int eni;
int n,m,x,y,l;

int comp(entry a, entry b) {
    if (a.x1 == b.x1) {
        return a.prior > b.prior;
    }
    return a.x1 < b.x1;
}

set<int> s;

bool check(int d) {
    s.clear();
    eni = 0;
    for (int i = 0; i < n+m; ++i) {
        if (e[i].hor) {
            if (e[i].x1 + d <= e[i].x2 - d) {
                en[eni].y1 = en[eni].y2 = e[i].y1;
                en[eni].x1 = en[eni].x2 = e[i].x1 + d;
                en[eni].hor = 1;
                en[eni].beg = 1;
                en[eni].prior = 3;
                ++eni;

                en[eni].y1 = en[eni].y2 = e[i].y1;
                en[eni].x1 = en[eni].x2 = e[i].x2 - d;
                en[eni].hor = 1;
                en[eni].beg = 0;
                en[eni].prior = 1;
                ++eni;
            }
        } else {
            if (e[i].y1 + d <= e[i].y2 - d) {
                en[eni].y1 = e[i].y1 + d;
                en[eni].y2 = e[i].y2 - d;
                en[eni].x1 = en[eni].x2 = e[i].x1;
                en[eni].hor = 0;
                en[eni].beg = 0;
                en[eni].prior = 2;
                ++eni;
            }
        }
    }

    sort(en,en+eni,comp);
    for (int i = 0; i < eni; ++i) {
        if (en[i].hor) {
            if (en[i].beg)
                s.insert(en[i].y1);
            else s.erase(en[i].y1);
        } else {
            if (s.lower_bound(en[i].y1) != s.end() && (*s.lower_bound(en[i].y1)) <= en[i].y2)
                return 1;
        }
    }

    return 0;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++i) { /// VERTICAL 
        scanf("%d%d%d",&x,&y,&l);
        e[m+i].x1 = e[m+i].x2 = x;
        e[m+i].y1 = y;
        e[m+i].y2 = y + l;
    }
    for (int i = 0; i < m; ++i) { /// HORIZONTAL 
        scanf("%d%d%d",&x,&y,&l);
        e[i].y1 = e[i].y2 = y;
        e[i].x1 = x;
        e[i].x2 = x + l;
        e[i].hor = 1;
    }

    if (!check(1)) { printf("0"); return 0; }
    int l = 1, r = 1e9;
    while (l <= r) {
        if (l == r) { printf("%d",l); return 0; }
        if (l+1 == r) {
            if (check(r)) { printf("%d",r); return 0; }
            printf("%d",l); return 0;
        }
        int mid = (l + r) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    printf("0");
    return 0;
}