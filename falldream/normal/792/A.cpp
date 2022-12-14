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

int n,minn=INF,num=0;
int s[200005];
int main()
{
    n=read();
    for(int i=1;i<=n;i++)s[i]=read();
    sort(s+1,s+n+1);
    for(int i=2;i<=n;i++)
    {
        int x=s[i]-s[i-1];
        if(x<minn){minn=x;num=1;}
        else if(x==minn)num++;
    }
    cout<<minn<<endl<<num;
    return 0;
}