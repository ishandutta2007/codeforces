#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200010
using namespace std;
int a[N];
bool hv[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
        if(hv[a[i]]) hv[a[i]+1]=true;
        else hv[a[i]]=true;
        int ans=0;
        for(int i=1;i<=2*n+2;i++) ans+=hv[i];
        printf("%d\n",ans);
        for(int i=1;i<=2*n+2;i++) hv[i]=false;
    }
    return 0;
}