#include<bits/stdc++.h>
#define maxn 2000005
#define x first
#define y second

using namespace std;
typedef pair<int,int> pi;
int query,root,n,m,p,l,pos[maxn][2],pre[maxn],d[maxn],ans;
bool f[maxn];
char s[maxn];
vector <pi> h[maxn];
queue <int> q;

void build(int o)
{
    int t,t2; t=0;
    for (int i=o;i<l;i++)
    {
        t2=-1;
        for (int j=0;j<h[t].size();j++) if (h[t][j].x==s[i]-'a') t2=h[t][j].y;
        if (t2==-1) h[t].push_back({s[i]-'a',++p}),t2=p;
        if (!o) f[t2]=true;
        pos[i][o]=t2; t=t2;
    }
}

int main()
{
    scanf("%d",&query);
    while (query--)
    {
        for (int i=0;i<=p;i++) h[i].clear(),pre[i]=0,f[i]=false,d[i]=0; p=0; ans=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%s",s); l=strlen(s);
            build(0); build(1);
            for (int j=1;j<l;j++) pre[pos[j][0]]=pos[j][1];
        }
        for (int i=1;i<=p;i++) d[pre[i]]++;
        for (int i=1;i<=p;i++) if (!d[i]) q.push(i);
        while (!q.empty())
        {
            int tmp=q.front(); q.pop();
            if (tmp==0) continue;
            if (f[tmp]) ans++,f[pre[tmp]]=false;
            if (!(--d[pre[tmp]])) q.push(pre[tmp]);
        }
        cout << ans << endl;
    }
}