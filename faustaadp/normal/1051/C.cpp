#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[1010],d[1010],h[1010],X,N;
vector<ll> v;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
        cin>>a[i];
        d[a[i]]++;
	}
	for(i=1;i<=n;i++)
        if(d[a[i]]==1)
            v.pb(i);
    for(i=1;i<=n;i++)
    {
        if(d[a[i]]>=3)
            X=i;
        d[a[i]]=0;
    }
    N=v.size();
    for(i=0;i<N/2;i++)
        h[v[i]]=1;
    if(N%2==0)
    {
        cout<<"YES\n";
    }
    else
    {
        if(X==0)
        {
            cout<<"NO\n";
            return 0;
        }
        else
        {
            cout<<"YES\n";
            h[X]=1;
        }
    }
    for(i=1;i<=n;i++)
        if(h[i])
            cout<<'B';
        else
            cout<<'A';
    cout<<"\n";
}