#include<iostream>
#include<cstdio>
#include<cstring>
#define N 410
using namespace std;
int a[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n+m;i++) a[i]=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                int b;
                scanf("%d",&b);
                a[i+j-1]^=b;
            }
        bool win=false;
        for(int i=1;i<=n+m-1;i++)
        if(a[i]!=0) win=true;
        puts(win?"Ashish":"Jeel");
    }
    return 0;
}