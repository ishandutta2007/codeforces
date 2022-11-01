#pragma comment(linker, "/stack:200000000")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define int ll

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
/*------------------------------------------------------------------------------------------------------*/
const int N=1000005;
int tot=1,n,q[N],l[N],las=1,ans,top,cnt[N],P[N*2],sum[N];
vector<int> S[N*2];
struct node{int son[2],link,mx,endpos;} p[N*2];
inline void extend(int c,int now)
{
	int New=++tot,pre=las;las=New;
	p[New].endpos=now;
	p[New].mx=p[pre].mx+1;
	for(;pre&&!p[pre].son[c];pre=p[pre].link)	p[pre].son[c]=New;
	if(!pre)	p[New].link=1;
	else
	{
		int to=p[pre].son[c];
		if(p[to].mx==p[pre].mx+1)	p[New].link=to;
		else
		{
			int tmp=++tot;
			p[tmp]=p[to];p[tmp].endpos=0;
			p[to].link=p[New].link=tmp;
			p[tmp].mx=p[pre].mx+1;
			for(;pre&&p[pre].son[c]==to;pre=p[pre].link)	p[pre].son[c]=tmp;
		}
	}
}

inline void topsort()
{
	For(i,1,tot)	cnt[p[i].mx]++;
	For(i,1,tot)	cnt[i]+=cnt[i-1];
	Dow(i,1,tot)	P[cnt[p[i].mx]--]=i;
}
inline void Get()
{
	int top = 1;
    q[0] = 0;
    sum[0] = -0x3f3f3f3f;
    for (int i=1;i<=n;i++)
	{
        while (sum[q[top-1]] >= sum[i])top--;
        l[i] = q[top-1];
        q[top++] = i;
    }
}
char s[N];
signed main()
{
	n=read();
	scanf("\n%s",s+1);
	For(i,1,n)	extend(s[i]-'(',i);
	For(i,1,n)	if(s[i]=='(')	sum[i]=sum[i-1]+1;
	else	sum[i]=sum[i-1]-1;
	S[n].push_back(0);
	For(i,1,n)	S[sum[i]+n].push_back(i);
	
	topsort();
	Dow(i,1,tot)
	{
		int x=P[i];
		if(!p[p[x].link].endpos)	p[p[x].link].endpos=p[x].endpos;
	}
	Get();
	For(i,2,tot)
	{
		int r=p[i].endpos;
		int L=max(l[r],r-p[i].mx);
		int R=min(r,r-p[p[i].link].mx);
		if(s[r]=='(')	continue;
		ans+=max(0,lower_bound(S[sum[r]+n].begin(),S[sum[r]+n].end(),R)-lower_bound(S[sum[r]+n].begin(),S[sum[r]+n].end(),L));
	}
	writeln(ans);
}