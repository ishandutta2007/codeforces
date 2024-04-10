#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
#define int long long
int t,n,sum[400005][3],cnt[2],ans;
string s;
inline int lowbit(int x)
{
    return x&-x;
}
inline void update(int x,int tag)
{
    for(;x<=(n<<1|1);x+=lowbit(x))
        ++sum[x][tag];
}
inline int query(int x,int tag)
{
    int res=0;
    for(;x;x-=lowbit(x))
        res+=sum[x][tag];
    return res;
}
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        s=" "+s;
        ans=cnt[0]=cnt[1]=0;
        for(int i=1;i<=(n<<1|1);++i)
            sum[i][0]=sum[i][1]=sum[i][2]=0;
        update(n+1,0);
        for(int i=1;i<=n;++i)
        {
            if(s[i]=='+')
                ++cnt[0];
            else
                ++cnt[1];
            ans+=query(cnt[1]-cnt[0]+n+1,((cnt[0]-cnt[1])%3+3)%3);
            update(cnt[1]-cnt[0]+n+1,((cnt[0]-cnt[1])%3+3)%3);
        }
        cout<<ans<<'\n';
    }
    return 0;
}