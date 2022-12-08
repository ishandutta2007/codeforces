#include <cstdio>
#include <iostream>

#include <vector>
#include <queue>

#include <cassert>
#include <ctime>
#include <utility>

using namespace std;

#define pb push_back
typedef vector<int> vi;

typedef queue<int> qu;

const int MAXN = 5e5 + 1000;
const int MAXNL = 25;
const int INF = 1e8 + 1e5;

void printout(char * s, char * e = nullptr) {
    if(e == nullptr) {
        for(;*s != '\0';s++) printf("%c", *s);
    } else {
        for(;s != e;s++) printf("%c", *s);
    }
    printf("\n");
}
char s[MAXN];
int N;

//SUFFIX ARRAY & LCP

int sa[MAXN], isa[MAXN];
int rnk[MAXN][2], nrnk[MAXN];
bool smr(int a, int b) {
    for(int i = 0;i < 2;i++) if(rnk[a][i] != rnk[b][i]) return false;
    return true;
}
vi ctarr[MAXN];
void radixsort(int * arr, const int& mx) {
    for(int r = 1, ctr = 0;r >= 0;r--, ctr = 0) {
        for(int i = 0;i < N;i++) ctarr[rnk[arr[i]][r]].pb(arr[i]);
        for(int i = 0;i <= mx;i++) {
            for(int j = 0;j < ctarr[i].size();j++) arr[ctr++] = ctarr[i][j];
            ctarr[i].assign(0, -1);
        }
        assert(ctr == N);
    }
}

void gsa() {
    for(int i = 0;i < N;i++) sa[i] = i;
    for(int i = 0;i < N;i++) rnk[i][0] = s[i], rnk[i][1] = 0;
    radixsort(sa, 128);
    for(int l = 1, ctr = 0;l < N;l <<= 1) {
        nrnk[sa[0]] = ctr = 1;
        for(int i = 1;i < N;i++) nrnk[sa[i]] = smr(sa[i - 1], sa[i]) ? ctr : ++ctr;
        for(int i = 0;i < N;i++) {
            rnk[i][0] = nrnk[i];
            rnk[i][1] = (i + l < N) ? nrnk[i + l] : 0;
        }
        radixsort(sa, ctr);
    }
    for(int i = 0;i < N;i++) isa[sa[i]] = i;
}

int lcp[MAXN];
void glcp() {
    for(int i = 0, prev = 0;i < N;i++) {
        if(isa[i] == N - 1) {
            lcp[isa[i]] = -1;
            prev = 0;
        } else {
            while(i + prev < N and sa[isa[i] + 1] + prev < N and s[i + prev] == s[sa[isa[i] + 1] + prev]) prev++;
            lcp[isa[i]] = prev;
            if(prev > 0) prev--;
        }
    }
}

//----- ----- -----
//SEGMENT TREE
struct NODE {
    int v;
    NODE * l;
    NODE * r;
    NODE(int a = -1, int b = -1) {l = r = nullptr, v = a;}
};
struct ST {
public:
    NODE * h;
    int s;
    ST() {s = 0, h = nullptr;}
    ST(int sz) {
        s = sz;
        h = new NODE();
    }
    void pout(NODE * n = nullptr, int nl = -1, int nr = -1) {
        if(nr == -1) n = h, nl = 0, nr = s;
        printf("%d %d: (v: %d)\n", nl, nr, n->v);
        if(nr - nl > 1) {
            int m = nl + ((nr - nl)>>1);
            pout(n->l, nl, m);
            pout(n->r, m, nr);
        }
    }
    void init(NODE * n = nullptr, int nl = -1, int nr = -1) {
        if(nr == -1) n = h, nl = 0, nr = s;
        if(nr - nl == 1) {
            n->v = -1;
        }
        if(nr - nl > 1) {
            n->l = new NODE();
            n->r = new NODE();
            int m = nl + ((nr - nl)>>1);
            init(n->l, nl, m);
            init(n->r, m, nr);
            
            n->v = max(n->l->v, n->r->v);
        }
    }
    void upd(int g, int nv) {upd(h, 0, s, g, nv);}
    void upd(NODE * n, int nl, int nr, int g, int nv) {
        assert(g < nr and g >= nl);
        if(nr - nl == 1) {
            n->v = nv;
            return;
        }
        if(nr - nl > 1) {
            int m = nl + ((nr - nl)>>1);
            if(g < m) upd(n->l, nl, m, g, nv);
            if(g >= m) upd(n->r, m, nr, g, nv);
            n->v = max(n->l->v, n->r->v);
        }
    }
    int q(int gl, int gr) {return q(h, 0, s, gl, gr);}
    int q(NODE * n, int nl, int nr, int gl, int gr) {
        if(gl >= gr or nl >= gr or gl >= nr) return -1;
        if(gr >= nr and gl <= nl) return n->v;
        assert(nr - nl > 1);
        if(nr - nl > 1) {
            int m = nl + ((nr - nl)>>1);
            int ret = -1, t;
            if(gl < m) if((t = q(n->l, nl, m, gl, gr)) > ret) ret = t;
            if(gr > m) if((t = q(n->r, m, nr, gl, gr)) > ret) ret = t;
            return ret;
        }
        return -1;
    }
} st;

//----- ----- -----
//SPARSE TABLES

int log2(const int& v) {
    for(int i = 0;i < 30;i++) if((1<<i) > v) return i;
    assert(false);
    return -1;
}
int L[MAXN][MAXNL], R[MAXN][MAXNL];
void init() {
    for(int i = 0;i <= N;i++) for(int j = log2(N) + 1;j >= 0;j--) L[i][j] = R[i][j] = INF;
    for(int i = 1;i < N;i++) L[i][0] = lcp[i - 1];
    for(int i = 0;i < N - 1;i++) R[i][0] = lcp[i];
    for(int i = N - 1, t, en = log2(N);i >= 0;i--) for(int j = 1;j <= en;j++) if(i + (1 << j) < N) R[i][j] = min(R[i][j - 1], R[i + (1 << (j - 1))][j - 1]); else break;
    for(int i = 0, t, en = log2(N);i < N;i++) for(int j = 1;j <= en;j++) if(i - (1 << j) >= 0) L[i][j] = min(L[i][j - 1], L[i - (1 << (j - 1))][j - 1]); else break;
}
int get_L(int l, const int& mn) {
    for(int i = log2(N);i >= 0;i--) if(L[l][i] != INF and L[l][i] >= mn) l -= (1 << i);
    return l;
}
int get_R(int l, const int& mn) {
    for(int i = log2(N);i >= 0;i--) if(R[l][i] != INF and R[l][i] >= mn) l += (1 << i);
    return l + 1;
}

//----- ----- -----

int dp[MAXN];
qu ins;

int main() {
    clock_t timer = clock();
    
    scanf("%d", &N);
    scanf(" %s", s);
    
    gsa();
    glcp();
    
    //for(int i = 0;i < N;i++) printf("%d ", lcp[i]), printout(s + sa[i]);
    
    st = ST(N);
    st.init();
    //st.pout();
    
    init();
    //for(int i = 0;i < N;i++) for(int j = 0;j < log2(N);j++) printf("R[%d][%d] = %d\n", i, j, R[i][j]);
    
    for(int i = 0;i <= N;i++) dp[i] = -1;
    dp[N] = 0;
    
    int t;
    for(int i = N - 1, j = N;i >= 0;i--) {
        dp[i] = dp[i + 1] + 1;
        for(;dp[i] > 0;dp[i]--, j--) {
            assert(i + dp[i] == j);
            while(!ins.empty() and ins.front() >= j) {
                int a = ins.front();
                ins.pop();
                st.upd(isa[a], dp[a]);
                //printf("u: %d %d %d %d %d\n", i, dp[i], a, isa[a], dp[a]);
                //st.pout();
            }
            
            if(dp[i] == 1) {
                ins.push(i);
                //printf("%d:   pos: %d   dp: %d\n", i, i - 1, dp[i]);
                break;
            }
            
            //printf("%d %d %d %d %d\n", i, isa[i], dp[i] - 1, get_L(isa[i], dp[i] - 1), get_R(isa[i], dp[i] - 1));
            int v = st.q(get_L(isa[i], dp[i] - 1), get_R(isa[i], dp[i] - 1));
            if((t = st.q(get_L(isa[i+1], dp[i] - 1), get_R(isa[i+1], dp[i] - 1))) > v) v = t;
            if(v >= dp[i] - 1) {
                ins.push(i);
                //printf("%d:   pos: %d   dp: %d\n", i, i - 1, dp[i]);
                break;
            }
        }
        //printf("dp[%d] = %d\n", i, dp[i]);
    }
    
    int ans = 0;
    for(int i = 0, t;i < N;i++) if((t = dp[i]) > ans) ans = t;
    printf("%d\n", ans);
    
    bool dominance = true;
    assert(dominance);
    
    cerr << (clock() - timer) * 1.0/CLOCKS_PER_SEC << " seconds\n";
    
    return 0;
}