#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
#define newline() printf("\n");
#define printint(x) printf("%d\n");
const int sz = 1e6;
long long m=1e9+7;
int a,b,n;
bool good(long long x)
{
	while(x>0)
	{
		int y = x%10;
		if(y!=a && y!=b)
			return false;
		x/=10;
	}
	return true;
}
long long inv(long long x)
{
	long long r1=m, r2=x, r3;
	long long q, s1=1, s2=0, s3, t1=0, t2=1, t3;
	while(r2!=0)
	{
		q = r1/r2;
		r3 = r1-q*r2;
		s3 = s1-q*s2;
		t3 = t1-q*t2;
		r1=r2, s1=s2, t1=t2;
		r2=r3, s2=s3, t2=t3;
	}
	t1%=m;
	if(t1<0)
		t1+=m;
	return t1;
}
int main()
{
	scanf("%d%d%d",&a,&b,&n);
	long long x = n*a;
	long long choose =  1;
	long long denom=1;
	long long tot=0;
	for(int i=0;i<=n;++i)
	{
	    if(good(x))
		{
			choose*=inv(denom), choose%=m;
			denom = 1;
			tot=(tot+choose)%m;
		}
		x+=b-a;
		choose*=n-i, choose%=m;
		denom*=i+1, denom%=m;
		//debug(choose);
	}
	printf("%lld\n",tot);
}