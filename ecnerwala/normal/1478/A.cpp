#include <bits/stdc++.h>
int main() {
using namespace std;
int T; cin >> T; while (T--) {
int N; cin >> N;
int last = 0, cnt = 0, ans = 0;
while (N--) { int v; cin >> v; if (v != last) last = v, cnt = 0; ans = max(ans, ++cnt); }
cout << ans << '\n';
}
}