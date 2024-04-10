#include<bits/stdc++.h>
using namespace std;

int main() {
int N, K; cin >> N >> K;
for (int m = K-1; m > 0; m--) {
if (N % m == 0) {
cout << (N / m) * K + m << '\n';
return 0;
}
}
}