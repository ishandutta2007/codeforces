#include <bits/stdc++.h>
int main() {
using std::cin; using std::cout;
int T; cin >> T;
while (T--) {
int N; cin >> N;
std::string S; cin >> S;
int ans = 0;
char prv = '\0';
int cnt = 1;
for (int i = 0; i < N; i += 2) {
if (S[i] == S[i+1]) {
if (prv == (S[i]^1)) cnt++;
prv = S[i];
} else ans++;
}
cout << ans << ' ' << cnt << '\n';
}
}