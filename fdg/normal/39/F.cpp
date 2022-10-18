#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    vector <int> a(m,0),b(k,0);
    for(int i=0;i<m;i++)
        cin >> a[i];
    for(int i=0;i<k;i++)
        cin >> b[i];
    int mn=k;
    for(int i=0;i<m;i++)
    {
        int cur=0;
        for(int j=0;j<k;j++)
            if (b[j]%a[i]==0) cur++;
        if (cur<mn) mn=cur;
    }
    vector <int> ans;
    for(int i=0;i<m;i++)
    {
        int cur=0;
        for(int j=0;j<k;j++)
            if (b[j]%a[i]==0) cur++;
        if (cur==mn) ans.push_back(i+1);
    }
    cout << ans.size() << endl;
    if (ans.size()>0)
    {
        cout << ans[0];
        for(int i=1;i<ans.size();i++)
            cout << " " << ans[i];
        cout << endl;
    }
    return 0;
}