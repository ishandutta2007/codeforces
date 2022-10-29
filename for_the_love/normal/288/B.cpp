#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const long long MOD = 1e9 + 7;
long long n, k, ans, i;
int main(){
    cin >> n >> k;
    ans = 1;
    for (i = 1; i <= k - 1; i++) ans = (ans * k) % MOD;
    for (i = k + 1; i <= n; i++) ans = (ans * (n - k)) % MOD;
    cout << ans << endl;
}