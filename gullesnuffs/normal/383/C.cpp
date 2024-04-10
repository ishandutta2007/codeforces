#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

int a[200005];
vector<int> adj[200005];
int posInTree[200005];
int treeSize;
int parent[200005];
int lastChildPos[200005];
bool lastChild[200005];
bool visited[200005];
int sign[200005];

struct Fenwick{
    int f[200005];

    void update(int pos, int val){
        for (int ind = pos; ind < 200005; ind |= (ind + 1))
            f[ind] += val;
    }

    int query(int pos){
        int res = 0;
        for (int ind = pos; ind >= 0; ind = ((ind&(ind + 1)) - 1))
            res += f[ind];
        return res;
    }
} fenwick;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i){
        scanf("%d", a + i);
        visited[i] = 0;
    }
    for (int i = 0; i < n - 1; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        --a;
        --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    stack<int> s;
    s.push(0);
    treeSize = 0;
    posInTree[0] = 0;
    lastChild[0] = 0;
    visited[0] = 1;
    sign[0] = 1;
    while (!s.empty()){
        int c = s.top();
        posInTree[c] = treeSize++;
        s.pop();
        int l = -1;
        for (int i = 0; i < adj[c].size(); ++i){
            int x = adj[c][i];
            if (visited[x])
                continue;
            s.push(x);
            parent[x] = c;
            visited[x] = 1;
            sign[x] = -sign[c];
            if (l == -1)
                lastChild[x] = 1;
            l = i;
        }
        if (l == -1){
            int node = c;
            lastChildPos[node] = treeSize;
            while (lastChild[node]){
                node = parent[node];
                lastChildPos[node] = treeSize;
            }
        }
    }
    for (int i = 0; i < n; ++i){
        fenwick.update(posInTree[i], a[i]*sign[i]);
        fenwick.update(posInTree[i] + 1, -a[i]*sign[i]);
    }
    for (int i = 0; i < m; ++i){
        int type;
        scanf("%d", &type);
        if (type == 1){
            int node, val;
            scanf("%d%d", &node, &val);
            --node;
            fenwick.update(posInTree[node], val*sign[node]);
            fenwick.update(lastChildPos[node], -val*sign[node]);
        }
        else{
            int node;
            scanf("%d", &node);
            --node;
            int res = fenwick.query(posInTree[node]);
            printf("%d\n", res*sign[node]);
        }
    }
    return 0;
}