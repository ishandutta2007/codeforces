#include<bits/stdc++.h>
using namespace std;
#define int long long
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
mt19937 rnd(2007);
struct DD {
    //check overflow
    struct Node {
        int cnt, x, y;
        int sum;
        Node *l, *r;
        Node (int x_) {
            x = sum = x_;
            cnt = 1;
            y = rnd();
            l = r = NULL;
        }   
    } *root;  
    void print_tree(Node *t) {
        if (!t)
            return;

        cout << t->x << ", ";
        if (t->l)
            cout << "l : " << t->l->x << ", ";
        else
            cout << "l : NULL, ";
        if (t->r)
            cout << "r : " << t->r->x;
        else
            cout << "r : NULL";
        cout << '\n';

        print_tree(t->l);
        print_tree(t->r);
    }   
    void print_list(Node *t) {
        if (!t)
            return;
        print_list(t->l);
        cout << t->x << ' ';
        print_list(t->r);
    }   
    int sum(Node *t) {
        if (!t)
            return 0;
        else
            return t->sum;
    }   
    int cnt(Node *t) {
        if (!t)
            return 0;
        else
            return t->cnt;
    }   
    void relax(Node *t) {
        t->sum = sum(t->l) + sum(t->r) + t->x;
        t->cnt = cnt(t->l) + cnt(t->r) + 1;
    }   
    Node *merge(Node *l, Node *r) {
        if (!l)
            return r;
        if (!r)
            return l;
        if (l->y < r->y) {
            l->r = merge(l->r, r);
            relax(l);
            return l;
        }   
        else {
            r->l = merge(l, r->l);
            relax(r);
            return r;
        }       
    }   
    pair <Node*, Node*> split(Node *t, int x) {
        if (!t)
            return {NULL, NULL};
        if (t->x < x) {
            auto tmp = split(t->r, x);
            t->r = tmp.f;
            relax(t);
            return mp(t, tmp.s);
        }   
        else {
            auto tmp = split(t->l, x);
            t->l = tmp.s;
            relax(t);
            return mp(tmp.f, t);
        }   
    }   
    pair <Node*, Node*> splitcnt(Node *t, int k) {
        if (!t)
            return {NULL, NULL};
        if (k <= cnt(t->l)) {
            auto tmp = splitcnt(t->l, k);
            t->l = tmp.s;
            relax(t);
            return mp(tmp.f, t);
        }   
        else {
            auto tmp = splitcnt(t->r, k - cnt(t->l) - 1);
            t->r = tmp.f;
            relax(t);
            return mp(t, tmp.s);
        }   
    }   
    void init() {
        root = NULL;
    }
    void add(int x) {
        auto t = split(root, x);
        root = merge(merge(t.f, new Node(x)), t.s);        
    }   
    void del(int x) {
        auto t1 = split(root, x);
        auto t2 = split(t1.s, x + 1);
        root = merge(merge(t1.f, merge(t2.f->l, t2.f->r)), t2.s);
    }   
    int sum_less(int x) {
        auto t = split(root, x);
        int ans = sum(t.f);
        root = merge(t.f, t.s);
        return ans;
    }   
    int sum_pref(int k) {
        auto t = splitcnt(root, k);
        int ans = sum(t.f);
        root = merge(t.f, t.s);
        return ans;
    }   
    int cnt() {
        return cnt(root);
    }   
    void print_tree() {
        print_tree(root);
        cout << '\n';
    }   
    void print_list() {
        print_list(root);
        cout << '\n';
    }   
    int getk(Node *t, int i) {
        int lf = cnt(t->l);
        if (lf == i)
            return t->x;
        if (i < lf)
            return getk(t->l, i);
        else
            return getk(t->r, i - lf - 1);
    }
    //0 - indexed
    int getk(int i) {
        return getk(root, i);
    }
} ta, tb;  
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    int sum = 0, suma = 0, sumb = 0, cnt = 0;
    while (n--) {
        int t, d;
        cin >> t >> d;
        sum += d;
        if (t == 0) {
            suma += d;
            if (d < 0) {
                ta.del(-d);
            }
            else {
                ta.add(d);
            }
        }   
        else {
            sumb += d;
            if (d < 0) {
                tb.del(-d);
            }
            else {
                tb.add(d);
            }
        }   
        
        if (cnt)
            cnt--;
        if (ta.cnt() && tb.cnt())
            cnt = max(cnt, 1ll);
        while (cnt < ta.cnt() && cnt < tb.cnt() && ta.getk(ta.cnt() - cnt - 1) > tb.getk(cnt)) 
            cnt++;

        if (!tb.cnt()) {
            cout << sum << endl;
        }
        else if (cnt == 0) {
            cout << sum + sumb - tb.getk(0) << endl;
        }   
        else {
            cout << sum + sumb - tb.sum_pref(cnt) + (suma - ta.sum_pref(ta.cnt() - cnt)) << endl;
        }   
    }
}