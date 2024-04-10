#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;

const int M = 1e9 + 7;
const int N = 1e6 + 13;

int sum(int a, int b) {
    int res = a + b;

    if(res >= M)
        res -= M;

    return res;
}

int a[N];

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

//    int ans = sum(a[0], a[1]);
//    ans = sum(ans, min(a[0], a[1]) * 1ll * min(a[0], a[1]) % M);
    int ans = a[0];

    int cur = 1;
    int x = a[0];

    for(int i = 1; i < n; i++) {
        cur = (cur * 1ll * min(x, a[i]) + 1 + max(0, min(a[i], a[i - 1]) - x)) % M;
        x = min(a[i - 1], a[i]);
        ans = sum(ans, sum(cur * 1ll * x % M, a[i] - x));
//        if(a[i] <= a[i - 1]) {
//            ans =
//        } else {
//
//        }
    }

    cout << ans;
}