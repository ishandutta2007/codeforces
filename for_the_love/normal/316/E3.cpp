#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define lx x + x
#define rx lx + 1
const int N = 222222;
const int MOD = 1e9;
struct Tnode{
    long long sign, s1, s2, l;
} t[N * 8];

long long s[N], f[N];

Tnode Union(Tnode a, Tnode b){
    Tnode ret;
    ret.sign = 0;
    ret.l = a.l + b.l;
    ret.s1 = a.s1 + b.s1 * (a.l - 2 >= 0 ? f[a.l - 2]: 0) + b.s2 * f[a.l - 1];
    ret.s2 = a.s2 + b.s1 * f[a.l - 1] + b.s2 * f[a.l];
    ret.s1 %= MOD;
    ret.s2 %= MOD;
    return ret;
}
void PushDown(int x){
    if (!t[x].sign) return;
    t[lx].sign += t[x].sign; t[rx].sign += t[x].sign;
    t[x].s1 += s[t[x].l - 1] * t[x].sign;
    t[x].s2 += (s[t[x].l] - 1) * t[x].sign;
    t[x].s1 %= MOD;
    t[x].s2 %= MOD;
    t[lx].sign %= MOD;
    t[rx].sign %= MOD;
    t[x].sign = 0;
}
void Build(int x, int l, int r){
    if (l == r){
        cin >> t[x].s1;
        t[x].s2 = t[x].s1;
        t[x].l = 1;
        return;
    }
    int mid = l + r >> 1;
    Build(lx, l, mid);
    Build(rx, mid + 1, r);
    t[x] = Union(t[lx], t[rx]);
}

Tnode Query(int x, int l, int r, int a, int b){
    PushDown(x);
    if (l >= a && r <= b) return t[x];
    int mid = l + r >> 1;
    if (a > mid) return Query(rx, mid + 1, r, a, b);
    if (b <= mid) return Query(lx, l, mid, a, b);
    return Union(Query(lx, l, mid, a, b), Query(rx, mid + 1, r, a, b));
    PushDown(lx); PushDown(rx);
    t[x] = Union(t[lx], t[rx]);
}


void Change(int x, int l, int r, int a, int b){
    PushDown(x);
    if (l == a && r == a){
        t[x].s1 = t[x].s2 = b;
        return;
    }
    int mid = l + r >> 1;
    if (a <= mid) Change(lx, l, mid, a, b); else Change(rx, mid + 1, r, a, b);
    PushDown(lx); PushDown(rx);
    t[x] = Union(t[lx], t[rx]);
}

void Add(int x, int l, int r, int a, int b, int d){
    PushDown(x);
    if (l >= a && r <= b){
        t[x].sign = d;
        PushDown(x);
        return;
    }
    int mid = l + r >> 1;
    if (a <= mid) Add(lx, l, mid, a, b, d);
    if (b > mid) Add(rx, mid + 1, r, a, b, d);
    PushDown(lx); PushDown(rx);
    t[x] = Union(t[lx], t[rx]);
}

int main(){
int n, m, p, a, b, d;
    f[0] = f[1] = 1;
    s[0] = 1; s[1] = 2;
    for (int i = 2; i <= N; i++){
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
        s[i] = (s[i - 1] + f[i]) % MOD;
    }
    cin >> n >> m;
    Build(1, 1, n);
    while (m--){
        cin >> p;
        if (p == 1){
            cin >> a >> b;
            Change(1, 1, n, a, b);
        }else if (p == 2){
            cin >> a >> b;
            cout << Query(1, 1, n, a, b).s1 << endl;
        }else{
            cin >> a >> b >> d;
            Add(1, 1, n, a, b, d);
        }
    }
}