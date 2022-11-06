#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define Mod 1000000007

LL a, b, ans;

int main()
{
    cin >> a >> b;
    LL v = (a * (1 + a) / 2) % Mod;
    LL t = b * v % Mod;
    LL u = (b * (b - 1) / 2) % Mod;
    ans = u * (a + t) % Mod;
    cout << ans << endl;
    return 0;
}