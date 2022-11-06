#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
ll n,i,a[1010],hz,d[1010][1010];
bool b[1010];
ll rmt(ll aa,ll bb)
{
    if(aa==2*n&&b[bb]==1)
        return 0;
    if(aa>=2*n)
        return -1000000000000000;
    if(d[aa][bb]==-1)
    {
        d[aa][bb]=max(rmt(aa+1,bb+1)-a[aa],rmt(aa+1,bb)+a[aa]);
    }
    return d[aa][bb];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    if(n%2==0)
    {
        for(i=0;i<=2*n-1;i=i+2)
            b[i]=1;
    }
    else
    {
        for(i=0;i<=2*n-1;i++)
            b[i]=1;
    }
    for(i=1;i<=n*2-1;i++)
    {
        cin>>a[i];
        hz=hz+a[i];
    }
    memset(d,-1,sizeof(d));
    cout<<rmt(1,0)<<"\n";
}