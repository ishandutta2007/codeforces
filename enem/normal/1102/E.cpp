#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int a[n];
    map<int, vector<int>> mp;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        mp[a[i]].push_back(i);
    }

    int k=-1;
    int r=0;
    for(int i=0; i<n; i++)
    {
        r=max(r, mp[a[i]].back());

        if(i==r) k++;
    }

    int ans=1;
    int x=2;
    while(k)
    {
        if(k&1) ans=1LL*ans*x%998244353;
        x=1LL*x*x%998244353;
        k>>=1;
    }

    cout<<ans;

    return 0;
}