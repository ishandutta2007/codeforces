#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, p;
// d * p + d <= n
// d >= cnt
inline int check(ll d) {
    ll newn = n - 1ll * d * p, tmp = newn;
    if(newn < 0) return 0;
    int cnt = 0;
    for(; newn; newn >>= 1) cnt += newn & 1;
    if(d >= cnt && d <= tmp) return 1;
    return 0;
}
int main() {
    cin >> n >> p;
    for(int i = 1; i <= 1000000; i++) {
        if(check(i)) return cout << i << endl, 0;
    }
    return cout << -1 << endl, 0;
}