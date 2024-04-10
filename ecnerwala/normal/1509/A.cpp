#include <bits/stdc++.h>
int main() {
using std::cin; using std::cout;
int T; cin >> T;
while (T--) {
int N; cin >> N;
std::vector<int> A(N); for (auto& a : A) cin >> a;
for (int a : A) if (a & 1) cout << a << ' ';
for (int a : A) if (!(a & 1)) cout << a << ' ';
cout << '\n';
}
}