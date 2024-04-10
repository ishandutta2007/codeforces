#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

struct node {
    int next[30];
};

int occ;
vector<int> adj[310000];
node nodes[410000];
int val[310000];
char ch[310000];
stack<int> boundaries;
vector<int> item_locations[310000];
vector<int> contain[310000];
int cc;

long long best = -1;
int ct = 0;
int n;

void cons(int v, int p, int curnode) {
    contain[v].push_back(curnode);

    for (int x : adj[v]) if (x != p) {
        if (nodes[curnode].next[ch[x]-'a'] == -1) nodes[curnode].next[ch[x]-'a'] = occ++;
        cons(x, v, nodes[curnode].next[ch[x]-'a']);
    }
}

void merge(int a, int b) {
    if (contain[a].size() < contain[b].size()) {
        swap(contain[a], contain[b]);
    }

    for (int k : contain[b]) {
        item_locations[k].pop_back();
        if (item_locations[k].empty() || *item_locations[k].rbegin() < boundaries.top()) {
            item_locations[k].push_back(boundaries.top());
            contain[a].push_back(k);
        }
    }
}

void dfs(int v, int p, int curnode) {
    boundaries.push(++cc);
    item_locations[contain[v][0]].push_back(cc);

    for (int x : adj[v]) if (x != p) {
        dfs(x, v, nodes[curnode].next[ch[x]-'a']);
        merge(v, x);
    }

    long long th = val[v] + 0ll + contain[v].size();
    if (th > best) {
        best = th;
        ct = 1;
    }
    else if (th == best) ct++;

    boundaries.pop();
}

int main() {
    memset(nodes,-1,sizeof(nodes));
    scanf("%d", &n);
    REP(i,n) {
        scanf("%d", &val[i]);
    }
    REP(i,n) scanf(" %c", &ch[i]);
    occ++;

    REP(i,n-1){
        int u,v;
        scanf("%d %d", &u, &v); u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cons(0, -1, 0); 
    dfs(0, -1, 0);

    printf("%lld\n", best);
    printf("%d\n", ct);
}