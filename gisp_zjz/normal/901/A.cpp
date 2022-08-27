#include<bits/stdc++.h>
#define maxn 200050

using namespace std;
int n,a[maxn],b[maxn],k,m,r,d;
bool f;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<=n;i++) scanf("%d",&a[i]);
    m=1;k=1;f=true;
    for (int i=1;i<=n;i++)
    {
        if (a[i]==1) f=true,b[++m]=k,k=m;
        else if (f){
            f=false;
            d=m+1;
            for (int j=0;j<a[i];j++) b[++m]=k;
            k=m;
        }
        else{
            r=m+2;
            for (int i2=i;i2<=n;i2++)
            {
                for (int j=0;j<a[i2];j++) b[++m]=k;
                k=m;
            }
            printf("ambiguous\n");
            for (int i=1;i<=m;i++) printf("%d ",b[i]); printf("\n");
            for (int i=1;i<=m;i++) if (i==r) printf("%d ",d); else printf("%d ",b[i]);
            printf("\n");
            return 0;
        }
    }
    printf("perfect\n");
    return 0;
}