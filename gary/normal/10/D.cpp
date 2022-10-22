#include<cstdio>
int n,a[502],b[502],f[502][502],g[502][502];    //g
void Print(int p) {
    if(!p)          //
        return ;
    Print(g[n][p]);
    printf("%d ",b[p]); //
}
int main() {
    int m,p=0;      //p
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",a+i);
    scanf("%d",&m);
    for(int i=1;i<=m;++i)
        scanf("%d",b+i);
    for(int i=1,t=0;i<=n;++i,t=0)
        for(int j=1;j<=m;++j) {
            f[i][j]=f[i-1][j];      //
            g[i][j]=g[i-1][j];
            if(a[i]==b[j]&&f[i-1][t]+1>f[i][j]) {   //
                f[i][j]=f[i-1][t]+1;
                g[i][j]=t;  //
            }
            if(b[j]<a[i]&&f[i-1][j]>f[i-1][t]) //tLCIS
                t=j;
        }
    for(int i=1;i<=m;++i)
        if(f[n][i]>f[n][p]) //
            p=i;
    printf("%d\n",f[n][p]);
    Print(p);
    return 0;
}