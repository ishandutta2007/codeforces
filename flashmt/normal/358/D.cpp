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
const int oo = 1 << 29;

int f[3333][2], n, a[3333], b[3333], c[3333];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    
    if (n == 1)
    {
        cout << a[1] << endl;
        return 0;
    }
    
    for (int i = 0; i <= n; i++) f[i][0] = f[i][1] = -oo;
    f[2][0] = a[1];
    f[2][1] = b[1];
    
    for (int i = 3; i <= n; i++)    
    {
        f[i][0] = max(f[i - 1][0] + b[i - 1], f[i - 1][1] + a[i - 1]);
        f[i][1] = max(f[i - 1][0] + c[i - 1], f[i - 1][1] + b[i - 1]);
    }
    
    cout << max(f[n][0] + b[n], f[n][1] + a[n]) << endl;
}