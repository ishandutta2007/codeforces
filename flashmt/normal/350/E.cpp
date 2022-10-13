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

void construct(vector <int> v, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (!m) break;
            else printf("%d %d\n", v[i], v[j]), m--;
}

int main()
{
    int n, m, k, a[333], marked[333] = {0};
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) cin >> a[i], marked[a[i]] = 1;
    
    if (k == n) 
    {
        puts("-1");
        return 0;
    }

    int mid;
    for (int i = 1; i <= n; i++)
        if (!marked[i]) 
        {
            mid = i; break;
        }
        
    if ((n - 2) * (n - 3) / 2 + n - 1 + n - k - 1 < m) 
    {
        puts("-1");
        return 0;
    }

    m -= (n - 1);
    int mm = min(n - k - 1, m);
    m -= mm;
    vector <int> v;
    int other = 0;
    
    for (int i = 1; i <= n; i++)
        if (marked[i]) other = i;
        
    cout << other << ' ' << mid << endl;
    
    for (int i = 1; i <= n; i++)
        if (i != mid && i != other)
        {
            v.push_back(i);
            cout << i << ' ' << mid << endl;
        }
        
    for (int i = 1; i <= n; i++)
        if (!marked[i] && i != mid && mm)
        {
            cout << other << ' ' << i << endl;
            mm--;
        }
        
    construct(v, n - 2, m);
}