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

int main()
{
    n=read();m=240-read();
    int i=1;
    while(i<=n)
    {
        if(m<i*5) break;
        m-=i*5;i++;
    }
    cout<<i-1;
    return 0;
}