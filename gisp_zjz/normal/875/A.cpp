#include<bits/stdc++.h>
#define maxn 10000020

using namespace std;
typedef long long ll;

int main()
{
    int n,ans[100],cnt,t,k;
    scanf("%d",&n);cnt=0;
    for (int i=min(n,100);i>=0;i--)
    {
        t=n-i;k=0;
        while (t)
        {
            k+=t%10;t/=10;
        }
        if (k==i) ans[cnt++]=n-i;
    }
    printf("%d\n",cnt);
    for (int i=0;i<cnt;i++) printf("%d\n",ans[i]);
    return 0;
}