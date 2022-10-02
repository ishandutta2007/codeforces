#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <bitset>
#include <unordered_map>


using namespace std;


struct matrix
{
    int a[2][2];
    matrix(){}
    matrix(int _a, int _b, int _c, int _d) {
        a[0][0] = _a;
        a[0][1] = _b;
        a[1][0] = _c;
        a[1][1] = _d;
    }
};


const int mod = 1000000007;


matrix operator *(matrix a, matrix b) {
    matrix c(0, 0, 0, 0);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int g = 0; g < 2; g++) {
                c.a[i][j] += (1LL * a.a[i][g] * b.a[g][j]) % mod;
                if (c.a[i][j] >= mod) {
                    c.a[i][j] -= mod;
                }
            }
        }
    } 
    return c;
}


void operator *=(matrix &a, matrix b) {
    a = a * b;
}


bool operator ==(matrix a, matrix b) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (a.a[i][j] != b.a[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}


bool operator !=(matrix a, matrix b) {
    return !(a == b);
}


matrix operator +(matrix a, matrix b) {
    matrix c(0, 0, 0, 0);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c.a[i][j] = a.a[i][j] + b.a[i][j];
            if (c.a[i][j] >= mod) {
                c.a[i][j] -= mod;
            }
        }
    } 
    return c;
}



inline matrix fastpow(matrix a, int n) {
    matrix ans = a;
    n--;
    while (n > 0) {
        if (n & 1) {
            ans *= a;
            n--;
        }
        n >>= 1;
        a *= a;
    }
    return ans;
}


matrix modd[700001];
matrix sum[700001];
matrix base;
matrix null;
matrix neut;
matrix pows[700001];


inline void push(int v) {
    if (modd[v] != neut) {
        sum[v] *= modd[v];
        modd[(v << 1)] *= modd[v];
        modd[(v << 1) + 1] *= modd[v];
        modd[v] = neut; 
    }
}


void add(int v, int vl, int vr, int l, int r, matrix basex) {
    if (vl > r || vr < l) {
        push(v);
        return;
    }
    if (l <= vl && vr <= r) {
        modd[v] *= basex;
        push(v);
        return;
    }
    push(v);
    int vm = (vl + vr) >> 1;
    add((v << 1), vl, vm, l, r, basex);
    add((v << 1) + 1, vm + 1, vr, l, r, basex);
    sum[v] = sum[(v << 1)] + sum[(v << 1) + 1];
}


matrix rmq(int v, int vl, int vr, int l, int r) {
    push(v);
    if (vl > r || vr < l) {
        return null;
    }
    if (l <= vl && vr <= r) {
        return sum[v];
    }
    int vm = (vl + vr) >> 1;
    return rmq((v << 1), vl, vm, l, r) + rmq((v << 1) + 1, vm + 1, vr, l, r);
}


int n, m;
int ss = 1;


int main () {
    null = matrix(0, 0, 0, 0);
    neut = matrix(1, 0, 0, 1);
    base = matrix(1, 1, 1, 0);
    cin >> n >> m;
    while (ss < n) {
        ss *= 2;
    }
    for (int i = 0; i < 2 * ss; i++) {
        modd[i] = neut;
        sum[i] = base; 
    }
    for (int i = ss - 1; i >= 1; i--) {
        sum[i] = sum[i * 2] + sum[i * 2 + 1];
    }
    for (int  i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (a == 1) {
            continue;
        }
        matrix basex = fastpow(base, a - 1);
        add(1, 1, ss, i + 1, i + 1, basex);
    }
    for (int i = 0; i < m; i++) {
        int t, l, r;
        scanf("%d %d %d", &t, &l, &r);
        if (t == 1) {
            int x;
            scanf("%d", &x);
            matrix basex = fastpow(base, x);
            add(1, 1, ss, l, r, basex);
        } else {
            printf("%d\n", rmq(1, 1, ss, l, r).a[0][1]);
        }
    }
    return 0;
}