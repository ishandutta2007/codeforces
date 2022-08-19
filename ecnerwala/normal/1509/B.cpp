#include <bits/stdc++.h>
int main() {
using namespace std;
int T; cin >> T; while (T--) {
int N; cin >> N;
string S; cin >> S;
for (char c : S) if (c == 'M') N -= 3;
bool good = !N;
int v = 0;
for (char c : S) if (c == 'T') v++; else { good = good && v; v--; }
v = 0;
reverse(S.begin(), S.end());
for (char c : S) if (c == 'T') v++; else { good = good && v; v--; }
cout << (good ? "YES" : "NO") << '\n';
}
}