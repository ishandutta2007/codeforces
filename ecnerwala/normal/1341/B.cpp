#include<bits/stdc++.h>
using namespace std;

void go() {
int N, K; cin >> N >> K;
vector<int> A(N);
for (int i = 0; i < N; i++) cin >> A[i];
vector<int> pref(N-1);
for (int i = 1; i+1 < N; i++) pref[i] = pref[i-1] + (A[i] > max(A[i-1], A[i+1]));
int bestL = -1, bestAns = -1;
for (int l = 0; l+K-2 <= N-2; l++) { int cnd = pref[l+K-2] - pref[l]; if (cnd > bestAns) bestAns = cnd, bestL = l; }
cout << bestAns+1 << ' ' << bestL+1 << '\n';
}

int main() {
int T; cin >> T;
while (T--) {
go();
}
}