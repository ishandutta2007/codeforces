#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)
#define MAXN 200000

typedef long long lint;

using namespace std;

int n;

struct node {
    vector <pair <int, int> > ords;
    int skip;
    
    node() {
        skip = 0;
    }
};

struct tree {
    vector <int> adj[MAXN];
    int parentof[MAXN];
    int next, preorder[MAXN], lastorder[MAXN], walk[MAXN];

    bool removed[MAXN];

    void dfs(int v, int parent) {
        walk[next] = v;
        preorder[v] = next++;

        for (int i = 0; i < (int)adj[v].size(); i++) {
            int v2 = adj[v][i];
            if (v2 == parent) continue;
            dfs(v2, v);
        }

        lastorder[v] = next-1;
    }
    
    void prepare(void) {
        next = 0;
        dfs(0, -1);
        for (int i = 0; i < n; i++) removed[i] = false;
    }

    node nodes[4*MAXN];
    vector <int> sonqueue;

    void consider(pair <int, int> o12, tree &t2) {
        int o1 = o12.first, o2 = o12.second;

        int v1 = walk[o1], v2 = walk[o2];

        int other_son;

        if (t2.preorder[v1] < t2.preorder[v2])
            other_son = v2;
        else
            other_son = v1;

        if (!t2.removed[other_son]) {
            t2.sonqueue.push_back(other_son);
            t2.removed[other_son] = true;
        }
    }

    void query(int a, int b, tree &t2) {
      const function<void(int, int, int)> solve = [&](int v, int l, int r) -> void {
        if (a > r || b < l) {
        } else if (a <= l && r <= b) {
          while (nodes[v].skip < (int)nodes[v].ords.size() && nodes[v].ords[nodes[v].skip].first < a) {
        consider(nodes[v].ords[nodes[v].skip], t2);
        nodes[v].skip++;
          }
          
          while (nodes[v].skip < (int)nodes[v].ords.size() && nodes[v].ords.back().first > b) {
        consider(nodes[v].ords.back(), t2);
        nodes[v].ords.pop_back();
          }
        } else {
          int m = (l+r)/2;
          solve(2*v+1, l, m);
          solve(2*v+2, m+1, r);
        }
      };
      solve(0, 0, n-1);
    }

    void parse_queue(tree &t2) {
        sort(sonqueue.begin(), sonqueue.end());

        for (int i = 0; i < (int)sonqueue.size(); i++) {
            int son = sonqueue[i];

            int o1 = preorder[son], o2 = lastorder[son];
            query(o1, o2, t2);
        }
    }

    void update(int ord1, int ord2, int n, int l, int r) {
        nodes[n].ords.push_back(make_pair(ord2, ord1));
        
        if (l < r) {
            int m = (l+r)/2;
            if (ord1 <= m) update(ord1, ord2, 2*n+1, l, m);
            else update(ord1, ord2, 2*n+2, m+1, r);
        }
    }

    void prepare2() {
        for (int i = 0; i < 4*n; i++)
            sort(nodes[i].ords.begin(), nodes[i].ords.end());
    }

    void add_edge(int v, int v2) {
        int ord1 = preorder[v];
        int ord2 = preorder[v2];
        update(ord1, ord2, 0, 0, n-1);
    }

    void add_edges_for(tree &t2) {
        for (int v = 0; v < n; v++) {
            for (int i = 0; i < (int)adj[v].size(); i++) {
                int v2 = adj[v][i];
                t2.add_edge(v, v2);
            }
        }
    }
} trees[2];

int main(int argc, char ** argv)
{
    scanf("%d", &n);

    for (int k = 0; k < 2; k++) {
        for (int i = 1; i < n; i++) {
            int p;
            scanf("%d", &p), p--;
            trees[k].parentof[i] = p;
            trees[k].adj[i].push_back(p);
            trees[k].adj[p].push_back(i);
        }
        
        trees[k].prepare();
    }

    for (int k = 0; k < 2; k++) {
        trees[k].add_edges_for(trees[k^1]);
    }

    for (int k = 0; k < 2; k++)
        trees[k].prepare2();

    int blueson;
    scanf("%d", &blueson);

    trees[0].sonqueue.push_back(blueson);
    trees[0].removed[blueson] = true;

    int k = 0;
    while (!trees[k].sonqueue.empty()) {
        trees[k].parse_queue(trees[k^1]);

        printf(k ? "Red\n" : "Blue\n");
        printf("%d", trees[k].sonqueue[0]);
        for (int i = 1; i < (int)trees[k].sonqueue.size(); i++)
            printf(" %d", trees[k].sonqueue[i]);
        printf("\n");

        trees[k].sonqueue.clear();
        k ^= 1;
    }

    return 0;
}