#include<bits/stdc++.h>
using namespace std;

int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T; cin >> T;
while (T--) {
int N; cin >> N; string S; cin >> S;
string ans;
for (char c : S) if (c & 1) ans += c;
if (ans.size() & 1) ans.pop_back();
if (ans.empty()) ans = "-1";
cout << ans << '\n';
}
}