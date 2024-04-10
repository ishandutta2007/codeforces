#include<bits/stdc++.h>
#define maxn 150020

using namespace std;
typedef long long ll;
char s[maxn];
int a[maxn][26],to[maxn],p,n,k,t,l;
ll ans;
priority_queue<int> q[maxn];

void dfs(int x,int y)
{
    int r=x;
    for (int i=0;i<26;i++)
    {
        int j=a[x][i];
        if (!j) continue;
        dfs(j,y+1);
        if (q[to[r]].size()<q[to[j]].size()) r=j;
    }
    for (int i=0;i<26;i++)
    {
        int j=a[x][i];
        if (!j) continue;
        if (j==r) continue;
        while (!q[to[j]].empty()){
            q[to[r]].push(q[to[j]].top());
            q[to[j]].pop();
        }
    }
    if (q[to[x]].size()) {
        q[to[r]].push(q[to[x]].top());
        q[to[x]].pop();
    }
    else if (x){
        //cout << x << ' ' << q[to[r]].top() << ' ' << y << endl;
        q[to[r]].pop();
        q[to[r]].push(y);
    }
    to[x]=to[r];
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%s",s);
        l=strlen(s); t=0;
        for (int j=0;j<l;j++)
        {
            if (!a[t][s[j]-'a']) a[t][s[j]-'a']=++p;
            t=a[t][s[j]-'a'];
        }
        q[t].push(l);
    }
    for (int i=1;i<=p;i++) to[i]=i;
    dfs(0,0);
    while (!q[to[0]].empty())
    {
        ans=ans+q[to[0]].top();
        q[to[0]].pop();
    }
    cout << ans << endl;
    return 0;
}