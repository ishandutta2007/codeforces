#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define SZ(a) a.size()
#define LL long long

LL n, h;
int num = 0;

LL solve(LL n)
{
    h = n;
    LL zzz = 1;
    while (n > 9)
    {
        num++;
        n /= 10;
        zzz *= 10;
    }
    int q = (h+1-(n+1)*zzz == 0);
    if (n >= 5) return h - 5*zzz + 1 - (q&(n==9));
    if (num == 0) return n*(n-1)/2;
    LL n1 = (h-zzz*n+1);
    LL n2 = zzz-n1;
    
    if (n1 >= n2)
    {
        return n*(n+1)*n2 + (n+1)*(n+1)*(n1-n2)/2 - n - q;
    }
    else
    {
        return n*(n+1)*n1 + n*n*(n2-n1)/2 - n - q;
    }
}


int main()
{
    cin >> n;
    cout << solve(n);
}