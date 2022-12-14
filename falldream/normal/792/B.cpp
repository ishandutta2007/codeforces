#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<queue>
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
int n,k,pos=1;
int nx[105],la[105];

void del(int x)
{
    la[nx[x]]=la[x];
    nx[la[x]]=nx[x];
}

int main()
{
    n=read();k=read();
    for(int i=1;i<n;i++)la[i+1]=i,nx[i]=i+1;
    la[1]=n;nx[n]=1;
    for(int i=1;i<=k;i++)
    {
        int a=read()%n;
        for(int j=1;j<=a;j++)
            pos=nx[pos];
        printf("%d\n",pos);
        pos=nx[pos];del(la[pos]);--n;
    }
    return 0;
}