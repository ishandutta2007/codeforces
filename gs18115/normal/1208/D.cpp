#include<iostream>
#include<vector>
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
struct fenwick
{
    ll dat[200010];
    inline void FI(int x,ll p)
    {
        for(x++;x<200010;x+=x&-x)
            dat[x]+=p;
        return;
    }
    inline ll FS(int x)
    {
        ll ans=0;
        for(x++;x>0;x=x&x-1)
            ans+=dat[x];
        return ans;
    }
}FT;
ll n,i;
ll s[200010],a[200010];
ll nxt[200010],prv[200010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(i=0;i<n;i++)
        cin>>s[i];
    for(i=0;i++<n;)
        FT.FI(i,i);
    for(i=0;i++<n;)
        nxt[i]=i+1,prv[i]=i-1;
    nxt[0]=1;
    prv[n+1]=n;
    for(i=n;i-->0;)
    {
        int ss=0,e=n-1;
        while(ss<e)
        {
            int m=ss+e>>1;
            if(FT.FS(m)>=s[i])
                e=m;
            else
                ss=m+1;
        }
        a[i]=nxt[ss];
        nxt[prv[a[i]]]=nxt[a[i]];
        prv[nxt[a[i]]]=prv[a[i]];
        FT.FI(a[i],-a[i]);
    }
    for(i=0;i<n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}