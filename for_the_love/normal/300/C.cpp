#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const long long MOD = 1e9 + 7;
long long fact[1000005], a, b, n, i, ans;
int check(int n){
    while (n){
        if (n % 10 != a && n % 10 != b) return 0;
        n /= 10;
    }
    return 1;
}
long long power(long long a, long long b){
    if (b == 0) return 1;
    if (b == 1) return a;
    long long t = power(a, b / 2);
    t = (t * t) % MOD;
    if (b & 1) t = (t * a) % MOD;
    return t;
}
int main(){
    cin >> a >> b >> n;
    fact[0] = 1;
    for (i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % MOD;
    for (i = 0; i <= n; i++) if (check(i * a + (n - i) * b))
        ans = (ans + fact[n] * power((fact[i] * fact[n - i]) % MOD, MOD - 2) % MOD) % MOD;
    cout << ans << endl;
}