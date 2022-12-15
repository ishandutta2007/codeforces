#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, double> id;
typedef vector<id> vid;
typedef pair<double, int> di;
typedef vector<di> vdi;
typedef pair<string, string> ss;

const int SIZE  = 1E5+5;
const int MOD = 1E9 + 7;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;

map<ll, int> dic;
ll arr[SIZE];
int previous[SIZE];
ii seg[12*SIZE];
int n;
int nt = 0;
ll d;

ii query(int L, int R, int idx = 0, int l = 0, int r = nt - 1) {
    if(R < l || L > r) return ii(0, 0);
    if(L <= l && R >= r) return seg[idx];
    int mid = (l+r)/2;
    return max(query(L, R, 2*idx+1, l, mid), query(L, R, 2*idx+2, mid+1, r));
}

void update(int p, ii v, int idx = 0, int l = 0, int r = nt - 1) {
    if(p < l || p > r) return;
    if(l == r) {
        seg[idx] = v;
        return;
    }
    int mid = (l+r)/2;
    update(p, v, 2*idx+1, l, mid); update(p, v, 2*idx+2, mid+1, r);
    seg[idx] = max(seg[2*idx+1], seg[2*idx+2]);
}

void printAte(int idx) {
    if(!idx) return;
    printAte(previous[idx]);
    printf("%d ", idx);
}

int main() {
    scanf("%d %lld", &n, &d);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &arr[i]);
        dic[arr[i]];
        dic[arr[i]+d];
        dic[arr[i]-d];
    }
    for(auto &p : dic) {
        p.second = nt++;
    }
    for(int i = 1; i <= n; i++) {
        ii best = max(query(0, dic[arr[i]-d]), query(dic[arr[i]+d], nt - 1));
        previous[i] = best.second;
        update(dic[arr[i]], ii(best.first+1, i));
    }
    ii resposta = query(0, nt - 1);
    printf("%d\n", resposta.first);
    printAte(resposta.second);
    return 0;
}