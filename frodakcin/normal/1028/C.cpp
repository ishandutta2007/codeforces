#include <iostream>
#include <cstdio>

#include <cassert>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define mp make_pair

typedef pair<int, pair<int, int> > piii;
#define coord first
#define rind second.first
#define appc second.second

const int MAXN = 140000;

int N;

struct RECT {
    int x1, x2, y1, y2;
    RECT() {
        x1 = x2 = y1 = y2 = -1;
    }
    RECT(int a, int b, int c, int d) {
        x1 = a;
        y1 = b;
        x2 = c;
        y2 = d;
        assert(x1 <= x2 and y1 <= y2);
    }
} rects[MAXN];

template<class T> struct NODE {
public:
    NODE<T> * l;
    NODE<T> * r;
    T val;
    T lazy;
    NODE(T v, T lz) {
        l = nullptr;
        r = nullptr;
        val = v;
        lazy = lz;
    }
    NODE() {
        l = nullptr;
        r = nullptr;
    }
};

struct ST {
    NODE<int> * head;
    int size;
    ST() {
        head = nullptr;
        size = 0;
    }
    ST(int s) {
        head = new NODE<int> (0, 0);
        size = s;
    }
    void prop(NODE<int> * n, int nl, int nr) {
        if(n->lazy == 0) return;
        n->val += n->lazy;
        if(nr - nl > 1) {
            if(n->r == nullptr) n->r = new NODE<int> (0, n->lazy);
            else n->r->lazy += n->lazy;
            if(n->l == nullptr) n->l = new NODE<int> (0, n->lazy);
            else n->l->lazy += n->lazy;
        }
        n->lazy = 0;
    }
    void upd(int gl, int gr, int v) {upd(head, 0, size, gl, gr, v);}
    void upd(NODE<int> * n, int nl, int nr, int gl, int gr, int v) {
        //printf("%d %d %d %d %d\n", nl, nr, gl, gr, v);
        if(gl >= gr or nl >= gr or nr <= gl) return;
        prop(n, nl, nr);
        if(gl <= nl and gr >= nr) {
            n->lazy += v;
            prop(n, nl, nr);
            return;
        }
        assert(nr - nl > 1);
        
        int m = nl + (nr - nl)/2;
        if(gl < m) {
            if(n->l == nullptr) n->l = new NODE<int> (0, 0);
            else prop(n->l, nl, m);
            upd(n->l, nl, m, gl, gr, v);
        }
        if(gr > m) {
            if(n->r == nullptr) n->r = new NODE<int> (0, 0);
            else prop(n->r, m, nr);
            upd(n->r, m, nr, gl, gr, v);
        }
        n->val = max(n->l != nullptr ? n->l->val : 0, n->r != nullptr ? n->r->val : 0);
    }
    int qry() {return qry(head, 0, size, 0, size);}
    int qry(int gl, int gr) {return qry(head, 0, size, gl, gr);}
    int qry(NODE<int> * n, int nl, int nr, int gl, int gr) {
        if(gl >= gr or nl >= gr or nr <= gl) return 0;
        prop(n, nl, nr);
        if(gl <= nl and gr >= nr) return n->val;
        assert(nr - nl > 1);
        
        int m = nl + (nr - nl)/2;
        int ret = 0, t;
        if(gl < m and n->l != nullptr) {
            prop(n->l, nl, m);
            if((t = qry(n->l, nl, m, gl, gr)) > ret) ret = t;
        }
        if(gr > m and n->r != nullptr) {
            prop(n->r, m, nr);
            if((t = qry(n->r, m, nr, gl, gr)) > ret) ret = t;
        }
        return ret;
    }
    int fnd() {return fnd(head, 0, size);}
    int fnd(NODE<int> * n, int nl, int nr) {
        prop(n, nl, nr);
        if(nr - nl == 1) {
            assert(n->val >= N - 1);
            return nl;
        }
        int m = nl + (nr - nl)/2;
        if(n->l != nullptr) {
            prop(n->l, nl, m);
            if(n->l->val >= N - 1) return fnd(n->l, nl, m);
        }
        if(n->r != nullptr) {
            prop(n->r, m, nr);
            if(n->r->val >= N - 1) return fnd(n->r, m, nr);
        }
        return -1;
    }
};

int cpsm[MAXN * 4], cpsl;

void cpsmap(int& a) {
    a = (lower_bound(cpsm, cpsm + cpsl, a) - cpsm);
}

piii slide[MAXN * 2];

int main() {
    scanf("%d", &N);
    cpsl = 0;
    for(int i = 0;i < N;i++) {
        int a[4];
        for(int j = 0;j < 4;j++) scanf("%d", &a[j]);
        a[2]++;
        a[3]++;
        for(int j = 0;j < 4;j++) cpsm[cpsl++] = a[j];
        rects[i] = RECT(a[0], a[1], a[2], a[3]);
    }
    
    sort(cpsm, cpsm + cpsl);
    cpsl = unique(cpsm, cpsm + cpsl) - cpsm;
    
    for(int i = 0;i < N;i++) {
        cpsmap(rects[i].x1);
        cpsmap(rects[i].x2);
        cpsmap(rects[i].y1);
        cpsmap(rects[i].y2);
    }
    
    for(int i = 0;i < N;i++) {
        slide[i * 2] = mp(rects[i].x1, mp(i, 1));
        slide[i * 2 + 1] = mp(rects[i].x2, mp(i, -1));
    }
    
    sort(slide, slide + (N * 2), [](const piii& a, const piii& b){return a.coord < b.coord;});
    
    ST st = ST(N * 4 + 1);
    
    
    bool fa = false;
    int jmp;
    for(int i = 0;i < N * 2;) {
        for(jmp = i + 1; jmp < N * 2 and slide[jmp - 1].coord == slide[jmp].coord; jmp++);
        for(;i < jmp;i++) {
            st.upd(rects[slide[i].rind].y1, rects[slide[i].rind].y2, slide[i].appc);
        }
        if(st.qry() >= N - 1) {
            fa = true;
            printf("%d %d\n", cpsm[slide[i - 1].coord], cpsm[st.fnd()]);
            break;
        }
    }
    
    if(!fa) printf("I didn't find an answer :(\n");
    
    return 0;
}