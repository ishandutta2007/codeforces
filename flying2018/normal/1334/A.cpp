#include<iostream>
#include<cstdio>
#include<cstring>
#define N 110
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n;
        scanf("%d",&n);
        int pa=0,pb=0;
        bool can=true;
        for(int i=1;i<=n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(a<pa || b<pb || a-pa<b-pb) can=false;
            pa=a,pb=b;
        }
        puts(can?"YES":"NO");
    }
    return 0;
}