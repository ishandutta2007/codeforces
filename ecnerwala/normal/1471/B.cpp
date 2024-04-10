#include<bits/stdc++.h>
int main(){using namespace std;int T; cin >> T; while (T--) {
int N, X; cin >> N >> X; vector<int> A(N); for (auto& a : A) cin >> a;
int num_cyc = -1;
int64_t extra_pref = 0;
int64_t cur_pref = 0;
for (int i = 0; i < N; i++) {
int c = 1;
for (int v = A[i]; v % X == 0; v /= X) c++;
if (i == 0 || c < num_cyc) {
num_cyc = c;
extra_pref = cur_pref;
}
cur_pref += A[i];
}
cout << num_cyc * cur_pref + extra_pref << '\n';
}}