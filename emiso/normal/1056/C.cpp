#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int n, m, a, b, val[2010], id, in[2020], nxt, t;
vector<pair<int, int>> edg, vvs;

int main() {
    scanf("%d %d", &n, &m);
    int sz = 2 * n;

    for(int i = 1; i <= 2*n; i++) {
        scanf("%d", &val[i]);
        vvs.emplace_back(val[i], i);
        in[i] = 1;
    }
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        edg.emplace_back(a, b);
    }
    scanf("%d", &t);

    while(sz) {
        if(t == 2) {
            nxt = 0;
            scanf("%d", &id);

            in[id] = 0;
            for(auto ed : edg) {
                if(ed.first == id && in[ed.second]) nxt = ed.second;
                else if(ed.second == id && in[ed.first]) nxt = ed.first;
            }

            t = 1;
        } else {
            if(nxt) {
                printf("%d\n", nxt);
                fflush(stdout);
                in[nxt] = 0;
            } else {
                for(auto ed : edg) {
                    if(in[ed.first]) {
                        if(val[ed.first] > val[ed.second])
                            nxt = ed.first;
                        else nxt = ed.second;
                        break;
                    }
                }

                if(!nxt) for(auto v : vvs) {
                    if(in[v.second] && (!nxt || val[nxt] < val[v.second]))
                        nxt = v.second;
                }

                printf("%d\n", nxt);
                fflush(stdout);
                in[nxt] = 0;
            }
            nxt = 0;
            t = 2;
        }
        sz--;
    }
    return 0;
}