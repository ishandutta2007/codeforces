#include<iostream>
#include<cstdio>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
long long ans=0;
int n,m,k,top=0,a[MN+5],last[MN+5],s[MN+5];

bool Solve(int l,int r)
{
//	cout<<"Solve"<<l<<" "<<r<<endl;
	if(a[l]!=a[r]) return 0;
	int nl=l,nr=r;
	for(;nl<r&&a[nl+1]==a[l];) ++nl;
	for(;nr>l&&a[nr-1]==a[r];) --nr;
	if(nl==r&&nr==l){long long tot=1LL*(r-l+1)*m;ans+=tot/k*k;return tot%k==0;} 
	int len=nl-l+1+r-nr+1;
	if(len<k) return 0;
	if(len==k) {int fg=Solve(nl+1,nr-1);ans+=1LL*(m-1+fg)*k;return fg;}
	ans+=1LL*(m-1)*k;return 0;
}

int main()
{
	n=read();k=read();m=read();
	for(int i=1;i<=n;++i)
	{
	 	a[++top]=read();
		if(top==1||a[top]!=a[top-1]) s[top]=1; else s[top]=s[top-1]+1;
		if(s[top]>=k) ans+=1LL*m*k,top-=k;
	}
	Solve(1,top);
	printf("%lld\n",1LL*n*m-ans);
	return 0;
}