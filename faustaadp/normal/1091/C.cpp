#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i;
unordered_map<ll,ll> B;
vector<ll> v;
void  cek(ll aa)
{
    ll K=n/aa;
    ll H=K;
    K=((K*(K-1))/2)*aa;
    H+=K;
    if(B[H])return ;
    //cout<<aa<<" "<<H<<"\n";
    B[H]=1;
    v.pb(H);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(i=1;i<=sqrt(n);i++)
    {
        if(n%i!=0)continue;
        ll X=i;
        ll Y=n/i;
        cek(X);
        cek(Y);
    }
    ll VS=v.size();
    sort(v.begin(),v.end());
    for(i=0;i<VS;i++)
    {
        if(i<(VS-1))cout<<v[i]<<" ";
        else cout<<v[i]<<"\n";
    }
}