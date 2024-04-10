#include <bits/stdc++.h>
int main() {
using std::cin;
using std::cout;
int T; cin >> T;
while (T--) {
int N; cin >> N;
std::vector<int> A(N); for (auto& a : A) cin >> a;
int tot = 0; for (auto a : A) tot += a;
bool good = false;
for (auto a : A) if (a * N == tot) good = true;
cout << (good ? "YES" : "NO") << '\n';
}
}