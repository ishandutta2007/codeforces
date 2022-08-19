#include<bits/stdc++.h>

using namespace std;

int main() {
int a, b, c;cin >> a >> b >> c;
int v = max(a * b, a + b);
v = max(v * c, v + c);
int l = max(b * c, b + c);
l = max(l * a, l + a);
cout << max(v,l)<<'\n';
return 0;
}