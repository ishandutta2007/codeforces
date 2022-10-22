#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100010
#define P pair<int,int>
#define MP make_pair
#define fi first
#define se second
using namespace std;
int a[N];bool p[N];
P b[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=MP(a[i],i),p[i]=false;
        sort(b+1,b+n+1);reverse(b+1,b+n+1);
        for(int i=1;i<=n;i++)
            for(int w=b[i].se;w<=n && !p[w];w++) printf("%d ",a[w]),p[w]=1;
        puts("");
    }
    return 0;
}