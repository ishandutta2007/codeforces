#include<cstdio>
#include<cstring>
using namespace std;
char st[2000000];
int a[2000000],b[2000000],c[2000000],r[2000000];
int n,m,d,k,j,tmp;
void f(int x){
     if (x==1) return;f(x>>1);
     for(int i=1;i<=n;i++)c[i]=a[a[i]];
     for(int i=1;i<=n;i++)a[i]=c[i];
     if (x&1){
        for(int i=1;i<=n;i++)c[i]=a[b[i]];
        for(int i=1;i<=n;i++)a[i]=c[i];
     }
}
int main(){
    scanf("%s",st);n=strlen(st);scanf("%d",&m);
    for(int i=1;i<=n;i++)r[i]=i;
    for(;m>0;m--){
        scanf("%d%d",&k,&d);j=0;
        for(int i=1;i<=d;i=(i-1)%d+2){
            for(;i<=k;i+=d){
                j++;b[j]=i;
            }
        }
        for(int i=k+1;i<=n;i++)b[i]=i;
        tmp=b[1];
        for(int i=1;i<n;i++)b[i]=b[i+1];
        b[n]=tmp;
        for(int i=1;i<=n;i++)a[i]=b[i];
        f(n-k+1);
        for(int i=k;i<=n;i++)c[i-k+1]=a[i];
        for(int i=1;i<k;i++)c[i+n-k+1]=a[i];
        for(int i=1;i<=n;i++)a[i]=c[i];
        for(int i=1;i<=n;i++)c[i]=r[a[i]];
        for(int i=1;i<=n;i++)r[i]=c[i];
        for(int i=1;i<=n;i++)printf("%c",st[r[i]-1]);
        puts("");
    }
}