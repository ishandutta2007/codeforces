#include<bits/stdc++.h>
using namespace std;
int N;
int A[20];
int main() {
cin >> N;
int t = 0;
for (int i = 0; i < N; i++) cin >> A[i], t += A[i];
if (N == 1) cout << -1 << '\n';
else if (N == 2 && A[0] * 2 == t) cout << -1 << '\n';
else if (A[0] * 2 == t) {
cout << 2 << '\n' << 1 << ' ' << 2 << '\n';
} else {
cout << 1 << '\n' << 1 << '\n';
}
}