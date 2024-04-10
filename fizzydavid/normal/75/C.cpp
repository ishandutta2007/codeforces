//while(true)rp++;
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int a,b,n;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
vector<int>v;
int bs(int x)
{
    int l=0,r=v.size()-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(v[mid]<=x)l=mid+1;
        else r=mid-1;
    }
    return r;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>a>>b;
    int t=gcd(a,b);
    for(int i=1;i*i<=t;i++)if(t%i==0)
    {
        v.pb(i);
        if(i!=t/i)v.pb(t/i);
    }
    sort(v.begin(),v.end());
    cin>>n;int l,r;
    for(int i=1;i<=n;i++)
    {
        cin>>l>>r;
        int x=v[bs(r)];
        if(x<l)cout<<"-1"<<endl;else cout<<x<<endl;
    }
    return 0;
}