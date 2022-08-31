#include<bits/stdc++.h>
#define re register
#define ll long long
#define inf 0x3f3f3f3f
#define iinf 0x3f3f3f3f3f3f3f3fll
using namespace std;
ll n,a[1000005],l[1000005],r[1000005],maxx=-iinf;
stack<ll>s1,s2;
int main()
{
    scanf("%lld",&n);
    for(re int i=1;i<=n;++i)scanf("%lld",&a[i]);
    for(re int i=n;i>=1;i--)
    {
        while(s1.empty()==0&&a[s1.top()]<a[i])s1.pop();
        l[i]=s1.empty()?n+1ll:s1.top();
        s1.push(i);
    }
    for(re int i=1;i<=n;++i)
    {
        while(s2.empty()==0&&a[s2.top()]<a[i])s2.pop();
        r[i]=s2.empty()?0ll:s2.top();
        s2.push(i);
    }
    for(re int i=1;i<=n;++i)
    {
        if(l[i]!=n+1)maxx=max(maxx,a[i]^a[l[i]]);
        if(r[i])maxx=max(maxx,a[i]^a[r[i]]);
    }
    printf("%lld",maxx);
    return 0;
}