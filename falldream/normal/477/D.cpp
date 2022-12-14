#include<bits/stdc++.h>
#define MD 13
#define MN 5000
#define mod 1000000007
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
//template begin here
namespace SA
{
    int sa[2][MN+5],rk[2][MN+5],k,v[MN+5],p=1,q=0,*Sa,*Rk,f[MD+1][MN+5],Lg[MN+5];
    void GetH(char*s,int*sa,int*rk,int n)
    {
        for(int i=1,k=0;i<=n;f[0][rk[i++]-1]=k,k=max(k-1,0)) if(rk[i]>1)
            for(int j=sa[rk[i]-1];s[i+k]==s[j+k];++k);
    }
    void CalSa(int*sa,int*rk,int*SA,int*RK,int n)
    {
        for(int i=1;i<=n;++i) v[rk[sa[i]]]=i;
        for(int i=n;i;--i) if(sa[i]>k) SA[v[rk[sa[i]-k]]--]=sa[i]-k;
        for(int i=n-k+1;i<=n;++i) SA[v[rk[i]]--]=i;
        for(int i=1;i<=n;++i) RK[SA[i]]=RK[SA[i-1]]+(rk[SA[i]]!=rk[SA[i-1]]||rk[SA[i]+k]!=rk[SA[i-1]+k]);
    }
    void Build(char*s,int n)
    {
        memset(f,63,sizeof(f));Lg[0]=-1;
        for(int i=1;i<=n;++i) ++v[s[i]-'0'];v[1]+=v[0];
        for(int i=1;i<=n;++i) sa[q][v[s[i]-'0']--]=i;
        for(int i=1;i<=n;++i) rk[q][sa[q][i]]=rk[q][sa[q][i-1]]+(s[sa[q][i]]!=s[sa[q][i-1]]);
        for(k=1;k<n;k<<=1,swap(p,q)) CalSa(sa[q],rk[q],sa[p],rk[p],n);
        GetH(s,sa[q],rk[q],n);Sa=sa[q];Rk=rk[q];
        for(int i=1;i<=n;++i) Lg[i]=Lg[i>>1]+1;
        for(int i=1;i<=MD;++i)for(int j=1;j<=n;++j)
            if(j+(1<<i)<=n) f[i][j]=min(f[i-1][j],f[i-1][j+(1<<i-1)]);
    }
    int Query(int l,int r)
    {
        l=Rk[l];r=Rk[r];if(l>r) swap(l,r);
        int lg=Lg[r-l];
        return min(f[lg][l],f[lg][r-(1<<lg)]);    
    }
}
//template end here
char s[MN+5];
int n,f[MN+5][MN+5],g[MN+5][MN+5],G[MN+5],F[MN+5],it[MN+5];
bool Check(int l,int r,int L,int R)
{
    if(r-l!=R-L) return r-l<R-L;
    int lcp=SA::Query(l,L);
    if(lcp>=r-l+1) return true;
    else return s[l+lcp]<s[L+lcp];
}
int main()
{
    scanf("%s",s+1);n=strlen(s+1);SA::Build(s,n);
    for(int i=1;i<=n;++i) 
    {
        it[i]=i+1;f[i][1]=1;g[i][1]=1;
        for(int j=1;j<i;++j) if(s[j+1]=='1')
        {
            while(it[j]>1&&Check(it[j]-1,j,j+1,i)) 
                --it[j],F[j]=(F[j]+f[j][it[j]])%mod,G[j]=min(G[j],g[j][it[j]]);
            f[i][j+1]=F[j];g[i][j+1]=G[j]+1;
        }
        else g[i][j+1]=1e9;G[i]=1e9;
    }
    int res=0,found=0,mn=1e9;
    for(int i=n,v=1,now=0;i;--i,v=v*2%mod)
    {
        res=(res+f[n][i])%mod;
        now=(now+v*(s[i]-'0'))%mod;
        if(g[n][i]<1e8)
        {
            if(n-i+1<=15) mn=min(mn,now+g[n][i]);
            else if(!found) mn=(now+g[n][i])%mod;
            found=1;
        }
    }
    printf("%d %d\n",res,mn);
    return 0;
}