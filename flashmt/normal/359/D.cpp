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

int a[300300], divisor[300300][20], n, lg2[600300];

int gcd(int x, int y)
{
    return x && y ? gcd(y, x % y) : x + y;
}

int getGcd(int l, int r)
{
    int j = lg2[r - l + 1];
    return gcd(divisor[l][j], divisor[r - (1 << j) + 1][j]);
}

int main()
{
    //freopen("d.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) divisor[i][0] = a[i];
    
    for (int j = 0; 1 << j + 1 <= n; j++)
        for (int i = 0; i + (1 << j) < n; i++)
            divisor[i][j + 1] = gcd(divisor[i][j], divisor[i + (1 << j)][j]);
            
    for (int i = 0; 1 << i <= 300000; i++)
        for (int j = 1 << i; j < 1 << i + 1; j++)
            lg2[j] = i;
            
    set <int> ans;
    int maxLen = -1;
            
    for (int i = 0; i < n; i++)
    {
        int low = 0, high = i - 1;
        int leftmost = i;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (getGcd(mid, i) == a[i]) leftmost = mid, high = mid - 1;
            else low = mid + 1;
        }
        
        low = i + 1; high = n - 1;
        int rightmost = i;
        while (low <= high) 
        {
            int mid = (low + high) / 2;
            if (getGcd(i, mid) == a[i]) rightmost = mid, low = mid + 1;
            else high = mid - 1;
        }
        
        if (rightmost - leftmost == maxLen) ans.insert(leftmost + 1);
        else
            if (rightmost - leftmost > maxLen)
            {
                maxLen = rightmost - leftmost;
                ans.clear();
                ans.insert(leftmost + 1);
            }
    }
    
    cout << ans.size() << ' ' << maxLen << endl;
    for (set <int>::iterator it = ans.begin(); it != ans.end(); it++)
        cout << *it << ' ';
}