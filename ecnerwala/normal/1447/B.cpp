#include<bits/stdc++.h>
using namespace std;
int main() {
int T; cin >> T;
while (T--) {
int N, M; cin >> N >> M; N *= M;
vector<int> A(N);
bool flip = 0;
for (int& a : A) cin >> a, flip ^= (a < 0), a = abs(a);
if (flip) *min_element(A.begin(), A.end()) *= -1;
cout<<accumulate(A.begin(),A.end(),0)<<'\n';
}
}