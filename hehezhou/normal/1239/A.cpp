#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int f[100010];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    f[0] = f[1] = 1;
    for(int i = 2; i <= max(n, m); i++) f[i] = (f[i - 1] + f[i - 2]) % mod;
    return cout << ((f[n] + f[m]) % mod * 2 % mod - 2 + mod) % mod << endl, 0;
}