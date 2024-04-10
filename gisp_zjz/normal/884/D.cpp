#include<bits/stdc++.h>
#define maxn 1000005

using namespace std;
typedef long long ll;
ll n,t,a[maxn],ans,c[maxn],k;
bool f[maxn];

void dfs(int x)
{
    f[x]=false; t++;
    if (f[a[x]]) dfs(a[x]);
}

int main()
{
    scanf("%d",&n);
    priority_queue <ll,vector<ll> ,greater<ll> > q;
    for (int i=1;i<=n;i++) {scanf("%d",&k);q.push(k);}
    ans=0;
    if (n%2==0){t=q.top();q.pop();t+=q.top();q.pop();q.push(t);ans+=t;}
    while (q.size()>1){
        t=q.top();q.pop();
        t+=q.top();q.pop();
        t+=q.top();q.pop();
        q.push(t);ans+=t;
    }
    printf("%I64d\n",ans);
    return 0;
}