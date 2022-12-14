#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define MN 50
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;long long ans=0;
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
    {
        int x=read();
        if(q.size()&&q.top()<x) ans+=x-q.top(),q.pop(),q.push(x);
        q.push(x);
    }
    printf("%lld\n",ans);
    return 0;
}