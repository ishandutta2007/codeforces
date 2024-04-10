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
#include <iomanip>
using namespace std;



int main()
{
    int n,d;
    cin >> n >> d;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    sort (a,a+n);
    int res = 0,i=0;
    for (; i < m && i < n; ++i)
        res += a[i];

    if (i < m)
        res -= d * (m-i);

    cout << res;

    return 0;
}