#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
using namespace std;
const int MOD = 1000000007;

long long gcd(long long x,long long y){if (!y) return x; return gcd(y, x % y);}
long long n, ans, a[111111];
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        ans += a[i];
    }
    sort(a + 1,a + n + 1);
    for(long long i = n; i >= 1; i--)
        ans += (a[i] * 2 * (i - 1) - a[i] * 2 * (n - i));
    long long g = gcd(ans,n);
    cout << ans / g <<' ' << n / g << endl;
}