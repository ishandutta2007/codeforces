#include <bits/stdc++.h>
using namespace std;

int n, ans;
vector <int> a[2];
map <int,int> quantity[2];
long long cnt;

int main()
{
    ios::sync_with_stdio(0);
    int m, x, y;
    
    cin >> n >> m;
    while (m--)
    {
        cin >> x >> y;
        a[x].push_back(y);
        quantity[x][y]++;
    }
    
    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());
    
    for (int z = 0; z <= 1; z++)
    {
        if (a[z].size() >= 3) 
            ans = max(ans, (a[z].back() - a[z][0]) * 2);
        
        if (a[z].size() < 2) continue;
        
        for (int i = 0; i < int(a[z ^ 1].size()); i++)
            if (a[z][0] <= a[z ^ 1][i] && a[z ^ 1][i] <= a[z].back())
                ans = n * 2;
                
        if (a[z ^ 1].empty()) continue;
        
        for (int i = 0; i + 1 < int(a[z].size()); i++)
        {
            int x = a[z][i];
            int id = upper_bound(a[z ^ 1].begin(), a[z ^ 1].end(), x) - a[z ^ 1].begin();
            id--;
            if (id >= 0)
                ans = max(ans, (n - (x - a[z ^ 1][id])) * 2);
        }
        
        for (int i = 1; i < int(a[z].size()); i++)
        {
            int x = a[z][i];
            int id = lower_bound(a[z ^ 1].begin(), a[z ^ 1].end(), x) - a[z ^ 1].begin();
            if (id < int(a[z ^ 1].size()))
                ans = max(ans, (n - (a[z ^ 1][id] - x)) * 2);
        }
    }
    
    // pure case
    for (int z = 0; z <= 1; z++)
        if (a[z].size() >= 3 && (a[z].back() - a[z][0]) * 2 == ans)
        {
            int minCnt = 0, maxCnt = 0, otherCnt = 0;
            for (int i = 0; i < int(a[z].size()); i++)
                if (a[z][i] == a[z][0]) minCnt++;
                else
                    if (a[z][i] == a[z].back()) maxCnt++;
                    else otherCnt++;
                    
            if (!ans)
                cnt += minCnt * (minCnt - 1LL) * (minCnt - 2LL) / 6;
            else
            {
                cnt += 1LL * minCnt * maxCnt * otherCnt;
                cnt += minCnt * (minCnt - 1LL) / 2 * maxCnt;
                cnt += maxCnt * (maxCnt - 1LL) / 2 * minCnt;
            }
        }
    
    // mixed case
    if (ans == n * 2)
        for (int z = 0; z <= 1; z++)
            for (int i = 0; i < int(a[z].size()); i++)
            {
                if (a[z ^ 1].empty()) break;
                
                int x = a[z][i];
                int id = upper_bound(a[z ^ 1].begin(), a[z ^ 1].end(), x) - a[z ^ 1].begin();
                int idLess = upper_bound(a[z ^ 1].begin(), a[z ^ 1].end(), x - 1) - a[z ^ 1].begin();
                
                long long equal = id - idLess;
                long long bigger = a[z ^ 1].size() - id;
                    
                cnt += idLess * (bigger + equal);
                cnt += equal * (equal - 1LL) / 2;
                cnt += equal * bigger;
            }
    else
        for (int z = 0; z <= 1; z++)
        {
            if (a[z ^ 1].empty()) continue;
            
            for (int i = 0; i < int(a[z].size()); i++)
            {
                int x = a[z][i];
                int id = upper_bound(a[z ^ 1].begin(), a[z ^ 1].end(), x) - a[z ^ 1].begin();
                id--;
                if (id < 0) continue;
                
                int y = a[z ^ 1][id];
                if (ans == (n - (x - y)) * 2)
                    cnt += quantity[z ^ 1][y] * (a[z].size() - 1LL - i);
            }
            
            for (int i = 0; i < int(a[z].size()); i++)
            {
                int x = a[z][i];
                int id = lower_bound(a[z ^ 1].begin(), a[z ^ 1].end(), x) - a[z ^ 1].begin();
                if (id >= int(a[z ^ 1].size())) continue;
                
                int y = a[z ^ 1][id];
                if (ans == (n - (y - x)) * 2)
                    cnt += 1LL * quantity[z ^ 1][y] * i;
            }
        }
    
    cout << cnt << endl;
}