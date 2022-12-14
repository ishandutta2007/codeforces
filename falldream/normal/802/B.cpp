#include<iostream>
#include<cstdio>
#include<queue>
#define pa pair<int,int>
#define mp(x,y) make_pair(x,y)
#define INF 2000000000
#define MN 400000
using namespace std;
inline int read()
{
    int x = 0 , f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){ if(ch == '-') f = -1;  ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return x * f;
}

priority_queue<pa> q;
int n,k,a[MN+5],ne[MN+5],la[MN+5],ans=0;
bool in[MN+5];

int main()
{
    n=read();k=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=n;i;--i)
    {
        ne[i]=la[a[i]]?la[a[i]]:INF;
        la[a[i]]=i;
   //     cout<<i<<" "<<ne[i]<<endl;
    }
    for(int i=1;i<=n;++i)
    {
        if(in[a[i]])
        {
            ++k;
            q.push(mp(ne[i],a[i]));
        }
        else
        {
       //   cout<<i<<endl;
            ++ans;
            while(q.size()==k) in[q.top().second]=0,q.pop();
            q.push(mp(ne[i],a[i]));
            in[a[i]]=1;
        }

    }
    cout<<ans;
    return 0;
}