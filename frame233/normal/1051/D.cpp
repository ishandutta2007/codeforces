#include<cstdio>
#include<cstring>
#define Finline __inline__ __attribute__ ((always_inline))
const int N=1005,mod=998244353;
int f[2][N<<1][4];
Finline void add(int &a,const int &b){(a+=b)>=mod&&(a-=mod);}
int main()
{
    int n,k;
    register int t=1;
    scanf("%d %d",&n,&k);
    f[1][1][0]=f[1][2][1]=f[1][2][2]=f[1][1][3]=1;
    for(register int i=2;i<=n;++i)
    {
        t^=1;
        memset(f[t],0,sizeof(f[t]));
        for(register int j=1;j<=(i<<1)&&j<=k;++j)
        {
            add(f[t][j][0],f[t^1][j][0]);
            add(f[t][j][0],f[t^1][j][1]);
            add(f[t][j][0],f[t^1][j][2]);
            add(f[t][j][1],f[t^1][j][1]);
            add(f[t][j][2],f[t^1][j][2]);
            add(f[t][j][3],f[t^1][j][1]);
            add(f[t][j][3],f[t^1][j][2]);
            add(f[t][j][3],f[t^1][j][3]);
            if(j>1)
            {
                add(f[t][j][0],f[t^1][j-1][3]);
                add(f[t][j][1],f[t^1][j-1][0]);
                add(f[t][j][1],f[t^1][j-1][3]);
                add(f[t][j][2],f[t^1][j-1][0]);
                add(f[t][j][2],f[t^1][j-1][3]);
                add(f[t][j][3],f[t^1][j-1][0]);
            }
            if(j>2)
            {
                add(f[t][j][1],f[t^1][j-2][2]);
                add(f[t][j][2],f[t^1][j-2][1]);
            }
        }
    }
    int ans=f[t][k][0];
    add(ans,f[t][k][1]);
    add(ans,f[t][k][2]);
    add(ans,f[t][k][3]);
    printf("%d\n",ans);
    return 0;
}