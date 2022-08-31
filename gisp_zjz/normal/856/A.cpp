#include<bits/stdc++.h>
#define maxn 23050

using namespace std;
bool f[1000005];
int t,a[105],d,n,e;

int main()
{
    scanf("%d",&t);
    while (t--){
        scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%d",&a[i]); sort(a,a+n);
        memset(f,true,sizeof(f));
        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++)
                for (int k=1;k<=n;k++)
                {
                    e=(a[j]-a[i])/k;
                    if (e*k==a[j]-a[i]) f[e]=false;
                }
        d=1;
        while (!f[d]) d++;
        printf("YES\n");
        for (int i=1;i<=n;i++) printf("%d ",i*d); printf("\n");
    }
    return 0;
}