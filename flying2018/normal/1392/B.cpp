#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
#define ll long long
using namespace std;
ll a[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n;
        ll k;
        scanf("%d%lld",&n,&k);
        ll minn=1e10,maxn=-1e10;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]),minn=min(minn,a[i]),maxn=max(maxn,a[i]);
        if(k&1)
        {
            for(int i=1;i<=n;i++) printf("%lld ",maxn-a[i]);
            puts("");
        }
        else
        {
            for(int i=1;i<=n;i++) printf("%lld ",a[i]-minn);
            puts("");
        }
    }
    
    return 0;
}