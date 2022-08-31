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
int rec(string &s,int l,int r,char c)
{
    //cout<<l<<" "<<r<<" "<<c<<'\n';
    char nx=++c; c--;
    if(r==l)
    {
        if(s[l]==c) return 0;
        else return 1;
    }
    int a=0,b=0,m=l+(r-l)/2;
    rep(i,l,m) if(s[i]!=c) a++;
    a+=rec(s,m+1,r,nx);
    rep(i,m+1,r) if(s[i]!=c) b++;
    b+=rec(s,l,m,nx);
    return min(a,b);
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        s='.'+s;
        if(n==1){
            if(s[1]=='a')
            {
                cout<<0<<'\n';
                continue;
            }
            else{
                cout<<1<<'\n';
                continue;
            }
        }
        cout<<rec(s,1,n,'a')<<'\n';
    }
    return 0;
}