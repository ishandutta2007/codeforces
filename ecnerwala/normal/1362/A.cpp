#include<bits/stdc++.h>
int main() {
using std::cin; using std::cout;
int T; cin >> T;
auto norm = [](int64_t v) -> int64_t { return v >> __builtin_ctzll(v); };
while (T--) {
int64_t a, b; cin >> a >> b;
if (norm(a) != norm(b)) cout << -1 << '\n';
else cout << (abs(__builtin_ctzll(a) - __builtin_ctzll(b))+2)/3 << '\n';
}
}