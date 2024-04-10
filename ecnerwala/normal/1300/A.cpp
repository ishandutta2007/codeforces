#include <bits/stdc++.h>
using namespace std;
int main() {
int T; cin >> T; while (T--) {
int N; cin >> N; int s = 0, ans = 0; while (N--) { int a; cin >> a; ans += !a, s += a + !a; }
ans += !s;
cout << ans << '\n';
}
}