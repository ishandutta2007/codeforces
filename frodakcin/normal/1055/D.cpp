#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

void no_answer() {
    printf("NO\n");
    exit(0);
}
void printout(char * i, char * f = nullptr) {
    if(f != nullptr) for(;i!=f;i++) printf("%c", *i);
    else for(;(*i)!='\0';i++) printf("%c", *i);
    printf("\n");
}

const int MAXN = 3e3 + 100;
const int MAXL = 3e3 + 100;

bool execute(char * c, char * d, int& cl, int * ans) {
    ans[0] = ans[1] = -1;
    for(int i = 0, j = 0;i < cl;i++) {
        if(c[i] != d[i]) {
            if(j == 0) j = 1, ans[0] = i;
            ans[1] = i;
        }
    }
    if(ans[0] == -1) return false;
    ans[1]++;
    return true;
}
bool fit(char * a, char * b, int& cl, int * dat, char * aa, char * ab, int * ans) {
    dat[0] = dat[1] = -1;
    for(int i = 0, f = 0;i < cl;i++) {
        if(a[i] != b[i]) {
            if(f == 0) {
                
                dat[0] = i;
                for(int j = 0;ans[0] + j < ans[1];j++, i++) {
                    if(i >= cl or a[i] != aa[ans[0] + j] or b[i] != ab[ans[0] + j]) no_answer();
                }
                dat[1] = i--;
                
                f = 1;
            } else no_answer();
        }
    }
    if(dat[0] == -1) return false;
    assert(dat[1] - dat[0] == ans[1] - ans[0]);
    return true;
}
int f[MAXN], pl;
void generate_fail(char * s, const int &sl) {
    pl = sl, f[0] = 0;
    for(int i = 1;i < pl;i++) {
        f[i] = f[i-1];
        while(f[i] != 0 and s[i] != s[f[i]]) f[i] = f[f[i] - 1];
        if(s[f[i]] == s[i]) assert(++f[i] <= i);
    }
}
bool check(char * p, char * s, const int& sl) {
    for(int i = 0, j = 0;i < sl;i++) {
        while(j != 0 and p[j] != s[i]) j = f[j - 1];
        if(p[j] == s[i]) j++;
        if(j == pl) return true;
    }
    return false;
}

int N;
char w[MAXN][MAXL];
char w2[MAXN][MAXL];
int loc[MAXN][2];
int L[MAXN];

int sub[MAXN][2];
int ans[2];
int al;

int B;

bool extend_left() {
    if(ans[0] == 0) return false;
    for(int i = 0;i < N;i++) {
        if(loc[i][0] == -1) continue;
        if(loc[i][0] == 0 or w[i][loc[i][0] - 1] != w[B][ans[0] - 1] or w2[i][loc[i][0] - 1] != w2[B][ans[0] - 1]) return false;
    }
    ans[0]--;
    for(int i = 0;i < N;i++) if(loc[i][0] != -1) loc[i][0]--;
    return true;
}
bool extend_right() {
    if(ans[1] == L[B]) return false;
    for(int i = 0;i < N;i++) {
        if(loc[i][1] == -1) continue;
        if(loc[i][1] == L[i] or w[i][loc[i][1]] != w[B][ans[1]] or w2[i][loc[i][1]] != w2[B][ans[1]]) return false;
    }
    ans[1]++;
    for(int i = 0;i < N;i++) if(loc[i][1] != -1) loc[i][1]++;
    return true;
}

int main() {
    scanf("%d", &N);
    for(int i = 0;i < N;i++) scanf(" %s", w[i]);
    for(int i = 0;i < N;i++) scanf(" %s", w2[i]);
    
    for(int i = 0;i < N;i++) 
        for(L[i] = 0;w[i][L[i]] != '\0';L[i]++);
    
    for(B = 0;!execute(w[B], w2[B], L[B], loc[B]);B++) assert(B + 1 < N);
    assert((ans[1] = loc[B][1]) > (ans[0] = loc[B][0]));
    loc[B][0] = ans[0], loc[B][1] = ans[1];
    for(int i = B + 1;i < N;i++) fit(w[i], w2[i], L[i], loc[i], w[B], w2[B], ans);
    
    while(extend_left()) assert(ans[0] >= 0);
    while(extend_right()) assert(ans[1] <= L[B]);
    
    generate_fail(w[B] + ans[0], ans[1]-ans[0]);
    for(int i = 0;i < N;i++) if(check(w[B] + ans[0], w[i], loc[i][1] == -1 ? L[i] : loc[i][1] - 1)) no_answer();
    
    printf("YES\n");
    printout(w[B] + ans[0], w[B] + ans[1]);
    printout(w2[B] + ans[0], w2[B] + ans[1]);
    
    return 0;
}