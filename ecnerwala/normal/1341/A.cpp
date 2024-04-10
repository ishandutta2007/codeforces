#include<bits/stdc++.h>
using namespace std;
int main() {
int T; cin >> T;
while (T--) {
int N, A, B, C, D; cin >> N >> A >> B >> C >> D;
A *= N, B *= N;
cout << (abs(A-C) <= B+D ? "Yes" : "No") << '\n';
}
}