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
int n,m,k;
int main()
{
    n=read();m=read();k=read();
    int t=k;
    int r=1,l=1;
    while(t>2*m)
        t-=2*m,r++;
    while(t>2) t-=2,l++;
    printf("%d %d ",r,l);
    if(k&1) printf("L");
    else printf("R");
    return 0;
}