#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <unordered_map>
#include <cassert>


using namespace std;


int n;
#define Mod 1000000007


int powm(int a, long long x) {
    if (x == 0) {
        return 1;
    } else {
        if (x & 1LL) {
            return (1LL * powm(a, x - 1LL) * a) % Mod;
        } else {
            int b = powm(a, x / 2LL);
            return (1LL * b * b) % Mod;
        }
    }
}


long long a[100001];


int main() {
    cin >> n;
    bool b = 0;
    bool b1 = 0;
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
        if (a[i] != 1LL) {
            b = 1;
        }
        if (a[i] % 2LL == 0LL) {
            b1 = 1;
        }
    }
    if (!b) {
        cout << "0/1" << endl;
        return 0;
    }
    if (!b1) {
        int ans = 2;
        for (int i = 0; i < n; i++) {
            ans = powm(ans, a[i]);
        }
        ans = (1LL * ans * powm(2, Mod - 2)) % Mod;
        int st = ans;
        ans--;
        if (ans < 0) {
            ans += Mod;
        }
        //cout << ans << endl;
        ans = (1LL * ans * powm(3, Mod - 2)) % Mod;
        cout << ans << '/' << st << endl;
    } else {
        int ans = 2;
        for (int i = 0; i < n; i++) {
            ans = powm(ans, a[i]);
        }
        //cout << ans << endl;
        ans = (1LL * ans * powm(2, Mod - 2)) % Mod;
        int st = ans;
        ans++;
        if (ans >= Mod) {
            ans -= Mod;
        }
        //cout << ans << endl;
        ans = (1LL * ans * powm(3, Mod - 2)) % Mod;
        cout << ans << '/' << st << endl;
    }
    return 0;
}