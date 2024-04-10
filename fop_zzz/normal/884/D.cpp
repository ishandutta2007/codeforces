#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#define For(i,j,k) for(ll i=j;i<=k;++i)
#define Dow(i,j,k) for(ll i=k;i>=j;--i)
#define ll long long
#define inf 1e17
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
	return t*f;
}
priority_queue<ll,vector<ll>,greater<ll> > q,qq;
ll n,x,y,ans;
int main()
{
	n=read();
	if(n==1){puts("0");return 0;}
	if(n==2)	{printf("%I64d\n",read()+read());return 0;}
	For(i,1,n)	x=read(),q.push(x);
	qq=q;
	while(1)
	{
		if(q.size()==2){ll t1=q.top();q.pop();ll t2=q.top();q.pop();ans+=t1+t2;q.push(t1+t2);	break;}
		ll t1=q.top();q.pop();
		ll t2=q.top();q.pop();
		ll t3=q.top();q.pop();
		ans+=t1+t2+t3;
		q.push(t1+t2+t3);
		if(q.size()==1)	break;
	}
	ll tans=0;
	ll t1=qq.top();qq.pop();
	ll t2=qq.top();qq.pop();
	tans+=t1+t2;qq.push(t1+t2);
	while(1)
	{
		if(qq.size()==2){ll t1=qq.top();qq.pop();ll t2=qq.top();qq.pop();tans+=t1+t2;qq.push(t1+t2);	break;}
		ll t1=qq.top();qq.pop();
		ll t2=qq.top();qq.pop();
		ll t3=qq.top();qq.pop();
		tans+=t1+t2+t3;
		qq.push(t1+t2+t3);
		if(qq.size()==1)	break;
	}
	ans=min(ans,tans);
	cout<<ans<<endl;
}