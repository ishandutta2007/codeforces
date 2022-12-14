#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
#define MN 100000
#define pa pair<long long,long long>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
pa a[MN+5],b[MN+5];
int n,num1,num2,mnx=1e9,mxx=-1e9,mny=1e9,mxy=-1e9,A[MN+5],B[MN+5],C[MN+5],D[MN+5];
inline long long sqr(int x){return 1LL*x*x;}

bool Solve(long long x)
{
//	cout<<"Solve"<<x<<endl;
	if(sqr(mxx-mnx)<=x || sqr(mxy-mny)<=x) return true;
	long long sq,l=0,r=1e9,mid;
	while(l<=r)
	{
		mid=l+r>>1;
		if(mid*mid<=x) sq=mid,l=mid+1;
		else r=mid-1;	
	}
	for(int i=num1,l=0;i;--i)
	{
		long long Mxx=min((long long)a[i].first,sq-a[i].first);
		l=lower_bound(b+1,b+num2+1,make_pair(Mxx,(long long)1e9))-b-1;
	//	cout<<i<<" "<<Mxx<<" "<<l<<endl;
		long long Mx=max(A[i+1],B[l+1]),Mn=min(C[i+1],D[l+1]);
		if(sqr(Mx - Mn) <=x && sqr(max(Mx,-Mn)) + sqr(a[i].first) <= x) return true;
	}	
	for(int i=num2,l=0;i;--i)
	{
		long long Mxx=min((long long)b[i].first,sq-b[i].first);
		l=lower_bound(a+1,a+num1+1,make_pair(Mxx,(long long)1e9))-a-1;
		long long Mx=max(A[l+1],B[i+1]),Mn=min(C[l+1],D[i+1]);
		if(sqr(Mx - Mn) <=x && sqr(max(Mx,-Mn)) + sqr(b[i].first) <= x) return true;
	}	
	return false;
}

int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		int x=read(),y=read();
		mnx=min(mnx,x);mxx=max(mxx,x);
		mny=min(mny,y);mxy=max(mxy,y);
		if(x>=0) a[++num1]=make_pair(x,y);
		else b[++num2]=make_pair(-x,y);
	}
	sort(a+1,a+num1+1);sort(b+1,b+num2+1);
	for(int i=num1;i;--i) A[i]=max(A[i+1],(int)a[i].second),C[i]=min(C[i+1],(int)a[i].second);
	for(int i=num2;i;--i) B[i]=max(B[i+1],(int)b[i].second),D[i]=min(D[i+1],(int)b[i].second);
	long long l=0,r=1e17,mid,res;
	while(l<=r)
	{
		mid=l+r>>1;	
		if(Solve(mid)) res=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",res);
	return 0;
}