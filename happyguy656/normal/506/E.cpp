#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a14=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
int a14;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mod=10007,mxm=40003;
int n,m,id[222][222],nn,n1;char s[222];
int dp[mxm][222];
int to[mxm],nxt[mxm],fir[mxm],co[mxm],sp[mxm],gn;void lb(int x,int y){to[++gn]=y,nxt[gn]=fir[x],fir[x]=gn;}
struct mat{
    int x,y,a[422][422];
    mat(){}mat(int xx,int yy){x=xx,y=yy,memset(a,0,sizeof(a));}
    mat operator*(mat&b){
        mat r=mat(x,b.y);
        for(int i=0;i<=x;++i)for(int k=i;k<=y;++k)for(int j=k;j<=b.y;++j)r.a[i][j]+=a[i][k]*b.a[k][j]%mod;
        for(int i=0;i<=r.x;++i)for(int j=0;j<=r.y;++j)r.a[i][j]%=mod;return r;
    }
}zy,jz;
void mpor(mat&a,mat&b,int k){for(;k;k>>=1){if(k&1)a=a*b;b=b*b;}}
int jc(int bs,bool tp){
    int A=(n+1)/2,sz=A+n+1;zy=mat(sz,sz);
    for(int i=0,k;i<=n;++i)k=(n-i+1)/2,zy.a[i][sz-k]=dp[0][i];
    for(int i=1;i<=n;++i)zy.a[i][i]=24;for(int i=n+1;i<sz;++i)zy.a[i][i]=25;zy.a[sz][sz]=tp?26:0;
    for(int i=1;i<=sz;++i)zy.a[i-1][i]=1;zy.a[n][n+1]=0;
    jz=mat(0,sz);jz.a[0][0]=1;mpor(jz,zy,bs+1);
    return jz.a[0][sz];
}

int main(){
    scanf("%s%d",s+1,&m);n=strlen(s+1);
    for(int l=0;l<=n;++l)for(int i=1;i+l<=n;++i)id[i][i+l]=++nn;
    for(int i=1;i<=n;++i)for(int j=i;j<=n;++j){
        int k=id[i][j];co[k]=s[i]!=s[j],sp[k]=i+1==j&&s[i]==s[j];
        if(j-i<=1&&s[i]==s[j])lb(k,0);
        else if(s[i]==s[j])lb(k,id[i+1][j-1]);
        else lb(k,id[i][j-1]),lb(k,id[i+1][j]);
    }
    dp[nn][co[nn]]=1;
    for(int i=nn;i;--i)for(int k=0;k<=n;++k)if(dp[i][k])
        forg(j,i)(dp[to[j]][k+co[to[j]]]+=dp[i][k])%=mod;
    int ans=jc((n+m+1)/2,1);
    if((n+m)%2){
        memset(dp,0,sizeof(dp));
        dp[nn][co[nn]]=1;
        for(int i=nn;i;--i)for(int k=0;k<=n;++k)if(dp[i][k])
            forg(j,i)if(!(to[j]==0&&!sp[i])) (dp[to[j]][k+co[to[j]]]+=dp[i][k])%=mod;
        ans-=jc((n+m+1)/2,0);
    }
    ans=(ans%mod+mod)%mod;printf("%d\n",ans);
    return 0;
}