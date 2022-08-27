#include<bits/stdc++.h>
#define maxn 2000

using namespace std;

int a[maxn],cnt[maxn],b[maxn],w[maxn],n;

int main()
{
    scanf("%d",&n); for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<n;i++)
    {
        cnt[i]=0;
        for (int j=0;j<n;j++) if (a[j]>a[i]) cnt[i]++;
        w[cnt[i]]=i;
    }
    for (int i=1;i<n;i++) b[w[i]]=a[w[i-1]];
    b[w[0]]=a[w[n-1]];
    for (int i=0;i<n;i++) printf("%d ",b[i]);
    printf("\n");return 0;
}