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


long long n, a, b, p, q;


long long gcd(long long a, long long b) {
    if (a == 0LL) {
        return b;
    }
    return gcd(b % a, a);
}


int main() {
    cin >> n >> a >> b >> q >> p;
    long long ans = max(1LL * (n / a) * q + 1LL * (n / b - n / (a * b / gcd(a, b))) * p, 1LL * (n / b) * p + 1LL * (n / a - n / (a * b / gcd(a, b))) * q);
    cout << ans << endl;
    return 0;   
}