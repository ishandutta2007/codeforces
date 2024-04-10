#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char buf[1<<18],*po1=buf,*po2=buf;
#define getchar() (po1==po2 && (po2=(po1=buf)+fread(buf,1,1<<18,stdin),po1==po2)?EOF:*po1++)
LL read()
{
	LL x=0;
	char c=getchar();
	while(c<'0' || c>'9')	c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
void write(LL x)
{
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
#define mp make_pair
map<LL,LL> M,Id;
map<pair<LL,LL>,bool> Mp;
vector<LL> P[300005];
LL n,m,a[300005],siz[300005];
void Solve()
{
	M.clear(),Id.clear();
	n=read(),m=read();
	for(LL i=1;i<=n;++i)	a[i]=read();
	for(LL i=1;i<=n;++i)	++M[a[i]];
	LL cnt=0;
	for(auto st:M)
	{
		LL v=st.first,w=st.second;
		if(!Id[w])	Id[w]=++cnt;
		LL id=Id[w];
		siz[id]=w;
		P[id].push_back(v);
	}
	Mp.clear();
	for(LL i=1;i<=m;++i)
	{
		LL u=read(),v=read();
		Mp[mp(u,v)]=Mp[mp(v,u)]=true;
	}
	for(LL i=1;i<=cnt;++i)	sort(P[i].begin(),P[i].end());
	LL ans=0;
	for(LL i=1;i<=cnt;++i)
	{
		for(LL p1=LL(P[i].size())-1;p1>=0;--p1)
		{
			for(LL p2=p1-1;p2>=0;--p2)
			{
				LL st1=P[i][p1],st2=P[i][p2];
				if(Mp.find(mp(st1,st2))==Mp.end())
				{
					ans=max(ans,LL(siz[i]+siz[i])*LL(st1+st2));
					break;
				}
			}
		}
	}
	for(LL i=1;i<=cnt;++i)
	{
		for(LL j=i+1;j<=cnt;++j)
		{
			for(LL p1=LL(P[i].size())-1;p1>=0;--p1)
			{
				for(LL p2=LL(P[j].size())-1;p2>=0;--p2)
				{
					LL st1=P[i][p1],st2=P[j][p2];
					if(Mp.find(mp(st1,st2))==Mp.end())
					{
						ans=max(ans,LL(siz[i]+siz[j])*LL(st1+st2));
						break;
					}
				}
			}
		}
	}
	write(ans),puts("");
	for(LL i=1;i<=cnt;++i)	P[i].clear();
}
int main(){
	LL T=read();
	while(T-->0)	Solve();
	return 0;
}