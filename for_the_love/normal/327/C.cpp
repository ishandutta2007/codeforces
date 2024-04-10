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

long long k, t, ans, n;
string s;
long long power(long long a, long long b){
    if (!b) return 1;
    if (b == 1) return a;
    long long tmp = power(a, b / 2);
    tmp = tmp * tmp % MOD;
    if (b & 1) tmp = tmp * a % MOD;
    return tmp;
}
int main(){
    cin >> s;
    cin >> k;
    n = s.size();
    t = (power(2, n * k) - 1) * power((power(2, n) - 1), MOD - 2) % MOD;
    for (long long i = 0; i < s.size(); i++)
    if (s[i] == '0' || s[i] == '5') ans = (ans + power(2, i) * t) % MOD;
    cout << ans << endl;
}