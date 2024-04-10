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

int n,m;
int s[200005];

int main()
{
    n=read();m=read();
    for(int i=1;i<=m;i++)
    {
        int k=read();bool yes=false;
        for(int j=1;j<=k;j++)
        {
            int x=read();if(x<0)x=(-x)+n;
            if(i==s[(x+n-1)%(n*2)+1]){yes=true;}
            s[x]=i;
        }
        if(!yes)return 0*puts("YES");
    }
    puts("NO");
    return 0;
}