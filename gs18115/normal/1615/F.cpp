#include<iostream>
#include<vector>
#include<algorithm>
#define forn(i,n) for(int i=0;i<n;i++)
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
const int mod=1e9+7;
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
    return(int)((ll)x*y%mod);
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
inline int inv(int x)
{
    return pw(x,mod-2);
}
inline int divi(int x,int y)
{
    return mul(x,inv(y));
}
int dp[2010][4010];
int ct[2010][4010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tcc;
    cin>>tcc;
    while(tcc-->0)
    {
        int n;
        cin>>n;
        string s,t;
        cin>>s;
        cin>>t;
        vector<int>v1(n),v2(n);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='?')
                v1[i]=-1;
            else
                v1[i]=s[i]=='0'?0:1;
        }
        for(int i=0;i<n;i++)
        {
            if(t[i]=='?')
                v2[i]=-1;
            else
                v2[i]=t[i]=='0'?0:1;
        }
        const int mid=2005;
        dp[0][mid]=0;
        ct[0][mid]=1;
        for(int i=0;i<n;i++)
        {
            int cr=i;
            int nx=i+1;
            int a=v1[i],b=v2[i];
            for(int j=-n;j<=n;j++)
            {
                for(int x=0;x<2;x++)
                {
                    if(a!=-1&&a!=x)
                        continue;
                    for(int y=0;y<2;y++)
                    {
                        if(b!=-1&&b!=y)
                            continue;
                        int nxj=(x-y)-j;
                        ct[nx][mid+nxj]=add(ct[nx][mid+nxj],ct[cr][mid+j]);
                        dp[nx][mid+nxj]=add(dp[nx][mid+nxj],add(dp[cr][mid+j],mul(ct[cr][mid+j],abs(j))));
                    }
                }
            }
        }
        cout<<dp[n][mid]<<'\n';
        for(int i=0;i<=n;i++)
            for(int j=-n;j<=n;j++)
                dp[i][mid+j]=ct[i][mid+j]=0;
    }
    return 0;
}