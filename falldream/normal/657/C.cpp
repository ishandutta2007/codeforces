#include<algorithm>
#include<iostream>
#include<cstdio>
#include<queue>
#define MN 200000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
priority_queue<long long> q;
pair<int,int> B[MN*2+5];
int n,k,a[MN+5],b,c;
long long ans=1e18,sum[10],num[10];
void Add(int x,int ad){num[x%5]+=ad;sum[x%5]+=ad*(x/5);}
int main()
{
    n=read();k=read();b=read();c=read();b=min(b,c*5);
    for(int i=1;i<=n;++i) a[i]=read()+int(1e9);
    for(int t=0;t<5;++t)
    {
        while(!q.empty()) q.pop();
        for(int i=1;i<=n;++i)
        {
            int x=a[i],C=0;
            while(x%5!=t) ++x,C+=c;
            B[i]=make_pair(x,C);
        }
        sort(B+1,B+n+1);long long tot=0;
        for(int i=1;i<=n;++i)
        {
         //   cout<<i<<" "<<B[i].first<<" "<<B[i].second<<endl;
            q.push(-1LL*B[i].first/5*b+B[i].second);tot+=-1LL*B[i].first/5*b+B[i].second;
          //  cout<<tot<<endl;
            while(q.size()>k) tot-=q.top(),q.pop();
            if(q.size()==k) ans=min(ans,1LL*k*(B[i].first/5)*b+tot);
        }
    }
    printf("%lld\n",ans);
    return 0;
}