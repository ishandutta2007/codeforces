#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define MN 2200
using namespace std;
inline int read()
{
    int x = 0 , f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){ if(ch == '-') f = -1;  ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return x * f;
}

ll f[MN+5][MN+5],N[MN+5][MN+5],N2[MN+5][MN+5];
int a[MN+5],b[MN+5],n,k;

int main()
{
    n=read();k=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<=n;++i) b[i]=read();
    int l=-(1e9),r=1e9,mid;
    while(l<=r)
    {
        mid=1LL*l+r>>1;
        memset(f,63,sizeof(f));
        for(int i=0;i<=n;++i) f[0][i]=f[i][0]=0;
        for(int i=1;i<=n;++i)
            for(int j=i;j<=n;++j)
            {
                if(f[i-1][j]<f[i][j]) f[i][j]=f[i-1][j],N[i][j]=N[i-1][j],N2[i][j]=N2[i-1][j];
                else if(f[i-1][j]==f[i][j]) N[i][j]=max(N[i][j],N[i-1][j]),N2[i][j]=min(N2[i][j],N2[i-1][j]);
                if(f[i][j-1]<f[i][j]) f[i][j]=f[i][j-1],N[i][j]=N[i][j-1],N2[i][j]=N2[i][j-1];
                else if(f[i][j-1]==f[i][j]) N[i][j]=max(N[i][j],N[i][j-1]),N2[i][j]=min(N2[i][j],N2[i][j-1]);
                if(f[i-1][j-1]+a[i]-mid+b[j]-mid<f[i][j])
                    f[i][j]=f[i-1][j-1]+a[i]-mid+b[j]-mid,N[i][j]=N[i-1][j-1]+1,N2[i][j]=N2[i-1][j-1]+1;
                else if(f[i-1][j-1]+a[i]-mid+b[j]-mid==f[i][j])
                                                        N[i][j]=max(N[i][j],N[i-1][j-1]+1),N2[i][j]=min(N2[i][j],N2[i-1][j-1]+1);
            }
    //    cout<<mid<<" "<<f[n][n]<<" "<<N[n][n]<<endl;
        if(N[n][n]>=k&&N2[n][n]<=k) return 0*printf("%lld",f[n][n]+2LL*k*mid);
        else if(N[n][n]>k) r=mid-1;
        else l=mid+1;
    }
    return 0;
}