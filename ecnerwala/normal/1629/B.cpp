#include <bits/stdc++.h>
int main() {
using namespace std;
int T; cin >> T; while (T--) {
int L, R, K; cin >> L >> R >> K; L--;
cout << (R-L==1 && L || K >= R-R/2-L+L/2 ? "YES" : "NO") << '\n';
}
}