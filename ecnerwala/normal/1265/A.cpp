#include<bits/stdc++.h>
using namespace std;
int main() {
int T; cin >> T;
while (T--) {
string S; cin >> S; int N = int(S.size());
for (int i = 0; i < N; i++) {
if (S[i] != '?') continue;
for (S[i] = 'a'; true; S[i]++) {
if ((i == 0 || S[i] != S[i-1]) && (i == N-1 || S[i] != S[i+1])) break;
}
}
for (int i = 1; i < N; i++) if (S[i] == S[i-1]) { S = "-1"; break; }
cout << S << '\n';
}
}