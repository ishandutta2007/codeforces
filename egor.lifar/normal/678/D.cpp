#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>



using namespace std;


#define Mod 1000000007LL
unsigned long long n, a, b, x;


unsigned long long powm(unsigned long long x, unsigned long long n) {
    if (x == 0) {
        return 1;
    }
    if (n == 0) {
        return 1;
    } else {
        if (n % 2 == 1) {
            unsigned long long s = powm(x, n - 1);
            return (1LL * s * x) % Mod;
        } else {
            unsigned long long s = powm(x, n / 2);
            return (1LL * s * s) % Mod;
        }
    }
}


int main() {
    cin >> a >> b >> n >> x;
    unsigned long long ans = (1LL * powm(a, n) * x) % Mod;
   // cout << ans << endl;
    if (n == 1) {
        ans += b;
        ans %= Mod;
    } else {
        if (a == 1) {
            ans += (1LL * b * (n % Mod)) % Mod;
            ans %= Mod;
        } else {
            ans += (((1LL * b * (powm(a, n) - 1)) % Mod) * powm(a - 1, Mod - 2)) % Mod;
            ans %= Mod;
        }   
    }
    cout << ans << endl;
    return 0;       
}