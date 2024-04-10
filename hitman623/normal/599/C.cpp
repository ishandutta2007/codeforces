#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    long n,a[100005],s[100005],i,c=0,m=0;
    map < long , set < long > > mp;
    cin>>n;
    for(i=0;i<n;++i)
    {cin>>a[i];
    mp[a[i]].insert(i);
    s[i]=a[i];}
    sort(s,s+n);
    for(i=0;i<n;++i)
    {
        m=max(m,*mp[s[i]].begin());
        mp[s[i]].erase(mp[s[i]].begin());
        if(m==i)
            c++;
    }
    cout<<c;
    return 0;
}