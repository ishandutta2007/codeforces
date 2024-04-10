#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
int n; cin >> n;
ll x0, x1, y0, y1;
cin >> x0 >> y0;
x1 = x0; y1 = y0;
for(int i = 1; i < n; i++) {
ll x, y; cin >> x >> y;
x0 = min(x0, x);
x1 = max(x1, x);
y0 = min(y0, y);
y1 = max(y1, y);
}
ll s = max(x1 - x0, y1 - y0);
cout << s * s << '\n';
return 0;
}