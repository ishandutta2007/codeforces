#include<bits/stdc++.h>
using namespace std;
int main() {
int n; cin >> n;
long long res = 9 * n - 3;
res <<= 2 * (n - 3);
cout << res << '\n';
}