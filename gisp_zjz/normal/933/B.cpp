#include<bits/stdc++.h>
#define maxn 2500

using namespace std;
typedef long long ll;

ll ans[maxn],a[maxn],p,n,r,s[maxn],tmp;

int main()
{
    scanf("%I64d%I64d",&n,&p);
    tmp=n; r=0;
    while (tmp)
    {
        if (r%2==0) ans[r++]=tmp%p,tmp/=p;
        else ans[r++]=(p-tmp%p)%p,tmp=(tmp-1)/p+1;
    }
    printf("%d\n",r);
    for (int i=0;i<r;i++) printf("%d ",ans[i]);
    return 0;
}