#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<bitset>
#include<vector>
#include<queue>
#include<set>
#include<map>
#define ll long long
#define MN 200000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
set<int> s[MN+5];
vector<int> v[MN+5];
vector<pair<int,int> >Q[MN+5];
char st[MN+5],S[MN+5];
int n,K[MN+5],c[MN+5][26],fail[MN+5],step[MN+5],last=1,cnt=1,Ans[MN+5],q[MN+5],top,id[MN+5],anslen[MN+5];
void insert(int x)
{
    int p=last,np=++cnt;step[np]=step[p]+1;
    for(;p&&!c[p][x];p=fail[p]) c[p][x]=np;
    if(!p) fail[np]=1;
    else
    {
        int q=c[p][x];
        if(step[q]==step[p]+1) fail[np]=q;
        else
        {
            int nq=++cnt;step[nq]=step[p]+1;
            memcpy(c[nq],c[q],sizeof(c[q]));
            fail[nq]=fail[q];fail[np]=fail[q]=nq;
            for(;c[p][x]==q;p=fail[p]) c[p][x]=nq;
        }
    }
    last=np;
}
void dfs(int x)
{
    for(int i=0;i<v[x].size();++i)
    {
        dfs(v[x][i]);
        if(s[id[x]].size()<s[id[v[x][i]]].size()) swap(id[x],id[v[x][i]]);
        int y=id[v[x][i]];
        while(!s[y].empty()) s[id[x]].insert(*s[y].begin()),s[y].erase(s[y].begin());
    }
    if(Q[x].size())
    {
        top=0;
        for(set<int>::iterator it=s[id[x]].begin();it!=s[id[x]].end();++it) q[++top]=*it;
        sort(Q[x].begin(),Q[x].end());
        while(Q[x].size()&&Q[x].back().first>s[id[x]].size()) Ans[Q[x].back().second]=-1,Q[x].pop_back();
        for(int i=0;i<Q[x].size();++i)
        {
            if(i&&Q[x][i].first==Q[x][i-1].first) {Ans[Q[x][i].second]=Ans[Q[x][i-1].second];continue;}
            int mn=1e9,len=Q[x][i].first;
            for(int j=1;j+len-1<=top;++j) mn=min(mn,q[j+len-1]-q[j]);
            Ans[Q[x][i].second]=mn;
        }
    }
}
int main()
{
    scanf("%s",st+1);n=read();
    for(int i=1;st[i];++i) insert(st[i]-'a'),s[last].insert(i);
    for(int i=2;i<=cnt;++i) v[fail[i]].push_back(i),id[i]=i;
    for(int i=1;i<=n;++i)
    {
        int K=read();scanf("%s",S+1);int x=1,len=0,L=strlen(S+1);anslen[i]=L;
        for(int j=1;S[j];++j)
        {
            int t=S[j]-'a';
            while(x&&!c[x][t]) x=fail[x],len=step[x];
            if(!x) x=1,len=0; else x=c[x][t],++len;
        }
        while(step[fail[x]]>=L) x=fail[x];
        if(len>=L) Q[x].push_back(make_pair(K,i));
        else Ans[i]=-1;
    }
    dfs(1);
    for(int i=1;i<=n;++i) printf("%d\n",Ans[i]>=0?Ans[i]+anslen[i]:-1);
    return 0;
}