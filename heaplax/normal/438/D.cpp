#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 1<<18
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout); 
char ch;void re(int& x)
{
	while(ch=getchar(),ch<33);x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
}
using namespace std;
int n,m,s[N];
int l[N],r[N],mx[N];
long long sum[N];
void upd(int k)
{
	sum[k]=sum[k<<1]+sum[k<<1|1];
	mx[k]=max(mx[k<<1],mx[k<<1|1]);
}
void build(int k,int a,int b)
{
	l[k]=a,r[k]=b;
	if(a == b)
	{
		mx[k]=sum[k]=s[a];
		return;
	}
	build(k<<1,a,a+b>>1);
	build(k<<1|1,(a+b>>1)+1,b);
	upd(k);
}
void change(int k,int a,int b)
{
	if(l[k]==r[k])
	{
		mx[k]=sum[k]=b;
		return;
	}
	if(a<=(l[k]+r[k]>>1))change(k<<1,a,b);
	else change(k<<1|1,a,b);
	upd(k);
}
void mod(int k,int a,int b,int x)
{
	if(a>r[k] || b<l[k] || mx[k] < x)return;
	if(l[k] == r[k])
	{
		sum[k]%=x;
		mx[k]=sum[k];
		return;
	}	
	mod(k<<1,a,b,x);
	mod(k<<1|1,a,b,x);
	upd(k);
}
long long sol(int k,int a,int b)
{
	if(a>r[k] || b<l[k])return 0;
	if(a<=l[k] && b>=r[k])return sum[k];
	return sol(k<<1,a,b)+sol(k<<1|1,a,b);
}
int main()
{
	//open(mod);
	re(n),re(m);
	for(int i=1;i<=n;++i)re(s[i]);
	build(1,1,n);
	for(int opt,a,b,c;m--;)
	{
		re(opt),re(a),re(b);
		if(opt==1)
			printf("%I64d\n",sol(1,a,b));
		if(opt==2)
			re(c),mod(1,a,b,c);
		if(opt==3)
			change(1,a,b);
	}
}
/*
5 5
1 2 3 4 5
2 3 5 4
3 3 5
1 2 5
2 1 3 3 
1 1 3
*/