#include<bits/stdc++.h>
using namespace std;

int main() {
ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int T; cin >> T;
while (T--) {
int N; cin >> N;
bool good = true;
bool hasMid = N&1;
for (int i = 0; i < N; i++) { int a; cin >> a; good = good && (a >= min(i, N-1-i)); hasMid = hasMid || abs(N-1-i-i) == 1 && a > min(i, N-1-i); }
cout << (good && hasMid ? "Yes" : "No") << '\n';
}
}