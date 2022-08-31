#include <bits/stdc++.h>
int main() {
using namespace std;
int T; cin >> T; while (T--) {
int N, K; cin >> N >> K;
std::vector<std::pair<int, int>> A(N);
for (auto& [a, b] : A) cin >> a;
for (auto& [a, b] : A) cin >> b;
std::sort(A.begin(), A.end());
for (auto [a, b] : A) if (K >= a) K += b;
cout << K << '\n';
}
}