#include<bits/stdc++.h>

using namespace std;

int main() {
long long n, a, b; cin >> n >> a >> b;
for(int i = 0; i < n; i++) {
long long x; cin >> x;
long long v = x * a / b;
long long y = (v * b + a - 1) / a;
cout << x - y << '\n';
}
return 0;
}