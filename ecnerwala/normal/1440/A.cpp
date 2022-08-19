#include <bits/stdc++.h>
using namespace std;
int main() {
int T; cin >> T;
while (T--) {
int N, c[2], h; cin >> N >> c[0] >> c[1] >> h;
c[0] = min(c[0], c[1]+h);
c[1] = min(c[1], c[0]+h);
string s; cin >> s;
int ans = 0;
for (char v : s) ans += c[v-'0'];
cout << ans << '\n';
}
}