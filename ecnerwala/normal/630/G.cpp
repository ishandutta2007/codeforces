#include<bits/stdc++.h>
using namespace std;
int main() {
long long n; cin >> n;
long long r1 = (n + 4) * (n + 3) * (n + 2) * (n + 1) * (n + 0) / 120;
long long r2 = (n + 2) * (n + 1) * (n + 0) / 6;
cout << r1 * r2 << '\n';
}