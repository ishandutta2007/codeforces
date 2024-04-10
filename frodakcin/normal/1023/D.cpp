#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 202000;
const int MAXQ = 202000;

int N, Q;

struct NODE {
    NODE * l;
    NODE * r;
    int val;
    bool lazy;
    NODE() {
        l = nullptr;
        r = nullptr;
        val = 0;
        lazy = false;
    }
    NODE(int a, bool b) {
        val = a;
        lazy = b;
        l = nullptr;
        r = nullptr;
    }
};
struct ST {
    NODE * head;
    ST() {
        head = new NODE(0, false);
    }
    void prop(NODE * n, int nl, int nr) {
        if(!n->lazy) return;
        if(nr - nl == 1) n->lazy = false;
        else 
        {
            if(n->l == nullptr) n->l = new NODE(n->val, true);
            else n->l->val = n->val, n->l->lazy = true;
            if(n->r == nullptr) n->r = new NODE(n->val, true);
            else n->r->val = n->val, n->r->lazy = true;
            
            n->lazy = false;
        }
    }
    void update(int gl, int gr, int nv) {update(head, 0, N, gl, gr, nv);}
    void update(NODE * n, int nl, int nr, int gl, int gr, int nv) {
        
        prop(n, nl, nr);
        if(gl >= gr or gr < nl or gl > nr) return;
        if(gl <= nl and gr >= nr) {
            n->val = nv;
            n->lazy = true;
            return;
        }
        int mid = nl + (nr - nl)/2;
        if(gl < mid) {
            if(n->l == nullptr) n->l = new NODE(0, false);
            update(n->l, nl, mid, gl, gr, nv);
        }
        if(gr > mid) {
            if(n->r == nullptr) n->r = new NODE(0, false);
            update(n->r, mid, nr, gl, gr, nv);
        }
        
    }
    int query(int gl, int gr) {return query(head, 0, N, gl, gr);}
    int query(NODE * n, int nl, int nr, int gl, int gr) {
        
        prop(n, nl, nr);
        if(gl >= gr or gr < nl or gl > nr) return -1;
        if(gl <= nl and gr >= nr) {
            return n->val;
        }
        int mid = nl + (nr-nl)/2;
        if(gl < mid) return n->l == nullptr ? 0 : query(n->l, nl, mid, gl, gr);
        if(gr > mid) return n->r == nullptr ? 0 : query(n->r, mid, nr, gl, gr);
        return -1;
        
    }
};

int ofarr[MAXN];
int farr[MAXN];     //final arr
int fapp[MAXN], lapp[MAXN];     //first appearance, last appearance

int main() {
    scanf("%d%d", &N, &Q);
    for(int i = 0;i < N;i++) {
        scanf("%d", &farr[i]);
    }
    for(int i = 0;i <= Q;i++) fapp[i] = lapp[i] = -1;
    for(int i = 0;i < N;i++) {
        if(fapp[farr[i]] == -1) fapp[farr[i]] = i;
        lapp[farr[i]] = i;
    }
    
    ST st;
    for(int i = 1;i <= Q;i++) {
        if(lapp[i] == -1) continue;
        st.update(fapp[i], lapp[i] + 1, i);
    }
    
    for(int i = 0;i < N;i++) {
        ofarr[i] = st.query(i, i + 1);
    }
    
    int ri = -1;
    bool ans = true;
    for(int i = 0;i < N;i++) {
        if(ofarr[i] == 0) ofarr[i] = farr[i];
        if(ofarr[i] == 0) ofarr[i] = ri;
        else if(ri == -1) for(int j = 0;j < i;j++) ofarr[j] = ofarr[i];
        if(ofarr[i] != 0) ri = ofarr[i];
        
        if(farr[i] != 0 and ofarr[i] != farr[i]) {ans = false; break;}
    }
    
    bool qapp = lapp[Q] >= 0;
    if(!qapp)
    {
        for(int i = 0;i < N;i++){
            if(farr[i] == 0) {
                qapp = true;
                ofarr[i] = Q;
                break;
            }
        }
    }
    
    if(!ans or !qapp) {
        printf("NO\n");
    } else {
        printf("YES\n");
        for(int i = 0;i < N;i++) printf("%d ", (ofarr[i] == -1 ? 1 : ofarr[i]));
        printf("\n");
    }
    return 0;
}