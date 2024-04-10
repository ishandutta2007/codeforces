#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define ls(x) x<<1
#define rs(x) x<<1|1
#define R (l+r>>1)
#define L (l+r>>1)+1
#define MAXN 100001
int N,M,f[MAXN*2],siz[MAXN*2],top,sta[MAXN*100];vector<pair<int,int>>E[MAXN*4];map<int,int>id[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void upd(int k,int l,int r,int x,int y,int u,int v){if(l>=x&&r<=y)return E[k].push_back({u,v});x<=R&&(upd(ls(k),l,R,x,y,u,v),0),y>=L&&(upd(rs(k),L,r,x,y,u,v),0);}
int getf(int x){return f[x]==x?x:getf(f[x]);}
void mrg(int x,int y){x=getf(x),y=getf(y);if(siz[x]>siz[y])swap(x,y);f[x]=y;siz[y]+=siz[x];sta[++top]=x;}
void ask(int k,int l,int r)
{
	int flag=1,lst=top;for(auto i:E[k]){int u=i.first,v=i.second;if(getf(u)==getf(v)){flag=0;break;}mrg(u,v+N);mrg(v,u+N);}
	if(flag){if(l==r)cout<<"YES\n";else ask(ls(k),l,R),ask(rs(k),L,r);}else For(i,l,r)cout<<"NO\n";
	while(top>lst)siz[f[sta[top]]]-=siz[sta[top]],f[sta[top]]=sta[top],top--;
}
int main()
{
	N=get(),M=get();For(i,1,N*2)f[i]=i,siz[i]=1;vector<pair<pair<int,int>,pair<int,int>>>e;e.resize(1);
	For(i,1,M){int u=get(),v=get();if(!id[u][v]&&!id[v][u])id[u][v]=id[v][u]=e.size(),e.push_back({{u,v},{i,M}});else e[id[u][v]].second.second=i-1,id[u][v]=id[v][u]=0;}
	int K=e.size()-1;For(i,1,K)upd(1,1,M,e[i].second.first,e[i].second.second,e[i].first.first,e[i].first.second);ask(1,1,M);return 0;
}