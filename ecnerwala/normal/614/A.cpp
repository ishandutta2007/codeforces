#include<bits/stdc++.h>
using namespace std;

int main() {
long long l, r, k, v = 1; cin >> l >> r >> k;
while(true) {
if(v >= l) cout << v << '\n';
if(r / k >= v) v *= k;
else break;
}
if(v < l) cout << -1 << '\n';
return 0;
}