#include<bits/stdc++.h>
using namespace std;
const int N=1010,M=1e5+10;
int a[N][N],p[N],q[N][N];
char s[M];
int main() {
    int n,m,T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",a[i]+j);
        scanf("%s",s+1);
        int I=0,J=1,A=2;
        int cnt[3]={0,0,0};
        for(int i=1;i<=m;i++) {
            if(s[i]=='I')swap(J,A);
            if(s[i]=='C')swap(I,A);
            if(s[i]=='R')cnt[J]++;
            if(s[i]=='L')cnt[J]--;
            if(s[i]=='D')cnt[I]++;
            if(s[i]=='U')cnt[I]--;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) {
                int f[3]={i,j,a[i][j]};
                f[0]=(f[0]+cnt[0]%n+n)%n;
                f[1]=(f[1]+cnt[1]%n+n)%n;
                f[2]=(f[2]+cnt[2]%n+n)%n;
                if(f[0]==0)f[0]=n;
                if(f[1]==0)f[1]=n;
                if(f[2]==0)f[2]=n;
                q[f[I]][f[J]]=f[A];
            }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++)
                printf("%d ",q[i][j]);
            puts("");
        }
    }
    return 0;
}