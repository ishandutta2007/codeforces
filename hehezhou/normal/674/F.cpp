#include <bits/stdc++.h>
using namespace std;
typedef unsigned ui;
int n, p, q;
inline ui power(ui a, ui b) {
    ui res = a, ans = 1;
    for(; b; b >>= 1, res = res * res) if(b & 1) ans = ans * res;
    return ans;
}
int inv[150];
int main() {
    cin >> n >> p >> q;
    ui ans = 0;
    for(ui i = 1; i <= q; i++) {
        ui now = 0, C = 1, pw2 = 0, pw = 1;
        for(int j = 0; j <= min(p, n - 1); j++) {
            if(pw2 < 32) now = now + (C * pw << pw2);
            ui tmp = n - j;
            while((tmp & 1) ^ 1) tmp >>= 1, pw2++;
            C = C * tmp;
            tmp = j + 1;
            while((tmp & 1) ^ 1) tmp >>= 1, pw2--;
            C = C * (i == 1 ? inv[j] = power(tmp, (1u << 31) - 1u) : inv[j]);
            pw = pw * i;
        }
        ans = ans ^ (i * now);
    }
    return cout << ans << endl, 0;
}