#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 
 
 using namespace std;
 
template <typename T> T extGcd(T a, T b, T& x, T& y);
template <typename T> T modInv(T a, T m);
 
const int mod = 1000000007;
 long long n,m,k;

int modpow(int b, long long e) {
    int r = 1;
    while (e) {
        if (e&1) r = (r*1ll*b) % mod;
        b = (b*1ll*b) % mod;
        e >>= 1;
    }
    return r;
}

 int main() {
     scanf("%lld %lld %lld", &n, &m, &k);
     if (k == -1 && n % 2 != m % 2) {
         printf("0\n");
         return 0;
     }

     int ans = modpow(modpow(2, n-1), m-1);
     printf("%d\n",ans);
 }