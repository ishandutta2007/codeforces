#include<bits/stdc++.h>
int main() {
using namespace std;
int T; cin >> T; while (T--) {
int N; cin >> N;
std::vector<int> A(N);
for (auto& a : A) cin >> a;
std::reverse(A.begin(), A.end());
int cnt = 0;
for (int i = 0; i < N; ) {
if (A[i] == A[0]) i++;
else i *= 2, cnt++;
}
cout << cnt << '\n';
}
}