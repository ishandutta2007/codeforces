#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e16 + 7;
const int MAXN = 2e5 + 7;

int n;

vector <pair <int, int> > g[MAXN];

int bad = -1;
bool used1[MAXN];
void dfs(int u, int father){
    used1[u] = true;
    for (pair <int, int> e: g[u]){
        int v = e.first;
        int c = e.second;
        if (v == father) continue;
        if (used1[v]) bad = u;
        else dfs(v, u);
    }
}

vector <int> path;
vector <int> st;
bool used2[MAXN];
 build(int u, int father){
    st.push_back(u);
    used2[u] = true;
    for (pair <int, int> e: g[u]){
        int v = e.first;
        int c = e.second;
        if (v == father) continue;
        if (v == bad) path = st;
        else build(v, u);
    }
    st.pop_back();
}

set <int> bads;
bool used3[MAXN];
int cost[MAXN];
int calc(int u){
    used3[u] = true;
    int res = 0;
    for (pair <int, int> e: g[u]){
        int v = e.first;
        int c = e.second;
        if (!used3[v] && bads.find(v) == bads.end()){
            res = max(res, c + calc(v));
        }
    }
    return res;
}

pair <int, int> get(int u, int father){
    pair <int, int> res = {0, u};
    for (pair <int, int> e: g[u]){
        int v = e.first;
        int c = e.second;

        if (v == father || bads.find(v) != bads.end()) continue;
        pair <int, int> new_r = get(v, u);
        new_r.first += c;

        res = max(res, new_r);
    }
    return res;
}

map <pair <int, int> , int > d;
int nextc[MAXN];
int ctof[MAXN];

struct Node{
    int a, b, y, cnt;
    int mxa, mxb;
    int res;
    Node *l, *r;
};

Node *init(int a, int b){
    Node *res = new Node;
    res->a = res->mxa = a;
    res->b = res->mxb = b;
    res->res = -MOD;
    res->cnt = 1;
    res->y = (rand() << 15) + rand();
    res->l = res->r = NULL;
    return res;
}

int mxa(Node *t){
    if (!t) return -MOD;
    return t->mxa;
}

int mxb(Node *t){
    if (!t) return -MOD;
    return t->mxb;
}

int cnt(Node *t){
    if (!t) return 0;
    return t->cnt;
}

int res(Node *t){
    if (!t) return -MOD;
    return t->res;
}

Node *relax(Node *t){
    t->mxa = max(max(mxa(t->l), mxa(t->r)), t->a);
    t->mxb = max(max(mxb(t->l), mxb(t->r)), t->b);
    t->cnt = cnt(t->l) + cnt(t->r) + 1;

    //cout << mxa(t->l) << ' ' << mxb(t->r) << ' ' << t->a << ' ' << t->b << ' ' << mxa(t->l) + t->b << '\n';
    int new_res = mxa(t->l) + mxb(t->r);
    new_res = max(new_res, mxa(t->l) + t->b);
    new_res = max(new_res, t->a + mxb(t->r));
    t->res = max(max(res(t->l), res(t->r)), new_res);
    //cout << "t->res: " << t->res << '\n';
}

pair <Node*, Node*> split(Node *t, int k){
    if (!t) return {NULL, NULL};
    if (k <= cnt(t->l)){
        auto tmp = split(t->l, k);
        t->l = tmp.second;
        relax(t);
        return {tmp.first, t};
    }
    else{
        auto tmp = split(t->r, k - cnt(t->l) - 1);
        t->r = tmp.first;
        relax(t);
        return {t, tmp.second};
    }
}

Node *merge(Node *l, Node *r){
    if (!l) return r;
    if (!r) return l;
    if (l->y > r->y){
        l->r = merge(l->r, r);
        relax(l);
        return l;
    }
    else{
        r->l = merge(l, r->l);
        relax(r);
        return r;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cout.precision(40);
    cin >> n;
    for (int i = 0; i < n; ++i){
        int u, v, c;
        cin >> u >> v >> c;
        g[u - 1].push_back({v - 1, c});
        g[v - 1].push_back({u - 1, c});
        d[{u - 1, v - 1}] = c;
        d[{v - 1, u - 1}] = c;
    }

    dfs(0, -1);
    build(bad, -1);

    for (int u: path) bads.insert(u);

    int len = path.size();

    for (int i = 0; i < len; ++i){
        cost[i] = calc(path[i]);
        //cout << path[i] << ' ';
    }
    //cout << '\n';

    int ans1 = -MOD;
    for (int i = 0; i < len; ++i){
        int u = path[i];
        bads.erase(u);
        pair <int, int> tmp = get(u, -1);
        pair <int, int> d = get(tmp.second, -1);
        ans1 = max(ans1, d.first);
        bads.insert(u);
    }

    int sumlen = 0;
    for (int i = 0; i < len; ++i){
        int u = path[i];
        int v = path[(i + 1) % len];
        if (i) ctof[i] = ctof[i - 1] + nextc[i - 1];
        sumlen += d[{u, v}];
        nextc[i] = d[{u, v}];
    }

    Node *root = NULL;
    for (int i = 0; i < len; ++i){
        root = merge(root, init(cost[i] - ctof[i], cost[i] + ctof[i]));
    }

    int ans = root->res;
    //cout << ans << '\n';
    for (int i = 0; i < len; ++i){
        int r = sumlen + ctof[i];
        auto tmp = split(root, 1);
        root = merge(tmp.second, init(cost[i] - r, cost[i] + r));
        ans = min(ans, root->res);
        //cout << "KEK: " << i << ' ' << ans << '\n';
    }

    ans = max(ans, ans1);
    cout << ans;
    return 0;
}