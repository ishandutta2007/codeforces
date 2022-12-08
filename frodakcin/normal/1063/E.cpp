#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

const int MAXN = 1e3 + 100;
int N;
int p[MAXN], rp[MAXN];
char ans[MAXN][MAXN];
bool v[MAXN];

int lvl, C;
bool pd;
bool id(int * a, int as) {
    for(int i = 1;i <= as;i++) if(a[i] != i) return false;
    return true;
}
char get_dir(bool d) {
    return d ? '/' : '\\';
}
char get_dir(int a, int b) {assert(a != b); return get_dir(a < b);}
bool addE(int a, int b) {
    assert(a != b);
    if(a < b) {
        ans[lvl][a] = ans[lvl][b] = '/';
        return true;
    }
    if(a > b) {
        ans[lvl][a] = ans[lvl][b] = '\\';
        return false;
    }
    assert(false);
    return false;
}
void init(int n) {
    assert(p[n] != n);
    v[n] = true;
    C = n;
    for(int i = p[n];i != n;i = p[i]) {
        //printf("%d %d\n", i, p[i]);
        v[i] = true;
        pd = addE(p[i], i);
        lvl--;
    }
}
int addFE(int n, int lf) {
    if((pd) xor (n > C)) {
        ans[lvl][n] = get_dir(p[n], C);
        ans[lf][C] = get_dir(C, n);
        pd = C < n;
        ans[lf][n] = get_dir(C, n);
        return -1;
    }
    if((p[n] < n) xor (n < C)) {
        ans[lvl - 1][C] = get_dir(p[n], C);
        ans[lf][C] = get_dir(C, n);
        ans[lf][n] = get_dir(C, n);
        return -1;
    }
    assert(false);
    return -1;
}
void fill(int n) {
    v[n] = true;
    int l = 1, s = -1;
    for(int i = p[n];i != n;i = p[i]) {
        v[i] = true, l++;
        if(((p[n] < n) xor (C < n)) or (pd xor (n > C))) s = i; 
    }
    //cout << s << "\n";
    //assert(s != -1);
    //lvl++;
    lvl += addFE(s, lvl - l);
    for(int i = p[s];i != s;i = p[i]) {
        addE(p[i], i), lvl--;
    }
}

int main() {
    scanf("%d", &N);
    
    lvl = N;
    pd = false;
    for(int i = 0; i <= N;i++) v[i] = false, p[i] = rp[i] = -1;
    for(int i = 1;i <= N;i++) scanf("%d", rp + i);
    for(int i = 1;i <= N;i++) p[rp[i]] = i;
    //for(int i = 1;i <= N;i++) cerr << p[i] << "\n";
    for(int i = 1;i <= N;i++) for(int j = 1;j <= N;j++) ans[i][j] = '.';
    
    if(id(p, N)) {
        printf("%d\n", N);
        for(int i = 1;i <= N;i++, printf("\n")) for(int j = 1;j <= N;j++) printf("%c", ans[i][j]);
        return 0;
    }
    
    for(int i = 1;i <= N;i++) if(p[i] == i) v[i] = true;
    for(int i = 1, c = 1;c and i <= N;i++) if(!v[i]) init(i), c = 0;
    lvl++;
    //printf("%d %d\n", C, pd);
    for(int i = 1;i <= N;i++) if(!v[i]) fill(i);
    
    printf("%d\n", N - 1);
    for(int i = 1;i <= N;i++, printf("\n")) for(int j = 1;j <= N;j++) printf("%c", ans[i][j]);
    return 0;
}