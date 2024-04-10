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
const long long MOD = 1000000007;
//int n, x, i, a[10000], b[10000], j, ans;
long long p[10000], n, i, ans;
string s;
int main(){
    p[0] = 1;
    for (i = 1; i <= 1000; i++) p[i] = (p[i - 1] * 2) % MOD;
    cin >> s;
    n = s.size();

    for (i = n - 1; i >= 0; i--)
    if (s[i] == '1') ans = (ans + p[2 * n - i - 2]) % MOD;
    cout << ans << endl;
    /*while (1){
    cin >> n;
    cin >> x;
    for (i = 0; i < (1 << n); i++){
        a[i] = i;
        b[i] = i ^ x;
    }
    ans = 0;
    for (i = 0; i < (1 << n); i++)
    for (j = 0; j < (1 << n); j++)
    if (a[i] < a[j] && b[j] < b[i]) ans++;
    cout << ans << endl;
    }*/
}