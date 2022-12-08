#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

const int MAXN = 2e5 + 1000;

int cti(const char& c) {
    return static_cast<int>(c) - 97;
}

int qn;
struct STRTRIE {
    int v[MAXN * 17];
    int c[MAXN * 17][26];
    int h[MAXN];
    int NXT;
    
    int nn(const int& p = -1) {
        if(p == -1) {
            v[NXT] = -1;
            for(int i = 0;i < 26;i++) c[NXT][i] = -1;
        } else {
            v[NXT] = v[p];
            for(int i = 0;i < 26;i++) c[NXT][i] = c[p][i];
        }
        return NXT++;
    }
    
    STRTRIE() {
        NXT = 0;
        h[0] = nn();
    }
    
    void add() {
        h[qn] = h[qn-1];
    }
    void revert(int d) {
        h[qn] = h[qn - 1 - d];
    }
    int set(char * s, int sl, int nv) {
        int pv = h[qn-1], cn = h[qn] = nn(pv);
        for(int i = 0;i < sl;i++) {
            if(pv != -1) pv = c[pv][cti(s[i])];
            cn = c[cn][cti(s[i])] = nn(pv);
        }
        v[cn] = nv;
        if(pv != -1) return v[pv]; else return -1;
    }
    int get(char * s, int sl) {
        int cn = h[qn];
        for(int i = 0;i < sl;i++) {
            if(cn == -1) return -1;
            cn = c[cn][cti(s[i])];
        }
        if(cn == -1) return -1;
        return v[cn];
    }
    
} trie1;
struct INTTRIE {
    int v[MAXN * 32];
    int c[MAXN * 32][2];
    int h[MAXN];
    int NXT;
    
    int nn(const int& p = -1) {
        if(p == -1) {
            v[NXT] = 0;
            for(int i = 0;i < 2;i++) c[NXT][i] = -1;
        } else {
            v[NXT] = v[p];
            for(int i = 0;i < 2;i++) c[NXT][i] = c[p][i];
        }
        return NXT++;
    }
    
    INTTRIE() {
        NXT = 0;
        h[0] = nn();
    }
    
    void add() {
        h[qn] = h[qn-1];
    }
    void revert(int d) {
        h[qn] = h[qn - 1 - d];
    }
    void add(const int& a, const int& nv) {
        int pv = h[qn-1], cn = h[qn] = nn(pv);
        for(int i = 30;i >= 0;i--) {
            v[cn] += nv;
            if((a>>i)&1) {
                if(pv != -1) pv = c[pv][1];
                cn = c[cn][1] = nn(pv);
            } else {
                if(pv != -1) pv = c[pv][0];
                cn = c[cn][0] = nn(pv);
            }
        }
        v[cn] += nv;
    }
    void set(const int& a, const int& nv) {
        int pv = h[qn-1], cn = h[qn];
        for(int i = 30;i >= 0;i--) {
            v[cn] += nv;
            if((a>>i)&1) {
                if(pv != -1) pv = c[pv][1];
                
                if(c[cn][1] == -1 or c[cn][1] == pv) cn = c[cn][1] = nn(pv);
                else cn = c[cn][1];
            } else {
                if(pv != -1) pv = c[pv][0];
                
                if(c[cn][0] == -1 or c[cn][0] == pv) cn = c[cn][0] = nn(pv);
                else cn = c[cn][0];
            }
        }
        v[cn] += nv;
    }
    int get(const int& a) {
        int cn = h[qn], r = 0;
        for(int i = 30;i >= 0;i--) {
            assert(cn != -1);
            
            if((a>>i)&1) {
                if(c[cn][0] != -1) r += v[c[cn][0]];
                cn = c[cn][1];
            } else {
                cn = c[cn][0];
            }
        }
        return r;
    }
    
} trie2;

char a[20];
int al;
void sal() {
    for(al = 0;a[al] != '\0';al++);
}
void qset() {
    int x;
    scanf(" %s", a);
    scanf("%d", &x);
    sal();
    
    int p = trie1.set(a, al, x);
    trie2.add(x, 1);
    if(p != -1) trie2.set(p, -1);
}
void qrem() {
    scanf(" %s", a);
    sal();
    
    int p = trie1.set(a, al, -1);
    if(p == -1) trie2.add(); else trie2.add(p, -1);
}
void qqry() {
    scanf(" %s", a);
    sal();
    trie1.add();
    trie2.add();
    
    int p = trie1.get(a, al);
    if(p == -1) printf("-1\n"); else printf("%d\n", trie2.get(p));
    fflush(stdout);
}
void qund() {
    int u;
    scanf("%d", &u);
    trie1.revert(u);
    trie2.revert(u);
}

int Q;

int main() {
    scanf("%d", &Q);
    char ins[20];
    for(qn = 1;qn <= Q;qn++) {
        scanf(" %s", ins);
        if(ins[0] == 's') qset();
        if(ins[0] == 'r') qrem();
        if(ins[0] == 'q') qqry();
        if(ins[0] == 'u') qund();
    }
}