#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, int> lli;
typedef pair<int, ii> iii;
typedef pair<double, ii> dii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int SIZE = 4E5+5;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f3f;
const ll fat = 1E6;

struct setor {
    ll melhorRun;
    ll melhorComeco;
    ll melhorFinal;
    ll custoTotal;
};

setor seg[SIZE];
ll h[SIZE], d[SIZE];
int n, m;


setor merge(setor a, setor b) {
    setor r;
    r.melhorRun = max(a.melhorRun, b.melhorRun);
    if(b.melhorFinal) {
        r.melhorRun = max(r.melhorRun, a.melhorComeco + b.melhorFinal);
    }
    r.melhorComeco = max(b.melhorComeco, a.melhorComeco + b.custoTotal);
    r.melhorFinal = max(a.melhorFinal, b.melhorFinal + a.custoTotal);
    r.custoTotal = a.custoTotal + b.custoTotal;
    //printf("Apos o merge tem: \nMelhorRun: %lld\nMelhorComeco: %lld\nMelhorFinal: %lld\nCustoTotal: %lld\n----------\n", r.melhorRun, r.melhorComeco, r.melhorFinal, r.custoTotal);
    return r;
}

void build(int idx = 0, int l = 0, int r = n - 1) {
    if(l == r) {
        seg[idx].melhorComeco = d[l] + 2*h[l];
        seg[idx].melhorFinal = 2*h[l];
        seg[idx].melhorRun = 0;
        seg[idx].custoTotal = d[l];
    } else {
        int mid = (l+r)/2;
        build(2*idx+1, l, mid); build(2*idx+2, mid+1, r);
        seg[idx] = merge(seg[2*idx+1], seg[2*idx+2]);
    }
    //printf("entre %d e %d tem: \nMelhorRun: %lld\nMelhorComeco: %lld\nMelhorFinal: %lld\nCustoTotal: %lld\n----------\n", l, r, seg[idx].melhorRun, seg[idx].melhorComeco, seg[idx].melhorFinal, seg[idx].custoTotal);
}

setor query(int L, int R, int idx = 0, int l = 0, int r = n - 1) {
    if(L > r || R < l) return setor();
    if(L <= l && R >= r) return seg[idx];
    int mid = (l+r)/2;
    return merge(query(L, R, 2*idx+1, l, mid), query(L, R, 2*idx+2, mid+1, r));
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &d[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%lld", &h[i]);
    }
    build();
    while(m--) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        if(a > b) {
            printf("%lld\n", query(b+1, a-1).melhorRun);
        } else {
            printf("%lld\n", merge(query(b+1, n-1), query(0, a-1)).melhorRun);
        }
    }
    return 0;
}