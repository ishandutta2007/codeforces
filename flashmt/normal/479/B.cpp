#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n, k, a[111];
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    vector < pair <int,int> > res;
    for (int i = 0; i < k; i++)
    {
        int idMin = 1, idMax = 1;
        for (int j = 1; j <= n; j++)
        {
            if (a[j] > a[idMax]) idMax = j;
            if (a[j] < a[idMin]) idMin = j;
        }
        
        if (a[idMax] - a[idMin] < 2) break;
        res.push_back(make_pair(idMax, idMin));
        a[idMax]--;
        a[idMin]++;
    }
    
    cout << *max_element(a + 1, a + n + 1) - *min_element(a + 1, a + n + 1) << ' ' << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
    	cout << res[i].first << ' ' << res[i].second << endl;
}