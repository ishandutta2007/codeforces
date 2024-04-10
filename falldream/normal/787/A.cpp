#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<algorithm>
#define ll long long
#define INF 2000000000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int a,b,c,d;
bool mark[20000000];

int main()
{
    a=read();b=read();c=read();d=read();
    for(int i=0;i<=100000;i++)
        mark[b+i*a]=1;
    for(int j=0;j<=100000;j++)
        if(mark[d+j*c])return 0*printf("%d",d+j*c);
    puts("-1");
    return 0;
}