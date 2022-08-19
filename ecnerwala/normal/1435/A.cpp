#include<bits/stdc++.h>
int main() {
using namespace std;
int T; cin >> T;
while (T--) {
int N; cin >> N; N /= 2;
while (N--) {
int a, b; cin >> a >> b;
cout << b << ' ' << -a << '\n';
}
}
}