#include <bits/stdc++.h>
int main() {
std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
int T; std::cin >> T;
while (T--) {
int N, M; std::cin >> N >> M;
std::vector<int> A(N); for (auto& a : A) std::cin >> a;
int ans = (M&1) ? std::accumulate(A.begin(), A.end(), 0) : 0;
std::vector<int8_t> deg(N, 0);
while (M--) { int x, y; std::cin >> x >> y; x--, y--; ans = std::min(ans, A[x] + A[y]); deg[x]^=1; deg[y]^=1; }
for (int i = 0; i < N; i++) if (deg[i]) ans = std::min(ans, A[i]);
std::cout << ans << '\n';
}
}