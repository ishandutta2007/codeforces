#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>
#include <queue>
#include <ctime>
#include <cmath>
#include <map>
#pragma comment (linker,"/STACK:32000000")

#define ll long long

using namespace std;

vector <vector <int> > g;
vector <bool> used;
int cnt[100002];

int dfs(int cur)
{
    used[cur]=true;
    int ret=1;
    for(int i=0;i<g[cur].size();i++)
        if (!used[g[cur][i]]) ret+=dfs(g[cur][i]);
    return ret;
}

int dp[100002],tmp[100002];

struct Stack{
    Stack() : size(0) {};
    int what[100001],mn[100001],size;
    int get_min()
    {
        return size==0 ? 1000000 : mn[size-1];
    }
    void push(int x)
    {
        mn[size]=what[size]=x;
        if (size>0) mn[size]=min(x,mn[size-1]);
        ++size;
    }
    void pop()
    {
        size=max(0,size-1);
    }
    int Size()
    {
        return size;
    }
    int back()
    {
        return size==0 ? 1000000 : what[size-1];
    }
};

struct Queue{
    Queue() {};
    Stack s1,s2;
    int get_min()
    {
        return min(s1.get_min(),s2.get_min());
    }
    void push(int x)
    {
        s1.push(x);
    }
    void pop()
    {
        if (!s2.Size())
        {
            while(s1.Size())
            {
                s2.push(s1.back());
                s1.pop();
            }
        }
        s2.pop();
    }
    int size()
    {
        return s1.Size()+s2.Size();
    }
};

bool isLucky(int x)
{
    while(x)
    {
        if (x%10!=4&&x%10!=7) return false;
        x/=10;
    }
    return true;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    g.resize(n);
    used.resize(n);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0;i<n;i++)
        if (!used[i]) ++cnt[dfs(i)];
    for(int i=1;i<=n;i++)
        if (cnt[i]&&isLucky(i))
        {
            cout << 0 << endl;
            return 0;
        }
    for(int i=0;i<=n;i++) dp[i]=1000000;
    dp[0]=0;
    Queue q;
    for(int i=0;i<=n;i++)
    {
        if (!cnt[i]) continue;
        for(int j=0;j<i;++j)
        {
            while(q.size()) q.pop();
            for(int t=j,k=0;t<=n;t+=i,k++)
            {
                tmp[t]=min(dp[t],q.get_min()+k);
                q.push(dp[t]-k);
                if (q.size()>cnt[i]) q.pop();
            }
            for(int t=j;t<=n;t+=i)
                dp[t]=tmp[t];
        }
    }
    int ans=1000000;
    for(int i=1;i<=n;i++)
        if (isLucky(i)) ans=min(ans,dp[i]-1);
    if (ans>=999999) ans=-1;
    cout << ans << endl;
    return 0;
}