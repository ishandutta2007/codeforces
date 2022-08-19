#include<bits/stdc++.h>
using namespace std;

int main() {
long long n; cin >> n;
long long ans = 0;
while ((ans / 2) * (ans - ans / 2) < n) ans++;
cout << ans << '\n';
}