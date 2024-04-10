#pragma GCC optimize("Ofast")
#pragma optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

typedef long long ll;

using namespace std;

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());

struct vec {
    ll x = 0, y = 0;
    vec()= default;
    vec(ll _x, ll _y) {
        x = _x;
        y = _y;
    }
    vec(vec const &pt) {
        x = pt.x;
        y = pt.y;
    }
    void read () {
        cin >> x >> y;
    }
    void write () {
        cout << '(' << x << ", " << y << ')' << '\n';
    }
    vec operator - (vec a) {
        return { x - a.x, y - a.y };
    }
    ll operator % (vec a)  {
        return (x * a.y - y * a.x);
    }
    bool belong_to_angle(vec a, vec b, vec o) {
        vec p = {x, y};
        if ((b - o) % (p - o) >= 0 && (p - o) % (a - o) >= 0 && (b - o) % (a - o) >= 0) return true;
        return (b - o) % (p - o) <= 0 && (p - o) % (a - o) <= 0 && (b - o) % (a - o) <= 0;
    }
};

bool mda = true;

struct node {
    vec x;
    ll y, sz;
    node *l, *r;
    node() {}
    node(vec _x) {
        x = _x;
        y = gen();
        sz = 1;
        l = r = nullptr;
    }
    static ll get_size(node *p) {
        return p ? p->sz : 0;
    }
    static void upd_size(node *p) {
        p->sz = 1 + get_size(p->l) + get_size(p->r);
    }
    static pair <node*, node*> split(node *p, ll x) {
        if (!p) return {};
        if (get_size(p->l) + 1 <= x) {
            pair <node*, node*> q = split(p->r, x - get_size(p->l) - 1);
            p->r = q.first;
            upd_size(p);
            return { p, q.second };
        }
        pair <node*, node*> q = split(p->l, x);
        p->l = q.second;
        upd_size(p);
        return { q.first, p };
    }
    static node* merge(node *l, node *r) {
        if (!l) return r;
        if (!r) return l;
        if (l->y > r->y) {
            l->r = merge(l->r, r);
            upd_size(l);
            return l;
        }
        r->l = merge(l, r->l);
        upd_size(r);
        return r;
    }
    static void insert(vec pt, ll x, node* &root) {
        pair <node*, node*> q = split(root, x);
        node *t = new node(pt);
        root = merge(q.first, merge(t, q.second));
    }
    static node* cut(ll l, ll r, node* &root) {
        if (l > r) return {};
        pair <node*, node*> q1 = split(root, r);
        pair <node*, node*> q2 = split(q1.first, l - 1);
        root = merge(q2.first, q1.second);
        return q2.second;
    }
    static void paste(node* p, ll pos, node* &root) {
        pair <node*, node*> q = split(root, pos - 1);
        root = merge(q.first, merge(p, q.second));
    }
    static vec get(ll pos, node *root) {
        if (mda) pos++;
        mda = false;
        if (get_size(root->l) + 1 == pos) {
          mda = true;
          return root->x;
        }
        if (get_size(root->l) < pos)
          return get(pos - get_size(root->l) - 1, root->r);
        return get(pos, root->l);
    }
    static void write(node* p) {
        if (!p) return;
        write(p->l);
        p->x.write();
        write(p->r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    node *T = 0;
    int q;
    cin >> q;
    q -= 3;
    {
        int n = 3;
        vector <vec> kek(3);
        for (int i = 0; i < 3; i++) {
            int tmp;
            cin >> tmp;
            kek[i].read();
        }
        if ((kek[1] - kek[0]) % (kek[2] - kek[0]) < 0)
            swap(kek[0], kek[2]);
        for (int i = 0; i < 3; i++)
            node::insert(kek[i], i + 1, T);
    }
    vector <vec> a(T->sz + q + 1);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int n = T->sz;
            vec Point{};
            Point.read();
            bool flag = true;
            {
              int left = 1, right = n - 1;
              vec x = node::get(0, T);
              if (!Point.belong_to_angle(node::get(n - 1, T), node::get(1, T), x)) {
                  flag = false;
              }
              else {
                  while (left + 1 != right) {
                      int middle = (left + right) / 2;
                      if (Point.belong_to_angle(node::get(left, T), node::get(middle, T), x))
                          right = middle;
                      else
                          left = middle;
                  }
                  a[left] = node::get(left, T), a[right] = node::get(right, T);
                  if ((Point.belong_to_angle(x, a[left], a[right])) && (Point.belong_to_angle(x, a[right], a[left])))
                      flag = true;
                  else
                      flag = false;
              }
            }
            if (flag) continue;
            int Left, Right;
            bool kek = false;
            vec Line{};
            a[n - 1] = node::get(n - 1, T);
            a[1] = node::get(1, T);
            a[0] = node::get(0, T);
            if (Point.belong_to_angle(a[n - 1], a[1], a[0]))
                Line = Point - a[0];
            else {
                Line = a[0] - Point;
                kek = true;
            }
            int L = 0, R = n - 1;
            while (L != R) {
                int M = (L + R + 1) / 2;
                a[M] = node::get(M, T);
                if (Line % (a[M] - a[0]) > 0) R = M - 1;
                else L = M;
            }
            int Middle = L;
            int L1 = 0, R1 = Middle;
            int L2 = Middle, R2 = n;
            a[Middle] = node::get(Middle, T);
            if (Line % (a[Middle] - a[0]) == 0) R1--, L2++;
            if (kek) swap(L1, L2), swap(R1, R2);
            while (L1 < R1) {
                int M = (L1 + R1 + 1) / 2;
                a[M % n] = node::get(M % n, T);
                a[(M - 1 + n) % n] = node::get((M - 1 + n) % n, T);
                if ((a[M % n] - a[(M - 1 + n) % n]) % (a[M % n] - Point) > 0) R1 = M - 1;
                else L1 = M;
            }
            Left = L1;
            while (L2 < R2) {
                int M = (L2 + R2 + 1) / 2;
                a[M % n] = node::get(M % n, T);
                a[(M - 1 + n) % n] = node::get((M - 1 + n) % n, T);
                if ((a[M % n] - a[(M - 1 + n) % n]) % (a[M % n] - Point) < 0) R2 = M - 1;
                else L2 = M;
            }
            Right = L2;
            Left %= n, Right %= n;
            if (Left < Right) {
                node::cut(Left + 2, Right, T);
                node::insert(Point, Left + 1, T);
                continue;
            }
            node::cut(Left + 2, n, T);
            node::cut(1, Right, T);
            node::insert(Point, 0, T);
        }
        else {
            int n = T->sz;
            vec Point{};
            Point.read();
            int left = 1, right = n - 1;
            vec x = node::get(0, T);
            if (!Point.belong_to_angle(node::get(n - 1, T), node::get(1, T), x)) {
                cout << "NO\n";
            }
            else {
                while (left + 1 != right) {
                    int middle = (left + right) / 2;
                    if (Point.belong_to_angle(node::get(left, T), node::get(middle, T), x))
                        right = middle;
                    else
                        left = middle;
                }
                a[left] = node::get(left, T), a[right] = node::get(right, T);
                if ((Point.belong_to_angle(x, a[left], a[right])) && (Point.belong_to_angle(x, a[right], a[left])))
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
    }
    return 0;
}