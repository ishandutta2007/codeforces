#include<bits/stdc++.h>
bool solve(int A, int D) {
if (A >= D * 10) return true;
for (int i = 1; i < 10; i++) if (A >= D * i && (A - D * i) % 10 == 0) return true;
return false;
}
int main() {
using std::cin;
using std::cout;
int T; cin >> T;
while (T--) {
int Q, D; cin >> Q >> D;
while (Q--) {
int A; cin >> A;
cout << (solve(A,D) ? "YES" : "NO") << '\n';
}
}
}