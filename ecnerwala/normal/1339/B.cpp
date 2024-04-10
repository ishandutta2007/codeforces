#include<bits/stdc++.h>
using namespace std;

void go() {
int N; cin >> N;
vector<int> A(N);
for (int i = 0; i < N; i++) cin >> A[i];
sort(A.begin(), A.end());
vector<int> ans; ans.reserve(N);
int lo = 0, hi = N;
for (int z = 0; z < N; z++) {
if (z & 1) ans.push_back(A[lo++]);
else ans.push_back(A[--hi]);
}
reverse(ans.begin(), ans.end());
for (int i = 0; i < N; i++) {
cout << ans[i] << " \n"[i+1==N];
}
}

int main() {
ios_base::sync_with_stdio(0); cin.tie(nullptr);

int T; cin >> T;
while (T--) {
go();
}
}