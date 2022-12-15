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

const int SIZE = 4E6+5;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f3f;
const ll fat = 1E6;

char arr[SIZE];
iii seg[SIZE];

int n;


iii merge(iii a, iii b) {
    int novos = min(a.second.first, b.second.second);
    iii resposta = iii(a.first + b.first + 2*novos, ii(a.second.first + b.second.first - novos, a.second.second + b.second.second - novos));
    //printf("Dando merge em (%d, (%d %d)) x (%d, (%d %d)) = (%d, (%d %d))\n", a.first, a.second.first, a.second.second, b.first, b.second.first, b.second.second, resposta.first, resposta.second.first, resposta.second.second);
    return resposta;
}

void build(int idx = 0, int l = 0, int r = n - 1) {
    //printf("build(%d, %d, %d) com N = %d\n", idx, l, r, n);
    if(l == r) {
        seg[idx] = (arr[l] == '(') ? iii(0, ii(1, 0)) : iii(0, ii(0, 1));
        return;
    }
    int mid = (l+r)/2;
    build(2*idx+1, l, mid); build(2*idx+2, mid+1, r);
    seg[idx] = merge(seg[2*idx+1], seg[2*idx+2]);
}

void update(int p, int v, int idx = 0, int l = 0, int r = n - 1) {
    if(p < l || p > r) return;
    if(l == r) {
        arr[p] = v;
        seg[idx] = (v == '(') ? iii(0, ii(1, 0)) : iii(0, ii(0, 1));
        return;
    }
    int mid = (l+r)/2;
    update(p, v, 2*idx +1, l, mid); update(p, v, 2*idx+2, mid+1, r);
    seg[idx] = merge(seg[2*idx+1], seg[2*idx+2]);
}

iii query(int L, int R, int idx = 0, int l = 0, int r = n - 1) {
    if(L > r || R < l) return iii(0, ii(0, 0));
    if(L <= l && R >= r) return seg[idx];
    int mid = (l+r)/2;
    return merge(query(L, R, 2*idx+1, l, mid), query(L, R, 2*idx+2, mid + 1, r));
}

int main() {
    scanf("%s", arr);
    n = strlen(arr);
    build();
    int m;
    scanf("%d", &m);
    while(m--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", query(l-1, r-1).first);
    }
    return 0;
}