#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define MN 100000
#define mod 1000000007
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
vector<pair<int,int> >v[MN+5];
char st[MN+5];
int n,len,Ans[MN+5],tot=0,d[MN+5],p[MN+5],inv[MN+5],P[MN+5];
inline int C(int n,int m){return 1LL*p[n]*inv[m]%mod*inv[n-m]%mod;}
int main()
{
    p[0]=inv[0]=p[1]=inv[1]=P[0]=1;P[1]=25;
    for(int i=2;i<=MN;++i) p[i]=1LL*p[i-1]*i%mod,inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod,P[i]=1LL*P[i-1]*25%mod;
    for(int i=2;i<=MN;++i) inv[i]=1LL*inv[i]*inv[i-1]%mod;
    n=read();scanf("%s",st+1);len=strlen(st+1);
    for(int i=1;i<=n;++i)
        if(read()==1) scanf("%s",st+1),len=strlen(st+1);
        else v[len].push_back(make_pair(read(),++tot));
    for(int i=1;i<=MN;++i) if(v[i].size())
    {
        memset(d,0,sizeof(d));int k=0;
        sort(v[i].begin(),v[i].end());
        while(k<v[i].size()&&v[i][k].first  <i) ++k;
        for(int j=i;j<=MN;++j)
        {
            d[j]=(1LL*d[j-1]*26+1LL*C(j-1,i-1)*P[j-i]%mod)%mod;
            while(k<v[i].size()&&v[i][k].first==j) Ans[v[i][k++].second]=d[j];
        }
    }
    for(int i=1;i<=tot;++i) printf("%d\n",Ans[i]);
    return 0;
}