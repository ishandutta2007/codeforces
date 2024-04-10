#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <set>
#include <string>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

const int MAXN = 1000007;
const ll MAXV = 314000000ll;

struct Edge {
    int from;
    int delta;
    VI to;
};

Edge globalEdges[MAXN];
vector<Edge> edge[MAXN];
int n, m, edgeDegree[MAXN];

ll minResolve[MAXN];
vector<int> backEdge[MAXN];

ll ma[MAXN], mi[MAXN];
bool vis[MAXN], inStack[MAXN];

ll minvalue[MAXN];

void bfs() {
    REP(i, n) { mi[i] = -2; minResolve[i] = -2;}
    REP(i, m) edgeDegree[i] = globalEdges[i].to.size();

    set< pair<ll, int> > s;
    REP(i, n) {
        TR(it, edge[i]) {
            if (it->to.size() == 0) {
                int cost = it->delta;
                if (minResolve[i] == -2) {
                    minResolve[i] = cost;
                    s.insert(MP(cost, i));
                } else if (cost < minResolve[i]) {
                    s.erase(MP(minResolve[i], i));
                    minResolve[i] = cost;
                    s.insert(MP(cost, i));
                }
            }
        }
    }

    while (s.size()) {
        int i = s.begin()->second;
        s.erase(s.begin());

        if (minResolve[i] >= 0) {
            TR(it, backEdge[i]) {
                if (!--edgeDegree[*it]) {
                    int eid = *it;
                    ll sumCost = globalEdges[eid].delta;
                    TR(iter, globalEdges[eid].to) sumCost += minResolve[*iter];
                    sumCost = min(sumCost, MAXV);
                    if (minResolve[globalEdges[eid].from] == -2) {
                        minResolve[globalEdges[eid].from] = sumCost;
                        s.insert(MP(sumCost, globalEdges[eid].from));
                    } else if (sumCost < minResolve[globalEdges[eid].from]) {
                        s.erase(MP(minResolve[globalEdges[eid].from], globalEdges[eid].from));
                        minResolve[globalEdges[eid].from] = sumCost;
                        s.insert(MP(sumCost, globalEdges[eid].from));
                    }
                }
            }
        }
    }
}

void dfs2(int x) {
    inStack[x] = true;
    vis[x] = true;
    ma[x] = mi[x] = -2;
    TR(it, edge[x]) {
        ll maxv = it->delta, minv = it->delta;
        bool badEdge = false;
        TR(iter, it->to) {
            if (minvalue[*iter] == -2) {
                badEdge = true;
                break;
            }
            if (!vis[*iter]) dfs2(*iter);
            if (inStack[*iter]) {
                maxv = -1;
            } else {
                if (ma[*iter] == -1) {
                    maxv = -1;
                    if (mi[*iter] != -2) {

                    }
                } else if (maxv != -1) {
                    maxv += ma[*iter];
                    maxv = min(maxv, MAXV);
                    minv += mi[*iter];
                    minv = min(minv, MAXV);
                }
            }
        }

        if (badEdge) continue;

        if (maxv == -1) {
            ma[x] = -1;
        } else {
            if (ma[x] != -1) ma[x] = max(ma[x], maxv);
        }

        if (minv != -2) {
            if (mi[x] == -2 || minv < mi[x]) mi[x] = minv;
        }
    }
    inStack[x] = false;
}

int main() {
    cin >> m >> n;
    REP(i, m) {
        int at;
        scanf("%d", &at);
        --at;
        Edge newEdge;
        newEdge.from = at;
        newEdge.delta = 0;
        int k;
        scanf("%d", &k);
        REP(it, k) {
            int x;
            scanf("%d", &x);
            if (x == -1) {
                ++newEdge.delta;
            } else {
                newEdge.to.PB(x - 1);
                backEdge[x - 1].PB(i);
            }
        }

        globalEdges[i] = newEdge;
        edge[at].PB(newEdge);
    }
    bfs();

    REP(i, n) minvalue[i] = minResolve[i];
    REP(i, n) vis[i] = false;
    REP(i, n) {
        if (!vis[i]) {
            dfs2(i);
        }   
    }

    REP(i, n) mi[i] = minvalue[i];

    REP(x, n) {
        if (mi[x] == -2) {
            cout << -1 << " " << -1 << endl;
        } else {
            if (ma[x] == -1) ma[x] = -2;
            cout << mi[x] << " " << ma[x] << endl;
        }
    }
    return 0;
}