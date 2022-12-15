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

const int SIZE = 1E6;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f3f;
const ll fat = 1E6;

int seg[SIZE];
int arr[SIZE];
int n, npow, m;

void build(int idx = 0, int l = 0, int r = n - 1, int ore = npow % 2) {
    if(l == r) {
        seg[idx] = arr[l];
    } else {
        int mid = (l + r) / 2;
        build(2 * idx + 1, l, mid, (ore + 1) % 2);
        build(2 * idx + 2, mid + 1, r, (ore + 1) % 2);
        seg[idx] = ore ? seg[2*idx+1] | seg[2*idx+2] : seg[2*idx+1] ^ seg[2*idx+2];
    }
}

void update(int p, int v, int idx = 0, int l = 0, int r = n - 1, int ore = npow % 2) {
    if(l > p || r < p) return;
    if(l == r) {
        seg[idx] = v;
    } else {
        int mid = (l+r)/2;
        update(p, v, 2*idx+1, l, mid, (ore + 1) % 2);
        update(p, v, 2*idx+2, mid+1, r, (ore + 1) % 2);
        seg[idx] = ore ? seg[2*idx+1] | seg[2*idx+2] : seg[2*idx+1] ^ seg[2*idx+2];
    }
}

int query(int L = 0, int R = n - 1, int idx = 0, int l = 0, int r = n - 1, int ore = npow % 2) {
    return seg[0];
    //if(L > r || R < l) return 0;
    //if(L <= l && R >= r) return seg[idx];
    //int mid = (l+r)/2;
    //return
}

int main() {
    scanf("%d %d", &npow, &m);
    n = 1 << npow;
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    build();
    while(m--) {
        int p, b;
        scanf("%d %d", &p, &b);
        update(p-1, b);
        printf("%d\n", query());
    }   
    return 0;
}