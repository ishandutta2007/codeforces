#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
using namespace std;
int a[N];
bool is_prime(int x)
{
    for(int i=2;1ll*i*i<=x;i++) if(x%i==0) return false;
    return true;
}
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n,s=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),s+=a[i];
        if(!is_prime(s))
        {
            printf("%d\n",n);
            for(int i=1;i<=n;i++) printf("%d ",i);puts("");
            continue;
        }
        for(int i=1;i<=n;i++) if(!is_prime(s-a[i]))
        {
            printf("%d\n",n-1);
            for(int j=1;j<=n;j++) if(j!=i) printf("%d ",j);puts("");
            break;
        }
    }
    return 0;
}