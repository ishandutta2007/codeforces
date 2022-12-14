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

int n,m;
int x;
char s[4000];
int main()
{
    n=read();x=0;
    for(int i=1;i<=n;i++)
    {
        m=read();scanf("%s",s);
        if(x==0&&s[0]!='S'){printf("NO");return 0;}
        if(x==20000&&s[0]!='N') {printf("NO");return 0;}
            if(s[0]=='S') {x=x+m;if(x>20000) {printf("NO");return 0;}}
            if(s[0]=='N') {x-=m; if(x<0){ printf("NO");return 0;}}
         //   if(s[0]=='W') y-=m;
         //   if(s[0]=='E') y+=m;
    }
        if(x!=0) printf("NO");
        else printf("YES");
    return 0;
}