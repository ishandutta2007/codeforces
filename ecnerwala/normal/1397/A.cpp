#include<bits/stdc++.h>
int main() {
using namespace std;
int T; cin >> T;
while (T--) {
int N; cin >> N;
array<int, 26> cnt{0};
for (int i = 0; i < N; i++) {
string S; cin >> S;
for (char c : S) cnt[c-'a']++;
}
string ans = "YES";
for (int c : cnt) if (c % N) ans = "NO";
cout << ans << '\n';
}
}