#include <bits/stdc++.h>
#define pb push_back
#define long long long
using namespace std;
long calc(vector < long > v)
{
    long i,n=v.size(),ans=0;
    for(i=0;i<n;++i)
    ans=ans*10+v[i];
    return ans;
}
long solve(long x,long y ,long n)
{
    long i,j,k,c=0,num;
    vector < long > v;
    if(x!=y)
    {
    for(i=1;i<=10;++i)
    for(j=1;j<=10-i;++j)
    {
        v.clear();
        for(k=0;k<i;++k)
        v.pb(x);
        for(k=0;k<j;++k)
        v.pb(y);
        do
        {
            if(v[0]==0) continue;
            num=calc(v);
            if(num<=n) c++;
        }
        while(next_permutation(v.begin(),v.end()));
    }
    return c;
    }
    else
    {
        if(x==0) return 0;
        for(i=1;i<=10;++i)
        {
            v.clear();
            for(j=0;j<i;++j)
            v.pb(x);
            if(calc(v)<=n) c++;
        }
        return c;
    }
}
int main()
{
    long n,i,j,ans=0;
    cin>>n;
    for(i=0;i<10;++i)
    for(j=i;j<10;++j)
    ans+=solve(i,j,n);
    cout<<ans;
    return 0;
}