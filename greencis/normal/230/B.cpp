#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int n;
long long a;

inline bool isPrime(int x) {
    if (x<=1) return false;
    int sq = sqrt(x);
    for (int i = 2; i <=sq;++i)
        if (x % i == 0) return false;
    return true;
}

int main()
{
    scanf("%d",&n);
    while (n--) {
        scanf("%I64d",&a);
        long long q = sqrt(a);
        if (q*q != a) { printf("NO\n"); continue; }
        if (isPrime((int)q)) { printf("YES\n"); }
        else printf("NO\n");
    }
    return 0;
}