#include <bits/stdc++.h>
int main() {
using std::cin;
using std::cout;
int T; cin >> T;
while (T--) {
int N; cin >> N;
std::vector<int> A(N);
for (auto& a : A) cin >> a;
std::sort(A.begin(), A.end());
int V = int(std::unique(A.begin(), A.end()) - A.begin());
for (int K = 1; K <= N; K++) cout << std::max(K, V) << " \n"[K==N];
}
}