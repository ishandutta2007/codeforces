#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
int p[N],a[N],n;
int qry()
{
    int mn=1;
    for(int j=1;j<=n;j++) mn=max(mn,1-a[j]);
    printf("? ");
    for(int j=1;j<=n;j++) printf("%d ",a[j]+mn);
    puts("");fflush(stdout);
    int q;scanf("%d",&q);
    return q;
}
int main()
{
    int t=1;
    while(t --> 0)
    {
        scanf("%d",&n);
        int u=1;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<n;j++) a[j]=0;
            a[n]=i;
            int q=qry();
            if(q==0){u=n-i+1;break;}
        }
        p[n]=u;
        for(int i=1;i<=n;i++) if(u!=i)
        {
            for(int j=1;j<n;j++) a[j]=0;
            a[n]=-u+i;
            int q=qry();
            p[q]=i;
        }
        printf("! ");
        for(int j=1;j<=n;j++) printf("%d ",p[j]);
        puts("");fflush(stdout);
    }
    return 0;
}