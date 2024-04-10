#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
using namespace std;
inline int read()
{
   int x=0,f=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
   return x*f;
}

priority_queue<int> q;
int n,nown;

void check()
{
    while(!q.empty()&&q.top()==nown)
    {
        printf("%d ",q.top());
        q.pop();nown--;
    }
}

int main()
{
    n=read();nown=n;
    for(int i=1;i<=n;i++)
    {
        int x=read();
        if(x==nown)
            printf("%d ",x),nown--;
        else
            q.push(x);
        check();
        printf("\n");
    }
    return 0;
}