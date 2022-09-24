#include<iostream>
#include<vector>
#include<algorithm>
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define semicolon 
#define ryan bear
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const ll inf=1e18;
int dp[600010];
int n,i,j;
int m,M,c,d,p,q,k;
int d2,m2,r,ss,t;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    cin>>s;
    for(i=0;i<n;i++)
    {
        if(s[i]=='(')
            dp[i+1]=dp[i]+1;
        else
            dp[i+1]=dp[i]-1;
        if(dp[i]<m)
            m=dp[i],j=i;
    }
    if(dp[n]!=0)
        return cout<<0<<endl<<1<<' '<<1<<endl,0;
    int v=dp[j];
    for(i=0;i<=n;i++)
        dp[i]-=v;
    for(i=j;i<=n*2;i++)
        dp[i]=dp[i%n];
    for(i=0;i<n;i++)
        dp[i]=dp[i+j];
    for(i=0;i<n;i++)
    {
        if(dp[i]==0)
        {
            c++;
            k=i;
            d=0;
        }
        else if(dp[i]==1)
            k=i,d=0;
        else if(dp[i]==2)
        {
            d++;
            if(d>M)
            {
                M=d;
                p=k;
                q=i;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(dp[i]==0)
        {
            t=i;
            d2=0;
        }
        else if(dp[i]==1)
        {
            d2++;
            if(d2>m2)
            {
                m2=d2;
                r=t;
                ss=i;
            }
        }
    }
    p=(p+j)%n+1;
    q=(q+j)%n+1;
    r=(r+j)%n+1;
    ss=(ss+j)%n+1;
    if(c+M>m2)
    {
        cout<<c+M<<endl;
        if(M==0)
            cout<<1<<' '<<1<<endl;
        else
            cout<<p<<' '<<q<<endl;
    }
    else
    {
        cout<<m2<<endl;
        if(m2==0)
            cout<<1<<' '<<1<<endl;
        else
            cout<<r<<' '<<ss<<endl;
    }
    return 0;
}