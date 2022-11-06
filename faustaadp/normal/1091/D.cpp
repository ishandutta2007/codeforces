#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[110],j,has,X[110],H1=1,K=1,mo=998244353;
vector<ll> v;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    ll F=1;
    for(i=1;i<=n;i++)F=(F*i)%mo;
    for(i=1;i<=n;i++)
    {
        H1=(H1+F-K+mo)%mo;
        K=(K*(n-i+1))%mo;
    }
    cout<<H1<<"\n";
}