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

LL n, k;

int main()
{
    cin >> n >> k;
    if (k == 1)
    {
        cout << n;
        return 0;
    }
    else
    {
        LL p = 0;
        while (n >= 1) n/=2, p++;
        cout << (1LL<<p)-1;
    }
}