#include<iostream>
#include<cstdio>
#include<set>
#include<cmath>
using namespace std;
int n,s1,s2,a[100001],ans;
set<int> s;
inline bool check(int d)
{
    s.clear();
    s.insert(s1);
    s.insert(s2);
    for(int i=1;i<=n;++i)
    {
        while(!s.empty()&&a[i]-*s.begin()>d)
            s.erase(s.begin());
        while(!s.empty()&&*--s.end()-a[i]>d)
            s.erase(--s.end());
        if(s.empty())
            return 0;
        s.insert(a[i]);
    }
    return 1;
}
int main()
{
    cin>>n>>s1>>s2;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    int l=abs(s1-s2),r=1e9,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}