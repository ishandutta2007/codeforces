#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<cstring>
#include<set>
#define eps 1e-5
#define inf 1e17
#define For(i,j,k)	for(ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(ll i=k;i>=j;--i)
#define ll long long
#define maxn 1000000
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
	return t*f;
}
int n,k;
ll ans=inf,m,v[300001],all[5][300001],qz_all[300001],qz_sec[300001],qz_fir[300001],qz_non[300001];
int t1,t2,tot[300001],to[6];
inline bool cmp(int x,int y){return v[x]<v[y];}
int main()
{
	n=read();m=read();k=read();
	For(i,1,n)	v[i]=read();
	t1=read();
	For(i,1,t1)
		tot[read()]++;
	t2=read();
	For(i,1,t2)
		tot[read()]+=2;
	For(i,1,n)
		{all[tot[i]][++all[tot[i]][0]]=v[i];}
	For(i,0,3)
		sort(all[i]+1,all[i]+all[i][0]+1);
	For(j,0,3)	
		all[j][all[j][0]+1]=inf,to[j]=0;
	ll tot=0,now=0;
	For(i,0,min(all[3][0],m))
	{
		if(k-i>all[1][0]||k-i>all[2][0])	continue;
		while(to[3]<i)	tot++,to[3]++,now+=all[3][to[3]];
		if(to[1]==k-i+1)
		{
			now-=all[1][to[1]];
			to[1]--;tot--;
		}
		while(to[1]<k-i)	
		{	
			to[1]++;tot++;
			now+=all[1][to[1]];
		}
		if(to[2]==k-i+1)
		{
			now-=all[2][to[2]];
			to[2]--;tot--;
		}
		while(to[2]<k-i)
		{
			to[2]++;tot++;
			now+=all[2][to[2]];
		}
		while(tot<m)
		{
			ll mi=inf;
			For(j,0,3)	mi=min(mi,all[j][to[j]+1]);
			if(mi==inf)	break;
			For(j,0,3)
				if(all[j][to[j]+1]==mi)	
				{
					now+=mi;tot++;
					to[j]++;
					break;	
				}	
		}
//		cout<<i<<' '<<to[0]<<' '<<to[1]<<' '<<to[2]<<' '<<to[3]<<' '<<tot<<' '<<now<<endl;
		if(tot==m)	ans=min(ans,now);
	}
	if(ans==inf)	puts("-1");else	printf("%I64d\n",ans);
}