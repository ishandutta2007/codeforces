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
char s[200005];
int a,b,ans=0;;
int main()
{
    n=read();
    scanf("%s",s);
    a=0,b=0;
    for(int i=0;s[i];i++)
    {
        if(s[i]=='R')
        {
            if(a==-1)
            {
                ans++;b=0;
            }
            a=1;
        }
        else if(s[i]=='L')
        {
            if(a==1)
            {
                ans++;b=0;
            }
            a=-1;
        }
        else if(s[i]=='U')
        {
            if(b==1)
            {
                a=0;ans++;
            }
            b=-1;
        }
        else{
            if(b==-1)
            {
                ans++;a=0;
            }
            b=1;
        }
    }
    printf("%d",ans+1);
    return 0;
}