#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

#define lx x + x
#define rx lx + 1

struct Segment{
    LL sum, len;
    int sign;
} t[N << 3];

LL q[N], S[N];
char s[N];


Segment uni(Segment a, Segment b){
    Segment ret;
    ret.sign = -1;
    ret.sum = (a.sum * q[b.len] + b.sum) % MOD;
    ret.len = a.len + b.len;
    return ret;
}

void build(int x, int l, int r){
    if (l == r){
        t[x].len = 1;
        t[x].sign = -1;
        t[x].sum = s[l - 1] - '0';
        return;
    }
    int mid = l + r >> 1;
    build(lx, l, mid);
    build(rx, mid + 1, r);
    t[x] = uni(t[lx], t[rx]);
}

void pushDown(int x){
    if (t[x].sign == -1) return;
    t[x].sum = (S[t[x].len - 1] * t[x].sign) % MOD;
    t[lx].sign = t[x].sign, t[rx].sign = t[x].sign;
    t[x].sign = -1;
}

Segment query(int x, int l, int r, int a, int b){
    pushDown(x);
    if (l >= a &&r <= b) return t[x];
    int mid = l + r >> 1;
    if (a > mid) return query(rx, mid + 1, r, a, b);
    if (b <= mid) return query(lx, l, mid, a, b);
    return uni(query(lx, l, mid, a, b), query(rx, mid + 1, r, a, b));
}

void change(int x, int l, int r, int a, int b, int c){
    pushDown(x);
    if (l >= a && r <= b){
        t[x].sign = c;
        pushDown(x);
        return;
    }
    int mid = l + r >> 1;
    if (a <= mid) change(lx, l, mid, a, b, c);
    if (b > mid) change(rx, mid + 1, r, a, b, c);
    pushDown(lx); pushDown(rx);
    t[x] = uni(t[lx], t[rx]);
}


int main(){
    int n, m, k, op, l, r, z;
    scanf("%d%d%d", &n, &m, &k);
    q[0] = 1, S[0] = 1;
    for (int i = 1; i < n; i++){
        q[i] = q[i - 1] * 71 % MOD;
        S[i] = (S[i - 1] + q[i]) % MOD;
    }
    scanf("%s", s);
    build(1, 1, n);
    for (int i = 0; i < m + k; i++){
        scanf("%d%d%d%d", &op, &l, &r, &z);
        if (op == 1){
            change(1, 1, n, l, r, z);
        }else{
            if (z == r - l + 1){
                puts("YES");
                continue;
            }
            Segment x = query(1, 1, n, l, r - z);
            Segment y = query(1, 1, n, l + z, r);
            if (x.sum == y.sum){
                puts("YES");
            }else puts("NO");
        }
    }
}