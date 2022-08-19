#include <bits/stdc++.h>
int main() {
std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
int T; std::cin >> T;
while (T--) {
int N; std::cin >> N;
std::cout << N;
for (int i = 1; i < N; i++) std::cout << ' ' << i;
std::cout << '\n';
}
}