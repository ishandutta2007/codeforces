#include<bits/stdc++.h>
using namespace std;

int main() {
int T; cin >> T;
while (T--) {
int a, b; cin >> a >> b;
int d = abs(a-b);
cout << (d/5 + (d%5+1)/2) << '\n';
}
}