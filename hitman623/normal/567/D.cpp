#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll n,k,a,m,x[200005],c=0,i,f=0;
long calc(long x,long y)
{
    return (y-x-1)/(a+1)+(y-x-1-((y-x-1)/(a+1))*(a+1))/a;
}
int main()
{
    cin>>n>>k>>a>>m;
    set < ll > s;
    set < ll > ::iterator l,u;
    for(i=0;i<m;++i)
    cin>>x[i];
    s.insert(0);
    s.insert(n+1);
    c=calc(0,n+1);
    for(i=0;i<m;i++)
    {
       s.insert(x[i]);
       l=s.find(x[i]);
       u=l;
       l--;u++;
       c=c-calc(*l,*u)+calc(*l,x[i])+calc(x[i],*u);
       if(c<k)
       {cout<<i+1;f=1;break;}
    }
    if(!f) cout<<-1;
    return 0;
}