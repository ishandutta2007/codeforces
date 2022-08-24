#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
    int x;
    scanf("%d", &x);
    return x;
}

#define tm jaasdfs

struct Tree{
    int n;
    vector<pair<int, int>> a;

    Tree(int nn){
        n = 1;
        while (n < nn)
            n *= 2;
        a.resize(n + n);
    }

    Tree(){}

    Tree(const vector<pair<int, int>>& ar){
        int nn = ar.size();
        n = 1;
        while (n < nn)
            n *= 2;
        a.resize(n + n, {1e9, -1});
        for (int i = 0; i < nn; i++)
            a[n + i] = ar[i];
        for (int i = n - 1; i > 0; i--){
            a[i] = min(a[i + i], a[i + i + 1]);
        }
    }

    pair<int, int> _get(int v, int l1, int r1, int l, int r){
        if (l1 >= r || l >= r1)
            return {1e9, -1};
        if (l < l1)
             l=  l1;
        if (r > r1)
            r = r1;
        if (l == l1 && r == r1)
            return a[v];
        int m = (l1 + r1) / 2;
        return min(_get(v + v, l1, m, l, r), _get(v + v + 1, m, r1, l, r));
    }

    pair<int, int> get(int l, int r){
        return _get(1, 0, n, l, r);
    }
};

struct Node{
    int level;
    vector<Node*> a;
    Node* pr;
    int lst;

    Node(int level = 0, Node* pr = NULL):level(level),pr(pr){
        a.resize(26, NULL);
        lst = 1e9;
    }

    Node* go(char c){
        if (a[c - 'a'])
            return a[c - 'a'];
        else
            return a[c - 'a'] = new Node(level + 1, this);
    }
};

const int N = 333333;
vector<int> a[N];
string s;
int cnt[N];
char used[N];
int tin[N];
int tout[N];
vector<int> order;
int level[N];
int tm;
Tree tree;
int ad[N];

int lca(int u, int v){
    if (tout[v] < tin[u])
        return tree.get(tin[v], tout[u] + 1).second;
    else
        return tree.get(tin[u], tout[v] + 1).second;
}

void dfs0(int v){
    used[v] = 1;
    order.push_back(v);
    tin[v] = tm++;
    tout[v] = tm;
    for (auto x : a[v]){
        if (!used[x]){
            level[x] = level[v] + 1;
            dfs0(x);
            order.push_back(v);
            tout[v] = tm++;
        }
    }
}

void dfs(int v, Node* cur){
    cur = cur->go(s[v]);
    if (cur->lst < 1e8){
        int u = lca(cur->lst, v);
        // cerr << cur->lst + 1 << " " << v + 1 << " " << u + 1 << "\n";
        ad[u]++;
    }
    cur->lst = v;
    used[v] = 1;
    for (auto x : a[v]){
        if (!used[x]){
            dfs(x, cur);
            cnt[v] += cnt[x];
        }
    }
    cnt[v] -= ad[v] - 1;
}

int main(){

    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    cin >> s;

    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    tm = 0;
    dfs0(0);
    for (int i = 0; i < n; i++)
        used[i] = 0;
    vector<pair<int, itn>> qq;
    for (auto x : order){
        qq.push_back({level[x], x});
    }
    // for (auto x : qq)
    //  cerr << "(" << x.y + 1 << ", " << x.x << ") ";
    // cerr << "\n";
    // for (int i = 0; i < n; i++)
    //  cerr << "[" << tin[i] << ", " << tout[i] << "] ";
    // cerr << "\n";
    tree = Tree(qq);
    tm = 0;
    dfs(0, new Node());

    // for (int i = 0; i < n; i++)
    //  cerr << cnt[i] << " ";
    // cerr << "\n";

    for (int i = 0; i < n; i++)
        cnt[i] += c[i];
    int mx = 0;
    int cn = 0;
    for (int i = 0; i < n; i++){
        if (cnt[i] > mx){
            mx = cnt[i];
            cn = 1;
        } else
        if (cnt[i] == mx)
            cn++;
    }
    cout << mx << "\n" << cn << "\n";

    return 0;
}