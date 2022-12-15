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

const int SIZE = 1E6+5;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f3f;
const ll fat = 1E6;

int arr[SIZE];
ii seg[SIZE];

int n;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

ii merge(ii a, ii b) {
    if(a.first == b.first) return ii(a.first, a.second + b.second);
    int g = gcd(a.first, b.first);
    if(g == a.first) return a;
    if(g == b.first) return b;
    return ii(g, 0);
}

void build(int idx = 0, int l = 0, int r = n - 1) {
    if(l == r) {
        seg[idx] = ii(arr[l], 1);
    } else {
        int mid = (l+r)/2;
        build(2*idx+1, l, mid);
        build(2*idx+2, mid + 1, r);
        seg[idx] = merge(seg[2*idx+1], seg[2*idx+2]);
        //printf("seg de %d a %d = (%d, %d)\n", l, r, seg[idx].first, seg[idx].second);
    }
}

ii query(int L, int R, int idx = 0, int l = 0, int r = n - 1) {
    if(L > r || R < l) return ii(0, 0);
    if(L <= l && R >= r) return seg[idx];
    int mid = (l+r)/2;
    return merge(query(L, R, 2*idx + 1, l, mid), query(L, R, 2*idx + 2, mid + 1, r));
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    build();
    int t;
    scanf("%d", &t);
    while(t--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", r - l + 1 - query(l-1, r-1).second);
    }
    return 0;
}