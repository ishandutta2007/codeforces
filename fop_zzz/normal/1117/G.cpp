#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back

using namespace std;

inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))	{if(c=='-')	dp=-1;c=getchar();}
    while(isdigit(c))	t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0)	{putchar('-');x=-x;}	if(x>=10)	write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}

//
/* 
tr1 
tr2 pos
tr3  
*/ 
const int N=1e6+6;
int n,Q,q[N],p[N];
ll ans[N];
vector<int> vec[N];
struct BIT
{
	ll tr[N];
	inline void Upd(int x,int y){for(;x<=n;x+=x&-x)	tr[x]+=y;}
	inline ll Get(int x){ll sum=0;for(;x;x-=x&-x)	sum+=tr[x];return sum;}
	inline ll Ask(int l,int r){return Get(r)-Get(l-1);}
	inline void clear(){For(i,0,n)	tr[i]=0;}
}	tr1,tr2,tr3;
struct node{int l,r,num;}	que[N];
inline bool cmp(node x,node y){return x.r<y.r;}
int top,nxt[N];
inline void Solve(int kd)
{
	Dow(i,1,n)
	{
		while(top&&p[q[top]]<p[i])	top--;
		nxt[i]=q[top];
		q[++top]=i;
	}
	sort(que+1,que+Q+1,cmp);
	int l=1,r=1;
	For(i,1,n)
	{
		vec[nxt[i]].pb(i);
		for(int j=0;j<vec[i].size();++j)
		{
			tr1.Upd(vec[i][j],i-vec[i][j]-1+kd);
			tr2.Upd(vec[i][j],-vec[i][j]);
			tr3.Upd(vec[i][j],-1);
		}
		tr2.Upd(i,i);tr3.Upd(i,1);
		while(que[r+1].r==i&&r+1<=Q)	++r;
		if(que[l].r==i)
		{
			For(j,l,r)
				ans[que[j].num]+=tr1.Ask(que[j].l,que[j].r)+(i+kd)*tr3.Ask(que[j].l,que[j].r)-tr2.Ask(que[j].l,que[j].r);
			r=l=r+1;
		}
	}
	tr1.clear();tr2.clear();tr3.clear();
	For(i,0,n)	vec[i].clear();top=0;
}
int main()
{
	n=read();Q=read();
	For(i,1,n)	p[i]=read();
	For(i,1,Q)	que[i].l=read();
	For(i,1,Q)	que[i].r=read(),que[i].num=i;
	Solve(1);
	reverse(p+1,p+n+1);
	For(i,1,Q)	
	{
		int tl=que[i].l;
		que[i].l=n-que[i].r+1;
		que[i].r=n-tl+1;
	}
	Solve(0);
	For(i,1,Q)	write_p(ans[i]);
}
/*
4 4
3 1 4 2
2 1 1 1
2 3 4 1

*/