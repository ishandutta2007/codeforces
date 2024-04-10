#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<cmath>
#include<string>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define N 500005
#define M 200005
#define seed 23333

using namespace std;
int i,j,m,n,p,k,x,y,tot,cnt,GG,flag,vis[N],Q[N],Re[N],Fa[N],l,size[N],Dep[N],sa[N];
map<pair<int,int>,int>mp;
vector<int>v[N],used[N],two[N],tr[N],S[N];
void link(int x,int y)
{
		v[x].pb(y),v[y].pb(x);
		mp[mk(x,y)]=++tot;
		mp[mk(y,x)]=tot;
		used[x].pb(0); used[y].pb(0);
}
void bao(int j,int la)
{
		S[cnt].pb(la);
		int nx=v[la][j];
		flag&=(nx%n+1==la);
		//mk_the_edge--------------------
		used[la][j]=1;
		two[mp[mk(la,nx)]].pb(cnt);
		//-------------------------------
		if (vis[nx]==cnt) return;
		vis[nx]=cnt;
		int now=lower_bound(v[nx].begin(),v[nx].end(),la)-v[nx].begin();
		if (now==0)
				j=v[nx].size()-1; else j=now-1;
		bao(j,nx);
}
int makeroot(int x)
{ 
     int i,j;
     Q[Q[0]=1]=x; Re[x]=1; Fa[x]=0;
     for (l=1;l<=Q[0];l++)
   { 
           p=Q[l];
           for (j=0;j<tr[p].size();++j)
             if (!vis[tr[p][j]]&&!Re[tr[p][j]])
             { 
                  Re[tr[p][j]]=1;
                  Fa[tr[p][j]]=p;
                  Q[++Q[0]]=tr[p][j];
             }
   }
   for (i=1;i<=Q[0];i++) Re[Q[i]]=0;
   int Maxn=1000000,Max,id=0;
   for (i=Q[0];i;i--)
{ 
       Max=0;
       p=Q[i];
       size[p]=1;
           for (j=0;j<tr[p].size();++j)
         if (!vis[tr[p][j]]&&Fa[p]!=tr[p][j])
       { 
             size[p]+=size[tr[p][j]];
             Max=max(Max,size[tr[p][j]]);
       }
       Max=max(Max,Q[0]-size[p]);
       if (Maxn>Max)
       { 
          Maxn=Max;
          id=p;
       }
}
return id;
}
int cmp(int a,int b)
{
	return a>b;
}
void Fen(int x,int D)
{ 
      int Root=makeroot(x);
      int i;
      Dep[Root]=D;
      vis[Root]=1;
       for (i=0;i<(int)tr[Root].size();++i)
         if (!vis[tr[Root][i]])
        Fen(tr[Root][i],D+1);
}
inline int ww(int a,int b)
{
		int i,len=min(S[a].size(),S[b].size());
		for (i=0;i<len;++i)
			if (S[a][i]!=S[b][i]) return S[a][i]<S[b][i];
		return S[a].size()<S[b].size(); 
}
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;++i)  
			link(i,i%n+1);
	for (i=1;i<=m;++i) 
	{
			scanf("%d%d",&x,&y);
			link(x,y);
	}
	for (i=1;i<=n;++i) sort(v[i].begin(),v[i].end());
	for (i=1;i<=n;++i)
		for (j=0;j<(int)v[i].size();++j)
			if (!used[i][j])
			{
					++cnt;
					used[i][j]=1;
					vis[i]=cnt; flag=1;
					bao(j,i);
					if (flag) GG=cnt;
			}
	for (i=1;i<=tot;++i) if (two[i].size()==2)
	{
			if (two[i][0]==GG||two[i][1]==GG) continue;
			tr[two[i][0]].pb(two[i][1]);
			tr[two[i][1]].pb(two[i][0]);
	}
	memset(vis,0,sizeof(vis));
	for (i=1;i<=cnt;++i) sort(S[i].begin(),S[i].end(),cmp),sa[i]=i;
	Fen(1,1);
	sort(sa+1,sa+cnt+1,ww);
	for (i=1;i<=cnt;++i) if (sa[i]!=GG) printf("%d ",Dep[sa[i]]); 
}