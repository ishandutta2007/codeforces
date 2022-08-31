#include<bits/stdc++.h>
using namespace std;
int main() {
int T; cin >> T;
while (T--) {
int N; string S; cin >> N >> S;
S = '^' + S;
while (S.back() == ')') N -= 2, S.pop_back();
cout << (N < 0 ? "Yes" : "No") << '\n';
}
}