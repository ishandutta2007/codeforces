#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int mod=998244353;
int n,m,sum[18][1<<17],tot;
string str;
inline int pw(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=1ll*res*a%mod;
        b>>=1;
        a=1ll*a*a%mod;
    }
    return res;
}
int main()
{
    cin>>n>>str;
    for(auto i:str)
        tot+=i=='?';
    str=" "+str;
    for(int i=1;i<=n;++i)
    {
        int l=i,r=i,s=0,cnt=tot;
        while(l>=1&&r<=n)
        {
            if(str[l]!='?'&&str[r]!='?'&&str[l]!=str[r])
                break;
            if(str[l]=='?'&&str[r]=='?')
                cnt-=l!=r;
            else if(str[l]=='?')
            {
                s|=1<<(str[r]-'a');
                --cnt;
            }
            else if(str[r]=='?')
            {
                s|=1<<(str[l]-'a');
                --cnt;
            }
            for(int j=max(1,__builtin_popcount(s));j<=17;++j)
                sum[j][s]=(sum[j][s]+pw(j,cnt))%mod;
            --l,++r;
        }
        l=i,r=i+1,s=0,cnt=tot;
        while(l>=1&&r<=n)
        {
            if(str[l]!='?'&&str[r]!='?'&&str[l]!=str[r])
                break;
            if(str[l]=='?'&&str[r]=='?')
                cnt-=l!=r;
            else if(str[l]=='?')
            {
                s|=1<<(str[r]-'a');
                --cnt;
            }
            else if(str[r]=='?')
            {
                s|=1<<(str[l]-'a');
                --cnt;
            }
            for(int j=max(1,__builtin_popcount(s));j<=17;++j)
                sum[j][s]=(sum[j][s]+pw(j,cnt))%mod;
            --l,++r;
        }
    }
    for(int i=1;i<=17;++i)
        for(int j=0;j<17;++j)
            for(int s=0;s<1<<17;++s)
                if(s>>j&1)
                    sum[i][s]=(sum[i][s]+sum[i][s^(1<<j)])%mod;
    cin>>m;
    while(m--)
    {
        cin>>str;
        int len=str.length(),s=0;
        for(auto i:str)
            s|=1<<(i-'a');
        cout<<sum[len][s]<<'\n';
    }
    return 0;
}