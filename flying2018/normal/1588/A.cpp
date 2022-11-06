#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 1010
using namespace std;
int a[N],b[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        sort(a+1,a+n+1);sort(b+1,b+n+1);
        bool can=true;
        for(int i=1;i<=n;i++) if(a[i]!=b[i] && a[i]+1!=b[i]){can=false;break;}
        puts(can?"YES":"NO");
    }
    return 0;
}