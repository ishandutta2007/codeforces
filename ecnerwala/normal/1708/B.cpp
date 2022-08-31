#include <bits/stdc++.h>
int main() {
std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
int T; std::cin >> T;
while (T--) {
int N, L, R; std::cin >> N >> L >> R;
bool good = true;
for (int i = 1; i <= N; i++) good = good && (R/i*i >= L);
if (!good) std::cout << "NO" << '\n';
else {
std::cout << "YES" << '\n';
for (int i = 1; i <= N; i++) std::cout << R/i*i << " \n"[i==N];
}
}
}