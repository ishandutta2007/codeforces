#include<iostream>
#include<cstdio>
using namespace std;
int read()
{
   int x=0,f=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
   return x*f;
}
int n;
int s[105];
int main()
{
    n=read();bool flag=false;
    for(int i=1;i<=n;i++)
    {
        s[i]=read();if(s[i]!=0) flag=true;
        s[i]=s[i]+s[i-1];
    }
    if(flag==false) {printf("NO");return 0;}
    printf("YES\n");
    if(s[n]!=0)
    {
        printf("1\n1 %d",n);
    }
    else
    {
        printf("2\n");
        for(int i=1;i<n;i++)
        {
            if(s[i]!=0)
            {
                printf("1 %d\n%d %d",i,i+1,n);
                break;
            }
        }
    }
    return 0;
}