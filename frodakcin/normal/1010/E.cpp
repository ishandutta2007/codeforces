#include <iostream>
#include <cstdio>

#include <algorithm>

using namespace std;

const int INF = 1000000000;

const int MAXX = 101000;
const int MAXY = 101000;
const int MAXZ = 101000;
const int MAXN = 101000;
const int MAXM = 101000;
const int MAXK = 101000;

int X, Y, Z, N, M, K;

struct ST {
    int l;
    int r;
    int m[3];
    int lo[3];
    int hi[3];
} st[MAXN];

int t1[3], t2[3], C, h, sr[MAXM];
bool open(int * a) {
    return (t1[0] <= a[0] && a[0] <= t2[0]) and (t1[1] <= a[1] && a[1] <= t2[1]) and (t1[2] <= a[2] && a[2] <= t2[2]);
}
bool cmp(int a, int b) {
    for(int i = 0;i < 3;i++) if(st[a].m[(C + i)%3] != st[b].m[(C + i)%3]) return st[a].m[(C + i)%3] < st[b].m[(C + i)%3];
    return false;
}
void sil(int& a, int b) {
    if(b < a) a = b;
}
void siL(int& a, int b) {
    if(b > a) a = b;
}

bool build(int& x, int l, int r, int c) {
    if(l > r) {x = -1; return false;}
    int mid = l + (r - l)/2;
    C = c%3;
    nth_element(sr + l, sr + mid, sr + r + 1, cmp);
    x = sr[mid];
    if(build(st[x].l, l, mid-1, c+1)) for(int i = 0;i < 3;i++) {sil(st[x].lo[i], st[st[x].l].lo[i]); siL(st[x].hi[i], st[st[x].l].hi[i]);}
    if(build(st[x].r, mid+1, r, c+1)) for(int i = 0;i < 3;i++) {sil(st[x].lo[i], st[st[x].r].lo[i]); siL(st[x].hi[i], st[st[x].r].hi[i]);}
    return true;
}
bool enc(int * l, int * L, int stv) {       //stv is completely enclosed by l, L
    for(int i = 0;i < 3;i++) if(l[i] > st[stv].lo[i] || L[i] < st[stv].hi[i]) return false;
    return true;
}
bool encd(int * l, int * L, int stv) {
    for(int i = 0;i < 3;i++) if(l[i] > st[stv].m[i] || L[i] < st[stv].m[i]) return false;
    return true;
}
bool ot(int * l, int * L, int stv) {       //l, L is out of the range covered by stv
    for(int i = 0;i < 3;i++) if(l[i] > st[stv].hi[i] || L[i] < st[stv].lo[i]) return true;
    return false;
}
bool q(int x, int * l, int * L) {
    if(x == -1) return false;
    if(encd(l, L, x)) return true;
    if(ot(l, L, x)) return false;
    return q(st[x].l, l, L) or q(st[x].r, l, L);
}

int main() {
    scanf("%d%d%d%d%d%d", &X, &Y, &Z, &N, &M, &K);
    
    t1[0] = t1[1] = t1[2] = INF;
    t2[0] = t2[1] = t2[2] = 0;
    
    for(int i = 0;i < N;i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if(a < t1[0]) t1[0] = a; if(a > t2[0]) t2[0] = a;
        if(b < t1[1]) t1[1] = b; if(b > t2[1]) t2[1] = b;
        if(c < t1[2]) t1[2] = c; if(c > t2[2]) t2[2] = c;
    }
    for(int i = 0;i < M;i++) {
        scanf("%d%d%d", &st[i].m[0], &st[i].m[1], &st[i].m[2]);
        if(open(st[i].m)) {
            printf("INCORRECT\n");
            return 0;
        }
        st[i].lo[0] = st[i].hi[0] = st[i].m[0];
        st[i].lo[1] = st[i].hi[1] = st[i].m[1];
        st[i].lo[2] = st[i].hi[2] = st[i].m[2];
    }
    for(int i = 0;i <= M;i++) {
        sr[i] = i;
    }
    build(h, 0, M-1, 0);
    int a[3], al[3], aL[3];
    printf("CORRECT\n");
    for(int i = 0;i < K;i++) {
        scanf("%d%d%d", &a[0], &a[1], &a[2]);
        if(open(a)) {printf("OPEN\n"); continue;}
        for(int i = 0;i < 3;i++) {
            al[i] = min(t1[i], a[i]);
            aL[i] = max(t2[i], a[i]);
        }
        if(q(h, al, aL)) printf("CLOSED\n");
        else printf("UNKNOWN\n");
    }
}