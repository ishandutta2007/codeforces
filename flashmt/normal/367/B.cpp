#include <bits/stdc++.h>
using namespace std;

int n, m, p, a[200200], b[200200], cntB[200200], cntA[200200];

int main()
{
    vector <int> X;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i], X.push_back(b[i]);
    
    if (n < m)
    {
        cout << 0 << endl;
        return 0;
    }
    
    if (m == 1)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++) cnt += (a[i] == b[1]);
        cout << cnt << endl;
        for (int i = 1; i <= n; i++)
            if (a[i] == b[1]) cout << i << ' ';
        return 0;
    }
    
    sort(X.begin(), X.end());
    X.resize(unique(X.begin(), X.end()) - X.begin());
    
    for (int i = 1; i <= n; i++)
    {
        int id = lower_bound(X.begin(), X.end(), a[i]) - X.begin();
        if (id < int(X.size()) && X[id] == a[i]) a[i] = id;
        else a[i] = int(X.size());
    }
    
    for (int i = 1; i <= m; i++)
    {
        b[i] = lower_bound(X.begin(), X.end(), b[i]) - X.begin();
        cntB[b[i]]++;
    }
        
    vector <int> ans;   
    for (int r = 1; r <= p && r <= n; r++)
    {
        int match = 0;
        for (int i = r; i <= n; i += p)
        {
            if (cntB[a[i]] > cntA[a[i]]) match++;
            cntA[a[i]]++;
            
            long long j = i - 1LL * m * p;
            if (j > 0)
            {
                if (cntB[a[j]] >= cntA[a[j]]) match--;
                cntA[a[j]]--;
            }
            
            if (match == m) ans.push_back(j + p);
        }
        
        for (int i = r; i <= n; i += p) cntA[a[i]] = 0;
    }
    
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < int(ans.size()); i++) cout << ans[i] << ' ';
}