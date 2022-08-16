#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define VLL vector<ll>
#define PB push_back

int main()
{
    ll n;
    cin>>n;
    VLL o[65];
    REP(i,0,n)
    {
        ll t;
        cin>>t;
        o[__builtin_ctzll(t)].PB(t);
    }
    ll maxi=0;
    REP(i,0,65)
    {
        if(o[i].size()>o[maxi].size()) maxi=i;
    }
    cout<<n-o[maxi].size()<<'\n';
    REP(i,0,65)
    {
        if(i!=maxi)
        {
            REP(j,0,o[i].size())cout<<o[i][j]<<' ';
        }
    }

    return 0;
}