#include <bits/stdc++.h>
int main() {
using std::cin;
using std::cout;
int T; cin >> T;
while (T--) {
std::array<std::array<int, 2>, 3> A;
for (auto& a : A) cin >> a[1] >> a[0];
std::sort(A.begin(), A.end());
cout << (A[1][0] == A[2][0] ? A[2][1] - A[1][1] : 0) << '\n';
}
}