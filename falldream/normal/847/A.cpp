#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<queue>
#include<map>
#include<set>
#define MN 100
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,l[MN+5],r[MN+5],From=0,To=0;
queue<int> q1;
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
    {
        l[i]=read();r[i]=read();
        if(!l[i])if(!From)From=i;else q1.push(i);
    }
    for(int i=From;;)
    {
        if(!r[i])
        {
            if(!q1.size()) break;
            r[i]=q1.front(),q1.pop(),l[r[i]]=i;
        }
        i=r[i];
    }
    for(int i=1;i<=n;++i) printf("%d %d\n",l[i],r[i]);
    return 0;
}