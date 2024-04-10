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
int n,a[1000111];
ll bit[1000111];
void add(int i,ll x)
{
    while(i<=1000000)
    {
        bit[i]+=x;
        i+=i&(-i);
    }
}
ll sum(int i)
{
    ll res=0;
    while(i>0)
    {
        res+=bit[i];
        i-=i&(-i);
    }
    return res;
}
map<int,int>m;
ll l[1000111];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        m[a[i]]++;
        l[i]=m[a[i]];
    }
    ll ans=0;
    for(int i=1;i<n;i++)
    {
        add(l[i],1);
        ans+=i-sum(m[a[i+1]]-l[i+1]+1);
    }
    cout<<ans<<endl;
    return 0;
}