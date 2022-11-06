#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

LL n, m, t;

int main()
{
    cin >> n >> m;
    LL t = ((m - n % m) * (n / m) * (n / m - 1) >> 1) + ((n % m) * (n / m + 1) * (n / m) >> 1);
    cout << t << endl;
    t = (n - m) * (n - m + 1) >> 1;
    cout << t << endl;
    return 0;
}