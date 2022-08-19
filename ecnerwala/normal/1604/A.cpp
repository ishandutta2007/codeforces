#include <bits/stdc++.h>
int main() {
using std::cin, std::cout;
int T; cin >> T;
while (T--) {
int N; cin >> N;
int ans = 0;
for (int i = 1; i <= N; i++) { int a; cin >> a; ans = std::max(ans, a - i); }
cout << ans << '\n';
}
}