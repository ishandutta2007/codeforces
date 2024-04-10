#include<bits/stdc++.h>
using namespace std;

int main() {
long long n; cin >> n;
long long res = n * (n - 1) * (n - 2) * (n - 3) * (n - 4);
res /= 120;
res *= res;
res *= 120;
cout << res << '\n';
}