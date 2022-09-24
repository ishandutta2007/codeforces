#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const ll inf=1e18;
struct node
{
    int l,r;
}trie[6000010];
int tct;
void tc(int n)
{
    if(n==0)
        return;
    node&cur=trie[n];
    tc(cur.l);
    tc(cur.r);
    cur.l=cur.r=0;
    return;
}
inline void tc()
{
    tc(tct=1);
    return;
}
void ti(int n,int s,int e,int x)
{
    if(s==e)
        return;
    node&cur=trie[n];
    int m=s+e>>1;
    if(x>m)
    {
        if(cur.r==0)
            cur.r=++tct;
        ti(cur.r,m+1,e,x);
    }
    else
    {
        if(cur.l==0)
            cur.l=++tct;
        ti(cur.l,s,m,x);
    }
    return;
}
int get(int n,int s,int e,int x)
{
    if(s==e)
        return 0;
    const node&cur=trie[n];
    int m=s+e>>1;
    if(x>m)
    {
        if(cur.r==0)
            return(e-s+1)/2+get(cur.l,s,m,x-(e-s+1)/2);
        return get(cur.r,m+1,e,x);
    }
    if(cur.l==0)
        return(e-s+1)/2+get(cur.r,m+1,e,x+(e-s+1)/2);
    return get(cur.l,s,m,x);
}
ll dnc(vector<int>&v,int mb)
{
    if(v.size()<2)
        return 0;
    ll d=0;
    if(v[0]>=mb)
        d=mb;
    while(v.back()<d+mb)
    {
        mb/=2;
        if(v[0]>=d+mb)
            d+=mb;
    }
    for(int&t:v)
        t-=d;
    ll ans=inf;
    vector<int>q1,q2;
    for(int t:v)
    {
        if(t<mb)
            q1.eb(t);
        else
            q2.eb(t-mb);
    }
    tc();
    for(int t:q1)
        ti(1,0,mb-1,t);
    for(int t:q2)
        ans=min(ans,(ll)get(1,0,mb-1,t));
    return ans+mb+dnc(q1,mb/2)+dnc(q2,mb/2);
}
int n,i;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    vector<int>v(n);
    for(i=0;i<n;i++)
        cin>>v[i];
    sort(all(v));
    v.erase(unique(all(v)),v.end());
    cout<<dnc(v,1<<29)<<endl;
    return 0;
}