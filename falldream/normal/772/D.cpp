#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#define MN 1000000
#define ll long long
#define mod 1000000007
char B[1<<26],*S=B;
#define getchar() (*S++)
using namespace std;
inline int read()
{
    int x = 0,f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:-x;
}

int n,num[MN+5],sq[MN+5],sum[MN+5],a[MN+5],C,D,pw[7],X,p[MN+5];
ll res=0,ans;
inline void R(int&x,int y){x+=y;(x>=mod)?x-=mod:0;x<0?x+=mod:0;}
void dfs(int x,int now,int k,int l)
{
    if(x>6)
    {
        if(l!=X&&num[l])
        {
            R(num[X],k*num[l]);
            R(sq[X],k*sq[l]);
            R(sum[X],k*sum[l]);
        }
        return;
    }
    int la=now%10;now/=10;
    dfs(x+1,now,k,l+la*pw[x]);
    if(la<9) dfs(x+1,now,-k,l+(la+1)*pw[x]);
}

inline int Sqr(int x){return 1LL*x*x%mod;}
void solve(int x,int now,int k,int l)
{
 //   cout<<"solve"<<x<<" "<<now<<" "<<k<<" "<<l<<endl;
    if(x>6)
    {
        //if(X==1) cout<<l<<" "<<k<<endl;
        if(num[l])
        {
            if(k==-1) k=mod-1;
          //  cout<<X<<" "<<l<<" "<<num[l]<<" "<<sum[l]<<" "<<sq[l]<<" "<<k<<endl;
            if(num[l]==1) ans=(ans+1LL*k*Sqr(sum[l]))%mod;
            else
            {
                int times=p[num[l]-1];
                ans=(ans+1LL*k*times%mod*(1LL*Sqr(sum[l])+sq[l])%mod*500000004)%mod;
            }
        }
        return;
    }
    int la=now%10;now/=10;
    solve(x+1,now,k,l+la*pw[x]);
    if(la<9) solve(x+1,now,-k,l+(la+1)*pw[x]);
}

inline int U(int x){return x>=mod?x-=mod:x;}

int main()
{
    fread(B,1,1<<26,stdin);
    n=read();pw[1]=p[0]=1;
    for(int i=1;i<=1000000;i++) p[i]=U(p[i-1]<<1);
    for(int i=2;i<=6;i++)pw[i]=pw[i-1]*10;
    for(int i=1;i<=n;i++)
        ++num[a[i]=read()],sq[a[i]]=(sq[a[i]]+1LL*a[i]*a[i])%mod,(sum[a[i]]+=a[i])%=mod;
    for(X=999999;~X;--X) dfs(1,X,-1,0);
    for(X=999999;X;--X)
    {
        ans=0;solve(1,X,1,0);
        //if(ans)cout<<X<<" "<<ans<<endl;
        res=res^(1LL*ans*X);
    }
    cout<<res;
    return 0;
}