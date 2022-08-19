#include <bits/stdc++.h>
int main() {
std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
int T; std::cin >> T;
while (T--) {
int N, A; std::cin >> N >> A; N--;
bool good = true;
while (N--) { int v; std::cin >> v; if (v % A) good = false; }
std::cout << (good ? "YES" : "NO") << '\n';
}
}