#include<bits/stdc++.h>
using namespace std;
#define res int
#define LL long long
#define pb push_back
int read()
{
    static int sl,fh,ch;
    sl=0;fh=1;ch=getchar();
    while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
    while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
    return sl*fh;
}
const int kcz=998244353;
inline void add(res &x,const res &y){
    x+=y,x>=kcz?x-=kcz:1;
}
inline int mul(const res &x,const res &y){
    return (int)((LL)x*y%kcz);
}
const int N=5e3+10;
int f[N][N],a[N],suf[N];
int C[N][N];
int main()
{
    C[0][0]=1;
    for(res i=1;i<=N-10;i++){
        C[i][0]=1;
        for(res j=1;j<=i;j++)C[i][j]=C[i-1][j-1],add(C[i][j],C[i-1][j]);
    }
    res T=read();
    while(T--){
        res n=read();
        for(res i=1;i<=n;i++)a[i]=read();
        suf[n+1]=-1;
        for(res i=n;i>=1;){
            res j=i;
            while(a[j]==a[i]&&j>=1)j--;
            for(res k=i;k>j;k--)suf[k]=n-i;
            i=j;
        }
        for(res i=1;i<=n+1;i++)for(res j=0;j<=n;j++)f[i][j]=0;
        if(a[n]==a[n-1]){puts("0");continue;}
        f[n][0]=1;
        for(res i=n-1;i>=1;){
            res j=i;
            while(a[j]==a[i]&&j>=1)j--;
            res l=i-j;
            for(res k=l-1;k<=n/2;k++){
                if(n-i-(k-l)-(k-l)>=l){
                    if(n-i-(k-l)==n/2){
                        f[j+1][k]=mul(f[i+1][k-l],C[n-i-(k-l)-(k-l)][l]);
                    }
                    else f[j+1][k]=mul(f[i+1][k-l],C[n-i-1-(k-l)-(k-l)][l]);
                }
                if(n-i-(k-(l-1))-1-(k-(l-1))>=l-1){
                    if(n-i-(k-(l-1))+1==n/2){
                        add(f[j+1][k],mul(f[i+1][k-(l-1)],C[n-i-(k-(l-1))-1-(k-(l-1))][l-1]));
                    }
                    else add(f[j+1][k],mul(f[i+1][k-(l-1)],C[n-i-(k-(l-1))-1-(k-(l-1))][l-1]));
                }
            }
//            for(res k=l-1;k<=n/2;k++)printf("%d ",f[j+1][k]);
//            puts("");
            i=j;
        }
        printf("%d\n",f[1][n/2]);
//        f[n][0][0]=1;
//        for(res i=n-1;i>=1;i--){
//            for(res j=0;2*j-1<=suf[i];j++){
//                if(a[i]!=a[i+1])f[i][j][0]=f[i+1][j][0];
//                add(f[i][j][0],f[i+1][j][1]);
//                if(j){
//                    if(n-i-j+1==n/2)add(f[i][j][1],mul(f[i+1][j-1][0],suf[i]-2*j+2)),add(f[i][j][1],mul(f[i+1][j-1][1],suf[i]-2*j+2));
//                    else add(f[i][j][1],mul(f[i+1][j-1][0],suf[i]-2*j+1)),add(f[i][j][1],mul(f[i+1][j-1][1],suf[i]-2*j+1));
//                }
//            }
//            printf("%d:\n",suf[i]);
//            for(res j=0;j<=suf[i];j++)printf("%d %d\n",f[i][j][0],f[i][j][1]);
//            puts("");
//        }
    }
    return 0;
}