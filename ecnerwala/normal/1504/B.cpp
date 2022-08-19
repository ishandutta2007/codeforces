#include <bits/stdc++.h>
int main() {
std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
int T; std::cin >> T;
while (T--) {
int N; std::string A, B; std::cin >> N >> A >> B;
int sa = 0, sb = 0;
bool good = true;
for (int i = 0; i < N; i++) {
  sa += 2*(A[i]-'0')-1;
  sb += 2*(B[i]-'0')-1;
  good = good && abs(sa) == abs(sb);
}
good = good && sa == sb;
std::cout << (good ? "YES" : "NO") << '\n';
}
}