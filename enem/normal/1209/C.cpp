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
namespace std {
template <> struct hash<std::pair<int, int>> {
    inline size_t operator()(const std::pair<int, int> &v) const {
        std::hash<int> int_hasher;
        return int_hasher(v.first) ^ int_hasher(v.second);}};}
////////////////////

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
    int n;
    cin>>n;
    string s,t;
    cin>>s;
    t=s;
    sort(t.begin(),t.end());
    int j=0,a[n],flag=1;
    char lt1,lt2='0';
    rep(i,0,n-1)
    {
        if(s[i]==t[j])
        {
            a[i]=1;
            lt1=s[i];
            j++;
        }
        else a[i]=0;
    }
    //cout<<lt1<<endl;
    rep(i,0,n-1)
    {
        if(a[i]!=1)
        {
            if(s[i]>=lt2 && s[i]>=lt1)
            {
              a[i]=2;
              lt2=s[i];
            }
            else 
            {
              flag=0;
              break;
            } 
        }
    }
    if(flag==0) cout<<"-"<<endl;
    else 
    {
        rep(i,0,n-1) cout<<a[i];
        cout<<endl;
    }
    }
  return 0;
}