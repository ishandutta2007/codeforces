#include<iostream>
#include<cstdio>
#include<cstring>
#define N 210
using namespace std;
char s[N][N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
            int c1=(s[1][2]=='0'),c2=(s[2][1]=='0');
            int d1=(s[n][n-1]=='0'),d2=(s[n-1][n]=='0');
            if((c1==c2) && (d1==d2))
            {
                if(c1!=d1) puts("0");
                else printf("2\n%d %d\n%d %d\n",n,n-1,n-1,n);
            }
            else if(c1==c2)
            {
                if(d1==c1) printf("1\n%d %d\n",n,n-1);
                else printf("1\n%d %d\n",n-1,n);
            }
            else if(d1==d2)
            {
                if(c1==d1) printf("1\n%d %d\n",1,2);
                else printf("1\n%d %d\n",2,1);
            }
            else
            {
                puts("2");
                if(c1==0) printf("%d %d\n",1,2);
                else printf("%d %d\n",2,1);
                if(d1==1) printf("%d %d\n",n,n-1);
                else printf("%d %d\n",n-1,n);
            }
    }
    return 0;
}