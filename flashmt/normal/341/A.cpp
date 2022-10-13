#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

long long gcd(long long x, long long y)
{
    return x && y ? gcd(y, x % y) : x + y;
}

int main()
{
    int n, a[100100];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    
    long long totalDist = 0, sumDist = 0;
    for (int i = 1; i <= n; i++)
    {
        totalDist += a[i];
        totalDist += ((i - 1LL) * a[i] - sumDist) * 2;
        sumDist += a[i];
    }
    
    long long g = gcd(totalDist, n);
    cout << totalDist / g << ' ' << n / g << endl;
}