#include <stdio.h>
#include <set>
#include <vector>

using namespace std;

vector<int> g[1000000];
int numb[1000000];
int R[1000000];
int pr[1000000];
int cc;

set<int> s;
int n, a, b, q, op, v;

void dfs(int v, int p) {
    numb[v] = cc++;
    for (int i = 0; i < g[v].size(); i++) {
        if (g[v][i] != p) dfs(g[v][i], v);
    }
    R[v] = cc;
    pr[v] = p;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n-1; i++) {
        scanf("%d %d", &a, &b);
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0, -1);
    for (int i = 0; i < n; i++) s.insert(i);

    scanf("%d", &q);
    for (; q; q--) {
        scanf("%d %d", &op, &v);
        v--;

        if (op == 1) {
            vector<int> d;
            set<int>::iterator iter = s.lower_bound(numb[v]);
            
            bool found = false;
            for (; iter != s.end() && *iter < R[v]; ++iter ) {
                found = true;
                d.push_back(*iter);
            }
            for (int i = 0; i < d.size(); i++) {
                s.erase(d[i]);
            }

            if (found && pr[v] != -1) s.insert(numb[pr[v]]);
        }
        else if (op == 2) {
            s.insert(numb[v]);    
        }
        else {
            set<int>::iterator iter = s.lower_bound(numb[v]);
            printf("%d\n", !(iter != s.end() && *iter < R[v]));
        }

    }
}