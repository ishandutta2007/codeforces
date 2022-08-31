#include <bits/stdc++.h>
int main() {
using namespace std;
int T; cin >> T;
while (T--) { string S; cin >> S; bool f = false;
for (char c : S) {
c = f ? 'z' + 'a' - c : c;
c = 'a' + (c == 'a');
c = f ? 'z' + 'a' - c : c;
cout << c;
f ^= 1;
}
cout << '\n';
}
}