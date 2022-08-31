#include<bits/stdc++.h>
using namespace std;

int main() {
int N; cin >> N;
vector<int> A(N);
for (int i = 0; i < N; i++) cin >> A[i];
int cnt[3] = {0,0,0};
for (int i = 0; i < N; i++) { int v; cin >> v; cnt[A[i] - v + 1]++;}
if (cnt[2] == 0) cout << -1 << '\n';
else cout << (cnt[0]+cnt[2]) / cnt[2] << '\n';
}