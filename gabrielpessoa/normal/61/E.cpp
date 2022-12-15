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

ll bit[SIZE];
int arr[SIZE];
ll pares[SIZE];
map<int, int> cord;
int n;

void build() {
    memset(bit, 0, sizeof(bit));
}

void update(int idx, ll v = 1) {
    while(idx <= n) {
        bit[idx] += v;
        //printf("bit[%d] agora eh %lld\n", idx, bit[idx]);
        idx += idx & -idx;
    }
}

ll query(int idx) {
    ll r = 0;
    while(idx > 0) {
        r += bit[idx];
        idx -= idx & -idx;
    }
    return r;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        cord[arr[i]] = i;
    }
    int qnt = 0;
    for(auto c : cord) {
        arr[c.second] = ++qnt;
    }
    for(int i = n - 1; i >= 0; i--) {
        //printf("%d\n", arr[i]);
        pares[i] = query(arr[i] - 1);
        //printf("Na posicao %d pode se ter %lld pares\n", i, pares[i]);
        update(arr[i]);
        //printf("Depois de update pode-se ter %lld na posicao %d\n", query(arr[i]), i);
    }
    build();
    ll total = 0;
    for(int i = n - 1; i >= 0; i--) {
        total += query(arr[i]);
        update(arr[i], pares[i]);
    }
    printf("%lld\n", total);
    return 0;
}