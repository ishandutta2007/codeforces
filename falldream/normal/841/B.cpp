#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int main()
{
    int n=read(),flag=0,tot=0,x;
    for(int i=1;i<=n;++i) x=read(),flag|=(x&1),tot^=((x&1));
    if(tot||flag) puts("First");
    else puts("Second");
    return 0;
}