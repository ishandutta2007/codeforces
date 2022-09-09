#include<bits/stdc++.h>
using namespace std;
using LL = long long;
#define FOR(i) for(int i = -1; i <= 1; i += 1)
LL d(LL a, LL b, LL c){
    return abs(a - b) + abs(a - c) + abs(b - c);
}
int main(){
    int q;
    for(cin >> q; q; q -= 1){
        LL a, b, c, ans = LONG_LONG_MAX;
        cin >> a >> b >> c;
        FOR(i)FOR(j)FOR(k) ans = min(ans, d(a + i, b + j, c + k));
        cout << ans << "\n";
    }
}