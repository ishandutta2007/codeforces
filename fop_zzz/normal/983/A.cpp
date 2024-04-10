#include<bits/stdc++.h>
#define ll long long
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)

using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')	f=-1;c=getchar();}
	while(isdigit(c))	t=t*10+c-'0',c=getchar();
	return t*f;
}
ll Q,p,q,b;
inline ll mul(ll x,ll y){x%=q;ll sum=0;for(;y;y/=2,x=((x+x)>=q?x+x-q:x+x))	if(y&1)	sum=((sum+x)>=q?sum+x-q:sum+x);return sum;}

inline ll ksm(ll x,ll y){ll sum=1;for(;y;y/=2,x=mul(x,x))	if(y&1)	sum=mul(sum,x);return sum;}
int main()
{
	Q=read();
	For(TTT,1,Q)
	{
		p=read();q=read();b=read();
		ll tmp=ksm(b,64);
		ll ans=mul(tmp,p);
		if(ans==0)	puts("Finite");else	puts("Infinite");
	}
}