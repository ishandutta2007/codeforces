#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <set>
#include <stdlib.h>
#include <time.h>

using namespace std;

template <class T>
struct node {
    T sum, val;
    int prior, cnt;
    node * l, * r;
    node() {
        cnt=1;
        prior=(rand()<<16)+rand();
        l=r=NULL;
    }
};

template <class T>
class treap {
    node<T> * root;
    inline T getsum(node<T> * v) {
        if (v) return v->sum;
        else return *(new T);
    }
    inline int getcnt(node<T> * v) {
        if (v) return v->cnt;
        else return 0;
    }
    inline void upd(node<T> * v) {
        if (!v) return;
        v->sum=getsum(v->l)+getsum(v->r)+v->val;
        v->cnt=getcnt(v->l)+getcnt(v->r)+1;
    }
    node<T> * merge(node<T> * v1, node<T> * v2) {
        if (!v1) return v2;
        else if (!v2) return v1;
        if (!(v1->val<v2->val)) swap(v1, v2);
        if (v1->prior>v2->prior) {
            v1->r=merge(v1->r, v2);
            upd(v1);
            return v1;
        } else {
            v2->l=merge(v1, v2->l);
            upd(v2);
            return v2;
        }
    }
    void split(T x, node<T> * tree, node<T> * & l, node<T> * & r) {
        if (!tree) {
            l=NULL, r=NULL;
            return;
        } else {
            if (tree->val<x) {
                split(x, tree->r, l, r);
                tree->r=l;
                upd(tree);
                l=tree;
            } else {
                split(x, tree->l, l, r);
                tree->l=r;
                upd(tree);
                r=tree;
            }
        }
    }
    void insert(node<T> * n, node<T> * & tree) {
        if (!tree) tree=n;
        else {
            if (n->prior>tree->prior) {
                split(n->val, tree, n->l, n->r);
                tree=n;
            }
            else if (n->val<tree->val) insert(n, tree->l);
            else insert(n, tree->r);
            upd(tree);
        }
    }
    void del(T c, node<T> * & tree) {
        if (!tree) return;
        if (!(tree->val<c)&&!(c<tree->val)) {
            node<T> * l=tree->l, * r=tree->r;
            delete tree;
            tree=merge(l, r);
        } else {
            if (c<tree->val) del(c, tree->l);
            else del(c, tree->r);
        }
        upd(tree);
    }
    T getminsum(int cnt, node<T> * tree) {
        if (!tree) return *(new T);
        else if (tree->cnt<=cnt) return tree->sum;
        else {
            T ans;
            ans=ans+getminsum(cnt, tree->l);
            if (cnt>getcnt(tree->l)) ans=ans+tree->val;
            if (cnt>getcnt(tree->l)+1) ans=ans+getminsum(cnt-getcnt(tree->l)-1, tree->r);
            return ans;
        }
    }
    void eraseall(node<T> * tree) {
        if (!tree) return;
        else {
            eraseall(tree->l);
            eraseall(tree->r);
            delete tree;
        }
    }
public:
    inline void insert(T n) {
        node<T> *nn = new node<T>;
        nn->sum=nn->val=n;
        insert(nn, root);
    }
    inline void erase(T n) {
        del(n, root);
    }
    inline T getminsum(int cnt) {
        return getminsum(cnt, root);
    }
    inline void eraseall() {
        eraseall(root);
    }
};

struct cost{
    long long c;
    int i;
    cost(): c(0), i(0) {}
};
inline cost operator+(const cost & a, const cost & b) {
    cost c;
    c.c=a.c+b.c;
    return c;
}
inline bool operator<(const cost & a, const cost & b) {
    if (a.c==b.c) return (a.i<b.i);
    else return (a.c<b.c);
}

const int maxn=300000;

vector<pair<int, pair<int, int> > > levels;
int n, w, taskans[maxn];
treap<cost> tree;

inline void insert(long long a, int b) {
    cost c;
    c.c=a, c.i=b;
    tree.insert(c);
}

int main() {
    cin >> n >> w;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        levels.push_back(make_pair(b, make_pair(a, i)));
    }
    sort(levels.begin(), levels.end());
    long long ans=1LL<<50;
    int maxi=0;
    long long sum=0;
    for (int i=0; i<n; i++) insert(levels[i].second.first, levels[i].second.second);
    for (int i=0; i<=n; i++) {
        if (w<i) break;
        if (w-i<=n) {
            long long summm=tree.getminsum(w-i).c;
            if (ans>sum+summm) ans=sum+summm, maxi=i;
        }
        if (i!=n) {
            cost d;
            d.c=levels[i].second.first, d.i=levels[i].second.second;
            tree.erase(d);
            insert(levels[i].first-levels[i].second.first, levels[i].second.second);
            sum+=d.c;
        }
    }
    tree.eraseall();
    cout << ans << endl;
    set<pair<int, int> > s;
    for (int i=0; i<maxi; i++) taskans[levels[i].second.second]++, s.insert(make_pair(levels[i].first-levels[i].second.first, levels[i].second.second));
    for (int i=maxi; i<n; i++) s.insert(make_pair(levels[i].second.first, levels[i].second.second));
    int j=0;
    for (set<pair<int, int> >::iterator i=s.begin(); i!=s.end()&&j<w-maxi; i++, j++) {
        taskans[i->second]++;
    }
    for (int i=0; i<n; i++) cout << taskans[i];
    return 0;
}