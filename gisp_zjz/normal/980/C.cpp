#include<bits/stdc++.h>
#define maxn 230400

using namespace std;
int a[maxn],b[maxn],m,n,t[256],r;

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(t,-1,sizeof(t));
    for (int i=1;i<=n;i++)
    {
        if (t[a[i]]==-1){
            r=a[i];
            for (int j=max(0,a[i]-m+1);j<a[i];j++) if (t[j]==j||t[j]==-1) {r=j;break;}
            for (int j=r;j<=a[i];j++) t[j]=r;
        }
        b[i]=t[a[i]];
    }
    for (int i=1;i<=n;i++) printf("%d ",b[i]); printf("\n");
    return 0;
}