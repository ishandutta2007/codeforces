#include <bits/stdc++.h>
int main() {
std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
int T; std::cin >> T;
while (T--) {
int N; std::cin >> N;
int prv = 0, ans = 0;
while (N--) {
int nxt; std::cin >> nxt;
if (prv > nxt) { ans++, prv = 0; }
else prv = nxt;
}
std::cout << ans << '\n';
}
}