#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long h=1e9+7;
long po(long a,long b)
{
    if(a==0) return 0;
    if(b==0 || a==1) return 1;
    long m=po(a,b/2);
    if(b%2) return (((m*m)%h)*a)%h;
    return (m*m)%h;
}
int main()
{
    io
    ml mp;
    ml ::iterator it;
    long n,x,i,a[100005],cur=0,f,d,j,t;
    cin>>n>>x;
    for(i=0;i<n;++i)
    {
        cin>>a[i];
        cur+=a[i];
    }
    for(i=0;i<n;++i)
    mp[cur-a[i]]++;
    for(it=mp.begin();it!=mp.end();it++)
    {
        d=it->y;
        j=0;
        while(d%x==0)
        {
            j++;
            d/=x;
        }
        if(j!=0)
        mp[it->x+j]+=d;
        else
        {cur=min(cur,it->x);break;}
    }
    cout<<po(x,cur%(h-1));
    return 0;
}