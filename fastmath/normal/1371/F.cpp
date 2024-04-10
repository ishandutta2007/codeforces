#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';

const int N = 5e5+7;

struct Node {
    int ans1, ans2, len;
    vector <pair <int, char> > l, r;
    Node () {
        l = r = {};
        ans1 = ans2 = len = 0;
    }
};  

void rel(int &a, int b) { a = max(a, b); }

Node merge(Node &l, Node &r) {

    if (l.ans1 == 0)
        return r;
    if (r.ans1 == 0)
        return l;

    Node ans;

    ans.len = l.len + r.len;

    ans.l = l.l;
    if (ans.l.size() == 1) {
        int ptr = 0;
        if (r.l[0].s == ans.l.back().s) {
            ans.l.back().f += r.l[0].f;
            ++ptr;    
        }   
        if (ptr < r.l.size()) {
            ans.l.app(r.l[ptr]);
        }
    }   
    else if (l.len == ans.l[0].f + ans.l[1].f && ans.l[1].s == r.l[0].s) {
        ans.l[1].f += r.l[0].f;
    }   

    ans.r = r.r;
    if (ans.r.size() == 1) {
        int ptr = 0;
        if (l.r[0].s == ans.r.back().s) {
            ans.r.back().f += l.r[0].f;
            ++ptr;
        }   
        if (ptr < l.r.size()) {
            ans.r.app(l.r[ptr]);
        }
    }   
    else if (r.len == ans.r[0].f + ans.r[1].f && ans.r[1].s== l.r[0].s) {
        ans.r[1].f += l.r[0].f;
    }   

    ans.ans1 = ans.ans2 = 0;
    for (auto e : ans.l) {
        ans.ans1 = max(ans.ans1, e.f);
        ans.ans2 = max(ans.ans2, e.f);
    }   
    for (auto e : ans.r) {
        ans.ans1 = max(ans.ans1, e.f);
        ans.ans2 = max(ans.ans2, e.f);
    }   
        
    auto relax = [&] (pair <int, char> l, pair <int, char> r) {
        if (l.s == '>') {
            rel(ans.ans1, l.f+r.f);
        }   
        else {
            rel(ans.ans2, l.f+r.f);
        }   
    };   

    if (ans.l.size() == 2) {
        relax(ans.l[0], ans.l[1]);
    }   

    if (ans.r.size() == 2) {
        relax(ans.r[1], ans.r[0]);
    }


    if (l.r[0].s != r.l[0].s) {
        relax(l.r[0], r.l[0]);
    }   
    else {
        pair <int, char> mid = mp(l.r[0].f+r.l[0].f, l.r[0].s);
        if (l.r.size() == 2) {
            relax(l.r[1], mid);
        }   
        if (r.l.size() == 2) {
            relax(mid, r.l[1]);
        }   
    }   
    
    rel(ans.ans1, l.ans1);
    rel(ans.ans2, l.ans2);

    rel(ans.ans1, r.ans1);
    rel(ans.ans2, r.ans2);

    return ans;
}   

char inv(char c) {
    if (c == '<')
        return '>';
    else
        return '<';
}   

int n, q;
string s;
Node tree[N << 2];
bool prop[N << 2];
void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v].l = tree[v].r = { mp(1, s[tl]) };
        tree[v].ans1 = tree[v].ans2 = tree[v].len = 1;
        return;
    }   
    int tm = (tl + tr) >> 1;
    build(v * 2 + 1, tl, tm);
    build(v * 2 + 2, tm + 1, tr);
    tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
}   
void gap(int v) {
    for (auto &e : tree[v].l) {
        e.s = inv(e.s);
    }   
    for (auto &e : tree[v].r) {
        e.s = inv(e.s);
    }       
    swap(tree[v].ans1, tree[v].ans2);
    prop[v] ^= 1;
}   
void push(int v) {
    if (prop[v]) {
        gap(v * 2 + 1);
        gap(v * 2 + 2);
        prop[v] = 0;
    }   
}   
Node upd(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl)
        return Node();
    if (l <= tl && tr <= r) {
        gap(v);
        return tree[v];
    }   
    int tm = (tl + tr) >> 1;
    push(v);
    auto ansl = upd(v * 2 + 1, tl, tm, l, r);
    auto ansr = upd(v * 2 + 2, tm + 1, tr, l, r);
    tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);    
    return merge(ansl, ansr);
}
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> q;
    cin >> s;
    build(0, 0, n - 1);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        cout << upd(0, 0, n - 1, l, r).ans1 << endl;
    }   
}