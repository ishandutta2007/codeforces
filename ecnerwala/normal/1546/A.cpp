#include <bits/stdc++.h>
int main() {
using namespace std;
int T; cin >> T;
while (T--) {
int N; cin >> N;
vector<int> A; A.reserve(100);
vector<int> B; B.reserve(100);
for (int i = 0; i < N; i++) {
int x; cin >> x; while (x--) A.push_back(i);
}
for (int i = 0; i < N; i++) {
int x; cin >> x; while (x--) B.push_back(i);
}
if (A.size() == B.size()) {
cout << A.size() << '\n';
for (int i = 0; i < int(A.size()); i++) cout << A[i]+1 << ' ' << B[i]+1 << '\n';
} else {
cout << -1 << '\n';
}
}
}