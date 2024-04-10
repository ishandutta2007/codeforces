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

int n, m, sharedBudget, budget[100100], price[100100];

int main()
{
    //freopen("d.in", "r", stdin);
    cin >> n >> m >> sharedBudget;
    for (int i = 1; i <= n; i++) cin >> budget[i];
    for (int i = 1; i <= m; i++) cin >> price[i];
    
    sort(budget + 1, budget + n + 1);
    sort(price + 1, price + m + 1);
    
    int low = 1, high = min(m, n), ans = 0;
    long long personalBudget = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        
        long long totalPrice = 0, totalBudget = sharedBudget;
        for (int i = 1; i <= mid; i++) 
        {
            totalPrice += price[i];
            totalBudget += min(budget[n - mid + i], price[i]);
        } 
        
        if (totalBudget >= totalPrice)
        {
            ans = mid; 
            low = mid + 1;
            personalBudget = totalPrice - sharedBudget;
        }
        else high = mid - 1;
    }
    
    cout << ans << ' ' << max(personalBudget, 0LL) << endl;
}