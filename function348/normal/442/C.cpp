#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=500010;
int n;
int d[N];
long long ans;
int main()
{
    scanf("%d",&n);
    int p=0;
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        while (p>=2&&d[p]<=d[p-1]&&d[p]<=x)
        {
            ans+=min(d[p-1],x);
            p--;
        }
        d[++p]=x;
    }
    sort(d+1,d+p+1);
    for (int i=1;i<=p-2;i++) ans+=d[i];
    printf("%I64d\n",ans);
    return 0;
}