#include <bits/stdc++.h>
using namespace std;

int main() {
int T; cin >> T;
while (T--) {
int N; string S; cin >> N >> S;
int64_t ans = N;
for (int i = 1; i < N; i++) {
if (S[i-1] != S[i]) ans += i;
}
cout << ans << '\n';
}
}