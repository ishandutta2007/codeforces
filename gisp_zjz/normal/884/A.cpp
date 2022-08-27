#include<bits/stdc++.h>
#define maxn 1000005
#define m 86400

using namespace std;
int n,t,a[m];

int main()
{
    scanf("%d%d",&n,&t);
    int ans=0;
    for (int i=1;i<=n;i++)scanf("%d",&a[i]);
    while (t>0)
    {
        ans++;
        t-=(m-a[ans]);
    }
    printf("%d\n",ans);
}