#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,N,i,B[101010];
void cek(ll aa)
{
    if(aa==1)
        return ;
    ll JUM=0;
    memset(B,0,sizeof(B));
    ll ii;
    for(ii=n;ii>=1;ii--)
    {
        if(aa-ii>=0)
        {
            aa-=ii;
            B[ii]=1;
            JUM++;
        }
    }
    if(aa>0||JUM==0||JUM==n)
        return ;
    vector<ll> v1,v2;
    for(ii=1;ii<=n;ii++)
        if(B[ii]==1)
            v1.pb(ii);
        else
            v2.pb(ii);
    cout<<"Yes\n";
    cout<<v1.size();
    for(ii=0;ii<v1.size();ii++)
        cout<<" "<<v1[ii];
    cout<<"\n";
    cout<<v2.size();
    for(ii=0;ii<v2.size();ii++)
        cout<<" "<<v2[ii];
    cout<<"\n";
    exit(0);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    N=(n+1)*(n);
    N/=2;
    for(i=1;i<=sqrt(N);i++)
    {
        if(N%i==0)
        {
            cek(i);
            cek(N/i);
        }
    }
    cout<<"No\n";
}