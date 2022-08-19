#include<bits/stdc++.h>
using namespace std;

int main() {
int T; cin >> T;
while (T--) {
int N; string S; cin >> N >> S;
int ans = 0;
int cur = -N;
for (char c : S) {
if (c == 'P') ans = max(ans, ++cur); else cur = 0;
}
cout << ans << '\n';
}
}