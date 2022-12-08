#include <iostream>
#include <cstdio>

#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 101000;
const ll INF = 1e18;

int N;
ll arr[MAXN * 2];

int main() {
    scanf("%d", &N);
    for(int i = 0;i < N * 2;i++) {
        int ip;
        scanf("%d", &ip);
        arr[i] = static_cast<ll>(ip);
    }
    sort(arr, arr+2 * N);
    
    ll ans = (arr[N - 1] - arr[0]) * (arr[N * 2 - 1] - arr[N]);
    
    ll o = arr[N * 2 - 1] - arr[0];
    ll t = INF;
    for(int i = 1;i < N;i++) {
        ll a = static_cast<ll> (arr[i + N - 1] - arr[i]);
        if(a < t) t = a;
    }
    if(t < INF && o * t < ans) ans = o * t;
    
    printf("%I64d\n", ans);
    
    return 0;
}