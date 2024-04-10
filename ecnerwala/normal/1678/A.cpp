#include <bits/stdc++.h>
int main() {
using std::cin; using std::cout;
int T; cin >> T;
while (T--) {
int N; cin >> N;
std::vector<int> A(N);
int cnt_0 = 0;
for (auto& a : A) { cin >> a; cnt_0 += (a == 0); }
if (cnt_0) cout << N - cnt_0 << '\n';
else {
std::sort(A.begin(), A.end());
cout << (N+(std::unique(A.begin(), A.end()) == A.end())) << '\n';
}
}
}