#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

#define ti(x) static_cast<int>(x)
typedef long long ll;
#define tll(x) static_cast<ll>(x)

//grid 5000 = 1

const int S1 = 4000;
const int S0 = 3;
const int TMP1 = 4999;
const int TMP2 = 4998;
const int MAXD = 10 + 5;
int D, P;

const int MAXC = 5e3 + 50;
int cell[MAXC];

int log2(int v) {
    int r;
    for(r = 0;v != 0;r++) {
        if((1 << r) >= v) return r;
        if(v&(1 << r)) v -= (1 << r);
    }
    return -1;
}
int sum(int a, int b) {
    return (a + b)%P;
}
int dif(int a, int b) {
    return (a - b + P)%P;
}
int prod(int a, int b) {
    return ti((tll(a)*b)%P);
}
int pow(int b, int p) {
    assert(p >= 0);
    if(b == 1 or p == 0) return 1;
    if(b == 0) return 0;
    int ret = 1;
    for(;p;p>>=1, b=prod(b, b)) if(p&1) ret=prod(ret, b);
    return ret;
}
int divi(int a, int b) {
    return prod(a, pow(b, P - 2));
}
void addV(int a, int b, int c) {
    assert(c > 2);
    printf("+ %d %d %d\n", a, b, c);
    cell[c] = sum(cell[a], cell[b]);
}
void expD(int a, int b) {
    assert(b > 3);
    printf("^ %d %d\n", a, b);
    cell[b] = pow(cell[a], D);
}
void init0(int l) {
    int t = log2(P);
    addV(l, S1 + t, l);
    for(int i = t - 1;i > 0;i--) {
        if(P&(1 << i)) addV(l, S1 + i, l);
    }
}
void setC(int l, int c) {
    assert(c >= 0);
    if(c == 1) return addV(S0, S1, l);
    if(c == 2) return addV(S1, S1, l);
    addV(S0, S0, l);
    int test = 0;
    for(int i = log2(c);i >= 0;i--) if(c&(1 << i)) addV(l, S1 + i, l), test += (1 << i);
    assert(test == c);
}
void setC(int l, int c, int v) {       //m[l] = c, or c * m[v]
    assert(c >= 0 and l != v);
    if(c == 0) return addV(S0, S0, l);
    if(c == 1) return addV(S0, v, l);
    if(v == S1) return setC(l, c);
    addV(v, v, l);
    int test = 2;
    for(int i = log2(c) - 1, f = 0;i >= 0;i--, f = 1) {
        if(f) addV(l, l, l), test*=2;
        if((1 << i)&c) addV(l, v, l), test++;
    }
    assert(cell[l] == prod(c, cell[v]));
    assert(test == c);
}

void subV(int a, int b, int c = -1) {
    if(c == -1) c = a;
    setC(TMP1, P - 1, b);
    addV(a, TMP1, c);
}
void addC(int a, int b, int c = -1) {
    if(c == -1) c = a;
    else addV(a, S0, c);
    assert(cell[S0] == 0);
    assert(cell[c] == cell[a]);
    for(int i = log2(b);i >= 0;i--) if(b&(1 << i)) addV(c, S1 + i, c);
}
void subC(int a, int b, int c = -1) {
    addC(a, P - b, c);
}
void multC(int a, int b, int c = -1) {
    int o = cell[a];
    if(c == -1) {
        c = a;
        setC(TMP1, b, a);
        setC(a, 1, TMP1);
    } else setC(c, b, a);
    assert(cell[c] == prod(o, b));
}
void divC(int a, int b, int c = -1) {
    if(c == -1) {
        setC(TMP1, pow(b, P - 2), a);
        setC(a, 1, TMP1);
    } else setC(c, pow(b, P - 2), a);
}

int bin[MAXD][MAXD];
void squ(int l, int tp, int f) {
    int m[MAXD][MAXD], inv[MAXD][MAXD], mo[MAXD][MAXD];
    for(int i = 0;i <= D;i++) for(int j = 0;j <= D;j++) mo[i][j] = m[i][j] = prod(bin[D][j], pow(i, j)), inv[i][j] = i == j;
    //for(int i = 0;i <= D;i++, cerr << '\n') for(int j = 0;j <= D;j++) cerr << m[i][j] << ' ';
    for(int i = 0;i <= D;i++) {
        int v = pow(m[i][i], P - 2);
        for(int j = 0;j <= D;j++) {
            m[i][j] = prod(m[i][j], v);
            inv[i][j] = prod(inv[i][j], v);
        }
        for(int j = 0;j <= D;j++) {
            if(j == i) continue;
            int w = m[j][i];
            for(int k = 0;k <= D;k++) {
                m[j][k] = dif(m[j][k], prod(w, m[i][k]));
                inv[j][k] = dif(inv[j][k], prod(w, inv[i][k]));
            }
        }
    }
    //Checking Answer ---------------------
    for(int i = 0;i <= D;i++) for(int j = 0;j <= D;j++) {
        int v = 0;
        for(int k = 0;k <= D;k++) v = sum(v, prod(mo[i][k], inv[k][j]));
        assert(v == static_cast<int>(i == j));
    }
    //-------------------------------------
    setC(f, 0);
    for(int i = 0;i <= D;i++) {
        addC(l, i, tp);
        assert(sum(cell[l], i) == cell[tp]);
        expD(tp, tp);
        assert(pow(sum(cell[l], i), D) == cell[tp]);
        multC(tp, inv[D - 2][i]);
        assert(prod(pow(cell[l] + i, D), inv[D - 2][i]) == cell[tp]);
        addV(f, tp, f);
        
        //cerr << cell[f] << "\n";
    }
}

int main() {
    scanf("%d%d", &D, &P);
    
    for(int i = 0;i < MAXC;i++) cell[i] = 1;
    cell[1] = 0;
    cell[2] = 0;
    
    for(int i = 0;i <= D;i++) for(int j = 0;j <= D;j++) bin[i][j] = 0;
    for(int i = 0, j;i <= D;i++) for(bin[i][0] = bin[i][i] = 1, j = 1;j < i;j++) bin[i][j] = bin[i - 1][j - 1] + bin[i - 1][j];

    for(int i = S1;i < S1 + 33;i++) addV(i, i, i + 1);
    //for(int i = 0;i < 10;i++) assert((1 << i)%P == pow(2, i));
    //for(int i = 0;i < 10;i++) assert(cell[S1 + i] == (1 << i)%P);
    init0(S0);        //sets 0 to position S0 (3)
    
    squ(1, 1000, 100);
    squ(2, 1000, 101);
    addV(1, 2, 102);
    squ(102, 1000, 103);
    addV(100, 101, 104);
    subV(103, 104, 105);
    divC(105, 2, 106);
    printf("f 106\n");
    
    //cerr << cell[100] << endl;
    //cerr << cell[101] << endl;
    //cerr << cell[103] << endl;
    //cerr << cell[106] << endl;
    
    assert(cell[106] == prod(cell[1], cell[2]));
    
    return 0;
}