#include <iostream>
#include <cstdio>

#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAXN = 1e2 + 10;
const int MAXM = 1e5 + 1000;
const int INF = 1e9 + 1e6;

int N, M;

int win(int * cur) {
    if(cur[0]) return 0;
    if(cur[2] > 1 or (cur[2] == 1 and (cur[1]&1) == 0)) return 0;
    return (cur[1]&1 ? 1 : 2);
}

ll vi[MAXN];

struct OP {
    int l;
    int cv, d;
    OP() {l = cv = d = -1;}
    OP(int a, int b = -1, int c = -1) {l = a, cv = b, d = c;}
    void act(int * cur) {if(cv != -1) cur[cv] += d;}
    bool operator < (const OP& o) const {return l < o.l;}
} op[MAXN * 4];

int main() {
    scanf("%d%d", &N, &M);
    for(int i = 0;i < N;i++) scanf("%lld", vi + i);
    
    ll fv[3];      //a, f, s
    for(int i = 0;i < 3;i++) fv[i] = 0;
    
    for(int s = 3;s < M * 2;s++) {
        
        int a = 0;
        int ops = 0;
        int cur[3];
        for(int i = 0;i < 3;i++) cur[i] = 0;
        cur[0] = N;
        
        for(int i = 0, t1, t2;i < N;i++) {
            int l = static_cast<int>(vi[i]%s);
            if(l * 2 < s) op[ops++] = OP(l + 1, 0, -1); else if(l * 2 > s) op[ops++] = OP(s - l, 0, -1);
            if(l * 2 > s) op[ops++] = OP(s - l, 1, 1);
            if(l * 2 > s and (t1 = s - l) < (t2 = (l)/2 + 1)) op[ops++] = OP(t1, 2, 1), op[ops++] = OP(t2, 2, -1);
        }
        op[ops++] = OP(0, -1, -1);
        sort(op, op + ops);
        op[ops].l = (s + 1)/2;
        
        for(int i = 0, j;i < ops;i = j) {
            for(j = i;j < ops and op[j].l == op[i].l;j++) op[j].act(cur);
            int f = win(cur);
            //printf("%d %d %d %d %d %d %d %d %d\n", s, i, j, op[i].l, op[j].l, f, cur[0], cur[1], cur[2]);
            fv[f] += max(0, min(op[j].l, (s + 1)/2) - max(op[i].l, max(1, s - M)));
        }
        
    }
    
    for(int i = 1;i < 3;i++) fv[i] *= 2;
    
    for(int i = 1;i <= M;i++) {
        ll p = 0;
        for(int j = 0;j < N;j++) p += vi[j]/i;
        if(p&1) fv[1]++; else fv[2]++;
    }
    
    printf("%lld %lld %lld %lld\n", fv[0], fv[0], fv[1], fv[2]);
    
    return 0;
}