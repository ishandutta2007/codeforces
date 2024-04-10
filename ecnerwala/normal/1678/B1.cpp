#include <bits/stdc++.h>
int main() {
using std::cin; using std::cout;
int T; cin >> T;
while (T--) {
int N; cin >> N;
std::string S; cin >> S;
int ans = 0;
for (int i = 0; i < N; i += 2) ans += S[i] != S[i+1];
cout << ans << '\n';
}
}