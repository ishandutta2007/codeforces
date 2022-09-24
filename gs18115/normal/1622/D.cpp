#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
const int mod=998244353;
inline int add(int x,int y)
{
    return x+y<mod?x+y:x+y-mod;
}
inline int sub(int x,int y)
{
    return x<y?x+mod-y:x-y;
}
inline int mul(int x,int y)
{
    return(ll)x*y%mod;
}
inline int pw(int x,int y)
{
    int r=1;
    while(y>0)
    {
        if(y%2==1)
            r=mul(r,x);
        x=mul(x,x);
        y/=2;
    }
    return r;
}
inline int mul2(int x,int y)
{
    int d=mul(x,y);
    return d>mod/2?d-mod:d;
}
int cb[5050][5050];
int val[5050];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n+4;i++)
        for(int j=cb[i][0]=cb[i][i]=1;j<i;j++)
            cb[i][j]=add(cb[i-1][j-1],cb[i-1][j]);
    string s;
    cin>>s;
    vector<int>pos;
    for(int i=0;i<n;i++)
        if(s[i]=='1')
            pos.eb(i);
    int ps=pos.size();
    if(ps<k)
        return cout<<1<<endl,0;
    pos.eb(n);
    pos.insert(pos.begin(),-1);
    val[k]=1;
    for(int i=k;i-->0;)
    {
        val[i]=1;
        for(int j=i;j++<k;)
            val[i]=sub(val[i],mul(val[j],j-i+1));
    }
    int ans=1;
    for(int i=0;i++<ps;)
    {
        for(int j=i;j++<ps+1;)
        {
            int rad=pos[j]-pos[i-1]-1;
            int ct=j-i;
            if(ct>k)
                continue;
            if(i<=k-ct)
                continue;
            if(ps-j+2<=k-ct)
                continue;
            ans=add(ans,mul(val[ct],cb[rad][ct]-1));
        }
    }
    cout<<ans<<endl;
    return 0;
}