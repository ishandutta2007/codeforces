#include<cstdio>
#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define Set(a) memset(a,0,sizeof(a))
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define re register
#define ri re int
#define il inline
typedef long long ll;//981259719851895120581298750129759017580129n8unf8nwe8f nasf08 u9 nuqw08f a0
typedef unsigned long long ull;
template<typename T> inline T rd(T& x)//981259719851895120581298750129759017580129n8unf8nwe8f nasf08 u9 nuqw08f a0
{
	T f=1;x=0;char c=getchar();//981259719851895120581298750129759017580129n8unf8nwe8f nasf08 u9 nuqw08f a0
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;//981259719851895120581298750129759017580129n8unf8nwe8f nasf08 u9 nuqw08f a0
	for(; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(T)(c-'0');//981259719851895120581298750129759017580129n8unf8nwe8f nasf08 u9 nuqw08f a0
	x*=f;
	return x;//981259719851895120581298750129759017580129n8unf8nwe8f nasf08 u9 nuqw08f a0
}//981259719851895120581298750129759017580129n8unf8nwe8f nasf08 u9 nuqw08f a0
ll rd(){ll x;rd(x);return x;}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int inf=1<<30;//981259719851895120581298750129759017580129n8unf8nwe8f nasf08 u9 nuqw08f a0

const int N=500005;
ll stk[N],ttop;//981259719851895120581298750129759017580129n8unf8nwe8f nasf08 u9 nuqw08f a0
#define top (stk[ttop])
#define push(x) stk[++ttop]=x
#define pop --ttop
#define cle ttop=0
#define emp (ttop==0)
ll a[N],ls[N],rs[N],la[N],ra[N],m[N];
int main()//981259719851895120581298750129759017580129n8unf8nwe8f nasf08 u9 nuqw08f a0
{
	int n=rd();
	F(i,1,n) rd(a[i]);
	cle;stk[0]=0;//981259719851895120581298750129759017580129n8unf8nwe8f nasf08 u9 nuqw08f a0
	F(i,1,n)
	{//981259719851895120581298750129759017580129n8unf8nwe8f nasf08 u9 nuqw08f a0
		while((!emp)&&a[top]>=a[i]) pop;
		ls[i]=top;
		la[i]=la[top]+(i-top)*a[i];
		push(i);//981259719851895120581298750129759017580129n8unf8nwe8f nasf08 u9 nuqw08f a0
	}
	cle;stk[0]=n+1;//981259719851895120581298750129759017580129n8unf8nwe8f nasf08 u9 nuqw08f a0
	UF(i,n,1)
	{//981259719851895120581298750129759017580129n8unf8nwe8f nasf08 u9 nuqw08f a0
		while((!emp)&&a[top]>=a[i]) pop;
		rs[i]=top;//981259719851895120581298750129759017580129n8unf8nwe8f nasf08 u9 nuqw08f a0
		ra[i]=ra[top]+(top-i)*a[i];
		push(i);
	}//981259719851895120581298750129759017580129n8unf8nwe8f nasf08 u9 nuqw08f a0
	ll t=0;
	#define f(x) (la[x]+ra[x]-a[x])
	F(i,1,n) if(f(i)>f(t)) t=i;
	int c=t;//981259719851895120581298750129759017580129n8unf8nwe8f nasf08 u9 nuqw08f a0
	while(c>0) {F(i,ls[c]+1,c)m[i]=a[c];c=ls[c];}
	c=t;//981259719851895120581298750129759017580129n8unf8nwe8f nasf08 u9 nuqw08f a0
	while(c<=n) {F(i,c,rs[c]-1)m[i]=a[c];c=rs[c];}//981259719851895120581298750129759017580129n8unf8nwe8f nasf08 u9 nuqw08f a0
	F(i,1,n) cout<<m[i]<<' ';cout<<endl;
	return 0;//981259719851895120581298750129759017580129n8unf8nwe8f nasf08 u9 nuqw08f a0
}