#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m,id[3001][3001],cnt,pre[3001],q[6001],head,tail;
vector<int> dp,v[3001],qwq[3001];
bool mp[3001][3001];
long long ans;
inline double slope(int x,int y,int now)
{
    int x1=x,x2=y,c1=(pre[x]-now)*(pre[x]-now),c2=(pre[y]-now)*(pre[y]-now);
    return (x1*x1-x2*x2+c1-c2)*1.0/(x1-x2);
}
int main()
{
    scanf("%d%d",&n,&m);
    ++n,++m;
    dp.push_back(0);
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=m;++j)
        {
            char c=getchar();
            while(c!='0'&&c!='1')
                c=getchar();
            mp[i][j]=c^48;
            if(mp[i][j])
                v[i].push_back(j);
            else
            {
                qwq[i].push_back(j);
                id[i][j]=++cnt;
                dp.push_back(0x3f3f3f3f);
            }
        }
    for(register int i=1;i<=n;++i)
    {
        int lst=-1;
        for(register int j=1;j<=m;++j)
            if(mp[i][j])
                lst=j;
            else
                if(~lst)
                    dp[id[i][j]]=min(dp[id[i][j]],(j-lst)*(j-lst));
        lst=-1;
        for(register int j=m;j;--j)
            if(mp[i][j])
                lst=j;
            else
                if(~lst)
                    dp[id[i][j]]=min(dp[id[i][j]],(lst-j)*(lst-j));
    }
    for(register int i=1;i<=m;++i)
        pre[i]=-1;
    for(register int i=2;i<=n;++i)
    {
    	for(register int j=0;j<(int)(v[i-1].size());++j)
            pre[v[i-1][j]]=i-1;
        head=1;
        tail=0;
        for(register int j=1;j<=m;++j)
        {
            if(pre[j]==-1)
                continue;
            while(head<tail&&slope(q[tail-1],q[tail],i)>slope(q[tail],j,i))
                --tail;
            q[++tail]=j;
        }
        if(head>tail)
            continue;
        for(register int j=0;j<(int)(qwq[i].size());++j)
        {
            int k=qwq[i][j];
            while(head<tail&&slope(q[head],q[head+1],i)<(k<<1))
                ++head;
            dp[id[i][k]]=min(dp[id[i][k]],(q[head]-k)*(q[head]-k)+(pre[q[head]]-i)*(pre[q[head]]-i));
        }
    }
    for(register int i=1;i<=m;++i)
        pre[i]=-1;
    for(register int i=n-1;i;--i)
    {
    	for(register int j=0;j<(int)(v[i+1].size());++j)
            pre[v[i+1][j]]=i+1;
        head=1;
        tail=0;
        for(register int j=1;j<=m;++j)
        {
            if(pre[j]==-1)
                continue;
            while(head<tail&&slope(q[tail-1],q[tail],i)>slope(q[tail],j,i))
                --tail;
            q[++tail]=j;
        }
        if(head>tail)
            continue;
        for(register int j=0;j<(int)(qwq[i].size());++j)
        {
            int k=qwq[i][j];
            while(head<tail&&slope(q[head],q[head+1],i)<(k<<1))
                ++head;
            dp[id[i][k]]=min(dp[id[i][k]],(q[head]-k)*(q[head]-k)+(pre[q[head]]-i)*(pre[q[head]]-i));
        }
    }
    for(register int i=1;i<=cnt;++i)
        ans+=dp[i];
    printf("%lld\n",ans);
    return 0;
}