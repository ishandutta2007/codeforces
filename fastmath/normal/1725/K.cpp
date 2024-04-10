#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
#include <array>
#include <functional>
#include <stack>
#include <memory>
using namespace std;

#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define x first
#define y second
#define Time (double)clock()/CLOCKS_PER_SEC

#ifdef LOCAL
#define debug(x) std::cerr << #x << ": " << x << '\n';
#define debug2(x, y) std::cerr << #x << ", " << #y << ": " << x << ", " << y << '\n';
#define debug3(x, y, z) std::cerr << #x << ", " << #y << ", " << #z << ": " << x << ", " << y << ", " << z << '\n';
#else
#define debug(x)
#define debug2(x, y) 
#define debug3(x, y, z) 
#endif

#define FORI(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR(i,a) FORI(i,0,a)
#define ROFI(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ROF(i,a) ROFI(i,0,a)
#define rep(a) FOR(_,a)
#define each(a,x) for (auto& a: x)
#define FORN(i, n) FORI(i, 1, n + 1)

using vi = vector<int>;
template <typename T>
std::istream& operator >>(std::istream& input, std::pair <T, T> & data)
{
    input >> data.x >> data.y;
    return input;
}
template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& data)
{
    for (T& x : data)
        input >> x;
    return input;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const pair <T, T> & data)
{
    output << "(" << data.x << "," << data.y << ")";
    return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& data)
{
    for (const T& x : data)
        output << x << " ";
    return output;
}
std::ostream& operator <<(std::ostream& output, const __int128 &x)
{
    __int128 n = x;
    if (n == 0) {
        output << "0";
        return output;
    }
    if (n < 0) {
        n = -n;
        output << "-";
    }
    string s;
    while (n) {
        s += '0' + (n%10);
        n /= 10;
    }
    reverse(all(s));
    cout << s;
    return output;
}
ll div_up(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll div_down(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down 
ll math_mod(ll a, ll b) { return a - b * div_down(a, b); }
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; 
} // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; 
}
ll gcd(ll a, ll b) {
    while (b) {
        tie(a, b) = mp(b, a % b);
    }
    return a;
}
int Bit(int mask, int bit) { return (mask >> bit) & 1; }
mt19937 rnd(2007);
struct Node {
    int x, y, prop;
    Node *l, *r, *par;
    Node (int x_) {
        par = nullptr;
        x = x_;
        prop = -1;
        y = rnd();
        l = r = nullptr;
    }
};
void gap(Node *t, int val) {
    if (t) {
        t->x = val;
        t->prop = val; 
    }
}
void push(Node *t) {
    if (t->prop != -1) {
        gap(t->l, t->prop);
        gap(t->r, t->prop);
        t->prop = -1;
    }
}
void cut(Node *t) {
    if (t) {
        assert(t->par != nullptr);
        if (t->par->l == t) {
            t->par->l = nullptr;
        }
        else {
            assert(t->par->r == t);
            t->par->r = nullptr;
        }
        t->par = nullptr;        
    }
}
void setLeft(Node *u, Node *c) {
    assert(u->l == nullptr);
    u->l = c;
    if (c) {
        assert(c->par == nullptr);
        c->par = u;
    }
}
void setRight(Node *u, Node *c) {
    assert(u->r == nullptr);
    u->r = c;
    if (c) {
        assert(c->par == nullptr);
        c->par = u;
    }
}
Node *merge(Node *l, Node *r) {
    if (!l) {
        return r;
    }
    if (!r) {
        return l;
    }
    push(l);
    push(r);
    if (l->y < r->y) {
        auto right = l->r;
        cut(right);
        setRight(l, merge(right, r));
        return l;
    }
    else {
        auto left = r->l;
        cut(left);
        setLeft(r, merge(l, left));
        return r;
    }
}
pair <Node*, Node*> split(Node *t, int x) {
    if (!t) {
        return {nullptr, nullptr};
    }
    push(t);
    if (t->x < x) {
        auto right = t->r;
        cut(right);
        auto tmp = split(right, x);
        if (tmp.y) assert(tmp.y->par == nullptr);
        setRight(t, tmp.x);
        return {t, tmp.y};
    }
    else {
        auto left = t->l;
        cut(left);
        auto tmp = split(left, x);
        if (tmp.x) assert(tmp.x->par == nullptr);
        setLeft(t, tmp.y);
        return {tmp.x, t};
    }
}

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    Node *root = nullptr;

    int n;
    cin >> n;
    V <ii> a(n);
    FOR (i, n) {
        cin >> a[i].x;
        a[i].y = i + 1;
    }

    sort(all(a));

    V<Node*> link(n + 1);
    each (e, a) {
        auto u = new Node(e.x);
        link[e.y] = u;
        root = merge(root, u);
    }

    auto pushToRoot = [&] (Node *u) {
        V <Node*> path;
        while (u) {
            path.app(u);
            u = u->par;
        }
        reverse(all(path));
        each (e, path) {
            push(e);
        }
    };

    auto erase = [&] (Node *u) {
        pushToRoot(u);
        if (u == root) {
            auto left = root->l, right = root->r;
            cut(left); cut(right);
            return merge(left, right);
        }
        else {
            auto p = u->par;
            auto left = u->l, right = u->r;
            cut(left); cut(right);
            if (u == p->l) {
                cut(u);
                setLeft(p, merge(left, right));
            }
            else {
                cut(u);
                setRight(p, merge(left, right));
            }
        }
        return root;

    };

    int q;
    cin >> q;
    rep (q) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, w;
            cin >> i >> w;
            pushToRoot(link[i]);
            auto ost = erase(link[i]);
            link[i]->x = w;
            assert(link[i]->l == nullptr);
            assert(link[i]->r == nullptr);
            auto sp = split(ost, w);
            root = merge(merge(sp.x, link[i]), sp.y);
        }
        else if (t == 2) {
            int i;
            cin >> i;
            pushToRoot(link[i]);
            cout << link[i]->x << endl;
        }
        else {
            int l, r;
            cin >> l >> r;
            int m = (l + r) / 2;
            auto sp1 = split(root, l);
            auto sp2 = split(sp1.y, m + 1);
            auto sp3 = split(sp2.y, r + 1);
            if (l == 1) {
                gap(sp2.x, r + 1);
            }
            else {
                gap(sp2.x, l - 1);
            }
            gap(sp3.x, r + 1);
            root = merge(merge(sp1.x, sp2.x), merge(sp3.x, sp3.y));
        }
    }
}