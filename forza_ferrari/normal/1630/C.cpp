#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[200001],ans;
pair<int,int> p[200001];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(!p[a[i]].first)
            p[a[i]].first=i;
        p[a[i]].second=i;
    }
    sort(p+1,p+n+1);
    int lst=0;
    for(int i=1;i<=n;++i)
    {
        if(!p[i].first||p[i].first==p[i].second)
            continue;
        if(p[i].first>=lst)
            ans+=(lst=p[i].second)-p[i].first-1;
        else
        {
            int r=p[i].second;
            while(i<n&&p[i+1].first<lst)
                r=max(r,p[++i].second);
            if(r>lst)
            {
                ans+=r-lst-1;
                lst=r;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}