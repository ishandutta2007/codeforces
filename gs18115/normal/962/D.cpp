#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > x;
long long n,i,a[234567],p,q,r,s,cnt,cnt2;
int main()
{
    scanf("%I64d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        pair<int,int> pp(a[i],i);
        x.push(pp);
    }
    while(cnt<n-1)
    {
        p=x.top().first;
        q=x.top().second;
        x.pop();
        cnt++;
        r=x.top().first;
        s=x.top().second;
        if(p==r)
        {
            a[q]=-1;
            a[s]=p*2;
            x.pop();
            pair<long long,long long> pp(p*2,s);
            x.push(pp);
        }
        else
        {
            while(cnt<n&&x.top().first!=p)
            {
                p=x.top().first;
                q=x.top().second;
                x.pop();
                cnt++;
            }
            pair<long long,long long> pp(p,q);
            x.push(pp);
            cnt--;
        }
    }
    for(i=0;i<n;i++)
    {
        if(a[i]!=-1)cnt2++;
    }
    printf("%I64d\n",cnt2);
    for(i=0;i<n;i++)
    {
        if(a[i]!=-1)printf("%I64d ",a[i]);
    }
    return 0;
}