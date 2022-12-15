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

const int SIZE = 3E5+5;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f3f;
const ll fat = 1E9+9;

ll n;
ll arr[SIZE], seg[4 * SIZE], lazyA[4 * SIZE], lazyB[4* SIZE];
ll fibA[SIZE], fibB[SIZE], sumA[SIZE], sumB[SIZE];


void build(ll idx = 0, ll l = 0, ll r = n - 1) {
    if(l == r) {
        seg[idx] = arr[l];
    } else {
        ll mid = (l + r) / 2;
        build(2*idx+1, l, mid);
        build(2*idx+2, mid + 1, r);
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
        seg[idx] %= fat;
    }
}

void updateLazy(ll idx, ll l, ll r) {
    ll mid = (l + r) / 2;
    seg[idx] = (seg[idx] + (lazyA[idx] * sumA[r-l]) % fat + (lazyB[idx] * sumB[r-l]) % fat) % fat;
    if(l != r) {
        lazyA[idx * 2 + 1] = (lazyA[idx * 2 + 1] + lazyA[idx]) % fat;
        lazyB[idx * 2 + 1] = (lazyB[idx * 2 + 1] + lazyB[idx]) % fat;
        ll lazyAChildren = (lazyA[idx] * fibA[mid+1-l]) % fat + (lazyB[idx] * fibB[mid+1-l]) % fat;
        ll lazyBChildren = (lazyA[idx] * fibA[mid+2-l]) % fat + (lazyB[idx] * fibB[mid+2-l]) % fat;
        lazyA[idx * 2 + 2] = (lazyA[idx * 2 + 2] + lazyAChildren) % fat;
        lazyB[idx * 2 + 2] = (lazyB[idx * 2 + 2] + lazyBChildren) % fat;
    }
    lazyA[idx] = 0;
    lazyB[idx] = 0;
}

ll query(const ll L, const ll R, ll idx = 0,ll l = 0, ll r = n-1) {
    if(lazyB[idx] != 0 && lazyA[idx] != 0) {
        updateLazy(idx, l, r);
    }
    if(R < l || L > r) return 0;
    if(L <= l && r <= R) return seg[idx];
    ll mid = (l+r)/2;
    return (query(L, R, 2*idx+1, l, mid) + query(L, R, 2*idx+2, mid+1, r)) % fat;
}

void update(const ll i, const ll j, ll idx = 0, ll l = 0, ll r = n -1) {
    ll mid = (l+r)/2;
    if(lazyB[idx] != 0 && lazyA[idx] != 0) {
        updateLazy(idx, l , r);
    }
    if(l > j || r < i) return;
    if(l >= i && r <= j) {
        seg[idx] = (seg[idx] + sumB[r - i + 1] - sumB[l - i]) % fat;
        if(seg[idx] < 0) seg[idx] += fat;
        if(l != r) {
            lazyA[idx * 2 + 1] = (lazyA[idx * 2 + 1] + fibB[l-i+1]) % fat;
            lazyB[idx * 2 + 1] = (lazyB[idx * 2 + 1] + fibB[l-i+2]) % fat;
            lazyA[idx * 2 + 2] = (lazyA[idx * 2 + 2] + fibB[mid-i+2]) % fat;
            lazyB[idx * 2 + 2] = (lazyB[idx * 2 + 2] + fibB[mid-i+3]) % fat;
        }   
        return;
    }
    update(i, j, 2 * idx + 1, l, mid);
    update(i, j, 2 * idx + 2, mid + 1, r);
    seg[idx] = (seg[2*idx+1] + seg[2*idx+2]) % fat;
}

int main() {
    ll m;
    scanf("%lld %lld", &n, &m);
    for(ll i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    build();

    // preparar o fibonacci
    sumA[0] = 1;
    sumB[0] = 0;
    fibA[0] = 1;
    fibB[0] = 0;
    fibA[1] = 0;
    fibB[1] = 1;

    for(ll i = 1; i <= n; i++) {
        sumA[i] = (fibA[i] + sumA[i-1]) % fat;
        sumB[i] = (fibB[i] + sumB[i-1]) % fat;
        fibA[i+1] = (fibA[i] + fibA[i-1]) % fat;
        fibB[i+1] = (fibB[i] + fibB[i-1]) % fat;
    }

    // Query
    ll t, l, r;
    for(ll i = 0; i < m; i++) {
        scanf("%lld %lld %lld", &t, &l, &r);
        l--;
        r--;
        if(t == 1) {
            update(l, r);
        } else {
            printf("%lld\n", query(l, r));
        }
    }
    return 0;
}