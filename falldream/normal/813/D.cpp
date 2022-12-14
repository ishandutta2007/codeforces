#include<iostream>
#include<cstdio>
#include<cstring>
#define MN 5000
using namespace std;
inline int read()
{
    int x = 0,f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:-x;
}
int n,a[MN+5],f[MN+5],F[8],D[MN+5][MN+5],ans=0,ha[100005],cnt=0;
inline void R(int&x,int y){y>x?x=y:0;}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)!ha[a[i]=read()]?ha[a[i]]=++cnt:0;
    for(int i=0;i<=n;++i)
    {
        memset(F,0,sizeof(F));
        memset(f,0,sizeof(f));
        int Mx=D[i][0];
        for(int j=1;j<i;++j)
            R(F[a[j]%7],D[i][j]),
            R(f[ha[a[j]]],D[i][j]);
        for(int j=i+1;j<=n;++j)
        {
            R(D[i][j],Mx+1);
            R(D[i][j],max(f[ha[a[j]]],F[a[j]%7])+1);
            if(ha[a[j]-1]) R(D[i][j],f[ha[a[j]-1]]+1);
            if(ha[a[j]+1]) R(D[i][j],f[ha[a[j]+1]]+1);
            R(F[a[j]%7],D[i][j]);R(f[ha[a[j]]],D[i][j]);
            R(D[j][i],D[i][j]);
            R(ans,D[i][j]);
         //   cout<<i<<" "<<j<<" "<<D[i][j]<<endl;
        }
    }
    cout<<ans;
    return 0;
}