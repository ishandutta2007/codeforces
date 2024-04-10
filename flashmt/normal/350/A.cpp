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

int main()
{
    int n, m, x, maxAC = 0, minAC = 278, minWA = 278;
    cin >> n >> m;
    
    while (n--)
    {
        cin >> x;
        maxAC = max(maxAC, x);
        minAC = min(minAC, x);
    }
    
    while (m--)
    {
        cin >> x;
        minWA = min(minWA, x);
    }
    
    if (max(maxAC, minAC * 2) < minWA) cout << max(maxAC, minAC * 2) << endl;
    else puts("-1");
}