#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <iomanip>
using namespace std;

int n,a[105],res = 0;

int gcd(int a, int b) {
    return b ? gcd(b , a%b) : a;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    res = a[0];
    for (int i = 1; i < n; ++i)
        res = gcd(res,a[i]);
    cout << res*n;

    return 0;
}