#include <bits/stdc++.h>
int main() {
using namespace std;
ios_base::sync_with_stdio(false); cin.tie(nullptr);

int T; cin >> T;
while (T--) {
string S; cin >> S; int N = int(S.size());
auto i = S.find_first_not_of('a');
if (i == string::npos) { cout << "NO" << '\n'; continue; }
int j = (i < N/2 ? N-i : N-1-i);
cout << "YES" << '\n';
cout << S.substr(0, j) << 'a' << S.substr(j) << '\n';
}
}