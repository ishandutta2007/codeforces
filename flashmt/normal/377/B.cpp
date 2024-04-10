#include <bits/stdc++.h>
using namespace std;

struct Student
{
    int level, cost, id;
    
    bool operator < (Student u) const
    {
        return level > u.level || (level == u.level && cost < u.cost);
    }
};

int n, m, budget, worked[100100], inCharge[100100];
pair <int,int> bug[100100];
Student student[100100];

int possible(int days)
{
    set < pair <int,int> > q;
    long long totalCost = 0;
    
    for (int i = 0; i < n; i++) worked[i] = 0;
    
    for (int i = 0, j = 0; i < m; i++)
    {
        while (j < n && student[j].level >= bug[i].first) 
        {
            q.insert(make_pair(student[j].cost, j));
            j++;
        }
        
        if (q.empty()) return 0;
            
        int x = q.begin() -> second;
        inCharge[bug[i].second] = student[x].id;
        
        if (!worked[x]++) 
        {
            totalCost += student[x].cost;
            q.erase(q.begin());
            q.insert(make_pair(0, x));
        }
        
        if (worked[x] == days) q.erase(q.begin());
    }
    
    return totalCost <= budget;
}

int main()
{
    ios::sync_with_stdio(0);
    
    cin >> n >> m >> budget;
    for (int i = 0; i < m; i++) cin >> bug[i].first, bug[i].second = i;
    for (int i = 0; i < n; i++) cin >> student[i].level;
    for (int i = 0; i < n; i++) cin >> student[i].cost;
    for (int i = 0; i < n; i++) student[i].id = i;
    
    sort(bug, bug + m, greater< pair<int,int> >());
    sort(student, student + n);
    
    int ans = 0, low = 1, high = m;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (possible(mid)) ans = mid, high = mid - 1;
        else low = mid + 1;
    }
    
    if (!ans) cout << "NO\n";
    else 
    {
        cout << "YES\n";
        possible(ans);
        for (int i = 0; i < m; i++) cout << inCharge[i] + 1 << (i == m - 1 ? '\n' : ' ');
    }
}