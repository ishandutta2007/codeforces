#include<iostream>
#include<cstdio>
#define MN 50
using namespace std;
inline int read()
{
    int x = 0 , f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){ if(ch == '-') f = -1;  ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return x * f;
}

int num[MN+5],n,C[MN+5][6];

int main()
{
    n=read();C[0][0]=1;
    for(int i=1;i<=MN;++i)
    {
        C[i][0]=1;
        for(int j=1;j<=5;++j)
            C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
    for(int i=MN;i>=5;--i)
        while(n>=C[i][5]) n-=C[i][5],++num[i];
    for(int i=0;i<=MN;putchar('a'),++i)
        for(int j=1;j<=num[i];++j) putchar('b');
    printf(" aaaaab");
    return 0;
}