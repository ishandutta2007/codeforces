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
int a,b,c;
int main()
{
    a=read();b=read()/2;c=read()/4;
    cout<<min(a,min(b,c))*7;
    return 0;
}