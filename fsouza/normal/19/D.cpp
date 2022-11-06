#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <map>

#define INF 1000000002

using namespace std;

int main()
{
    int n;
    vector <int> ys;
    vector <pair <char, pair <int, int> > > ops;

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        char op[32];
        int x, y;

        scanf(" %s %d %d", op, &x, &y);
        if (op[0] != 'f')
            ys.push_back(y);
        ops.push_back(make_pair(op[0], make_pair(x, y)));
    }

    sort(ys.begin(), ys.end());
    ys.resize(unique(ys.begin(), ys.end())-ys.begin());
    int nys = ys.size();

    vector <multiset<int> > bit(nys);
    map <int, set<int> > y4x;

    for (int i = 0; i < n; i++) {
        int x = ops[i].second.first, y = ops[i].second.second;

        if (ops[i].first == 'f') {
            int yid = upper_bound(ys.begin(), ys.end(), y)-ys.begin();
            int minx = INF;

            while (yid < nys) {
                multiset<int>::iterator it = bit[yid].upper_bound(x);
                if (it != bit[yid].end()) minx = min(minx, *it);

                if (!yid) break;
                yid += yid&-yid;
            }

            if (minx == INF)
                printf("-1\n");
            else
                printf("%d %d\n", minx, *y4x[minx].upper_bound(y));
        } else {
            int yid = lower_bound(ys.begin(), ys.end(), y)-ys.begin();

            if (ops[i].first == 'a') y4x[x].insert(y);
            else y4x[x].erase(y);

            while (yid >= 0) {
                if (ops[i].first == 'a') bit[yid].insert(x);
                else bit[yid].erase(bit[yid].find(x));
                    
                yid -= yid?yid&-yid:1;
            }
        }
    }

    return 0;
}