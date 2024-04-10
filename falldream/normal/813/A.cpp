#include<iostream>
#include<cstdio>
#define MN 1000
#define INF 1000000000
using namespace std;
inline int read()
{
    int x = 0 , f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){ if(ch == '-') f = -1;  ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return x * f;
}
int n,m,mn=INF,tot=0;
int main()
{
    n=read();
    for(int i=1;i<=n;++i) tot+=read();
    m=read();
    for(int i=1;i<=m;++i)
    {
        int l=read(),r=read();
        if(r>=tot) mn=min(mn,max(0,l-tot));
    }
    printf("%d",mn==INF?-1:mn+tot);
    return 0;
}