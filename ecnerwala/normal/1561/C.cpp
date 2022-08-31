#include <bits/stdc++.h>
int main() {
std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
int T; std::cin >> T;
while (T--) {
int N; std::cin >> N;
std::vector<std::pair<int, int>> A(N);
for (int i = 0; i < N; i++) {
int k; std::cin >> k;
int v; std::cin >> v;
for (int i = 1; i < k; i++) { int u; std::cin >> u; v = std::max(v, u-i); }
A[i] = {v, k};
}
std::sort(A.begin(), A.end());
int cur = A[0].second;
int ans = A[0].first;
for (int i = 1; i < N; i++) {
ans = std::max(ans, A[i].first - cur);
cur += A[i].second;
}
std::cout << ans+1 << '\n';
}
}