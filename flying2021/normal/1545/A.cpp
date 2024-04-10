#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100010
using namespace std;
int a[N],c[N];
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),c[a[i]]+=i&1;
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++) c[a[i]]-=i&1;
        bool can=true;
        for(int i=1;i<=n;i++) if(c[a[i]]){can=false;puts("NO");break;}
        if(can) puts("YES");
        for(int i=1;i<=n;i++) c[a[i]]=0;
    }
    return 0;
}