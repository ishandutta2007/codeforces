#include <bits/stdc++.h>
using namespace std;

int n, region[100100];
long long totalLen[100100];
vector <int> v[100100];

int get(int x)
{
    return x == region[x] ? x : region[x] = get(region[x]);
}

int main()
{
    //freopen("d.in", "r", stdin);
    int m, P, Q, x, y, z;
    cin >> n >> m >> P >> Q;
    
    for (int i = 1; i <= n; i++) region[i] = i; 
    
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        x = get(x); y = get(y);
        if (x != y) 
        {
            region[y] = x; 
            totalLen[x] += totalLen[y];
        }
        totalLen[x] += z;
    }
    
    set < pair<long long,int> > s;
    for (int i = 1; i <= n; i++)
        if (get(i) == i)
            s.insert(make_pair(totalLen[i], i));
            
    int difRegionEdge = int(s.size()) - Q, sameRegionEdge = P - difRegionEdge;
    
    if (int(s.size()) < Q || P < difRegionEdge)
    {
        cout << "NO\n";
        return 0;
    }
            
    vector < pair<int,int> > ans;
    while (difRegionEdge--)
    {
        int x = s.begin() -> second;
        s.erase(s.begin());
        
        int y = s.begin() -> second;
        s.erase(s.begin());
        
        ans.push_back(make_pair(x, y));
        
        region[y] = x;
        long long len = min(totalLen[x] + totalLen[y] + 1, 1000000000LL);
        totalLen[x] += totalLen[y] + len;
        
        s.insert(make_pair(totalLen[x], x));
    }
    
    for (int i = 1; i <= n; i++) v[get(i)].push_back(i);
    x = 0; y = 0;
    for (int i = 1; i <= n; i++)
        if (v[i].size() > 1)
        {
            x = v[i][0]; y = v[i][1];
            break;
        }
        
    if (!x && sameRegionEdge)
    {
        cout << "NO\n";
        return 0;
    }
    
    while (sameRegionEdge--) ans.push_back(make_pair(x, y));
    
    cout << "YES\n";
    for (int i = 0; i < int(ans.size()); i++) cout << ans[i].first << ' ' << ans[i].second << endl;
}