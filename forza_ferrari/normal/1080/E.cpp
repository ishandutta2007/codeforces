#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<random>
using namespace std;
const int base=19260817,mod=998244353;
int n,m,cnt[251][251][26],p[505],ans,val[505];
string s;
inline int Mod(int x)
{
    return x>=mod? x-mod:x;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>s;
        for(int j=1;j<=m;++j)
        {
            for(int k=0;k<26;++k)
                cnt[i][j][k]=cnt[i][j-1][k];
            ++cnt[i][j][s[j-1]-'a'];
        }
    }
    for(int i=1;i<=m;++i)
        for(int j=i;j<=m;++j)
        {
            for(int k=0;k<=n<<1;++k)
            {
                val[k]=-1;
                p[k]=0;
            }
            int tmp=-1;
            for(int k=1;k<=n;++k)
            {
                int flag=0;
                for(int t=0;t<26;++t)
                {
                    flag+=(cnt[k][j][t]-cnt[k][i-1][t])&1;
                    if(flag>1)
                        break;
                }
                if(flag>1)
                    val[(k<<1)-1]=--tmp;
                else
                {
                    val[(k<<1)-1]=0;
                    for(int t=0;t<26;++t)
                        val[(k<<1)-1]=Mod(1ll*val[(k<<1)-1]*base%mod+cnt[k][j][t]-cnt[k][i-1][t]);
                }
            }
            for(int l=1,r=0,mid=0;l<=(n<<1);++l)
            {
                if(val[l]<-1)
                    continue;
                if(l<=r)
                    p[l]=min(r-l+1,p[(mid<<1)-l]);
                while(l-p[l]>=0&&l+p[l]<=(n<<1)&&val[l-p[l]]==val[l+p[l]])
                    ++p[l];
                if(l+p[l]-1>r)
                {
                    r=l+p[l]-1;
                    mid=l;
                }
                ans+=p[l]>>1;
            }
        }
    cout<<ans<<'\n';
    return 0;
}