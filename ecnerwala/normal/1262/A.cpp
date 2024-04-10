#include<bits/stdc++.h>
using namespace std;
int main() {
int T; cin >> T;
while (T--) {
int N; cin >> N;
vector<int> L(N), R(N);
for (int i = 0; i < N; i++) cin >> L[i] >> R[i];
int l = *max_element(L.begin(), L.end());
int r = *min_element(R.begin(), R.end());
cout << max(l-r,0) << '\n';
}
}