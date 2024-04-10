#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ull unsigned long long int
#define rep(i,a,b) for (ll i = a; i <= b; i++)
#define ren(i,a,b) for(ll i=b;i>=a;i--)
#define F first
#define S second
#define PB push_back
#define DB pop_back
#define MP make_pair
#define MT make_tuple
#define G(a,b) get<a>(b)
#define V(a) vector<a>
#define MOD 1000000007
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll powM(ll x,ll y,ll m)
{
    if(y==0) return 1;
    ll p=powM(x,y/2,m)%m;
    p=(p*p)%m;
    return (y%2==0)?p:(x*p)%m;
}
////////////////////

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int> v;
        rep(i,0,n-1)
        {
            if(s[i]=='0') v.PB(i);
        }
        //rep(i,0,v.size()-1) cout<<v[i]<<" ";
        rep(i,0,((ll)v.size())-1)
        {
            if(v[i]-i<=k)
            {
                k=k-(v[i]-i);
                v[i]=i;
            }
            else{
                v[i]=v[i]-k;
                break;
            }
        }
        //rep(i,0,v.size()-1) cout<<v[i]<<" ";
        ll j=0;
        rep(i,0,n-1)
        {                    
            if(j<((ll)v.size()) && v[j]==i)
            {
                cout<<0;
                j++;
            }
            else cout<<1;
        }
        cout<<endl;
    }
    return 0;
}