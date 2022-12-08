#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<#x<<": "<<x<<endl
const int modul = 1e9+7, sz=3e5;

long long inv(long long x)
{
	long long r1=modul, r2=x, r3;
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
	t1%=modul;
	if(t1<0)
		t1+=modul;
	return t1;
}

long long fact[sz], ifact[sz];
long long distribute(long long items, long long slots, long long minH)
{
	if(slots==0)
	{
		if(items==0)
			return 1;
		else
			return 0;
	}
    if(minH*slots>items)
		return 0;
	items-=minH*slots;
	long long ans=fact[slots+items-1];
	ans*=ifact[items], ans%=modul;
	ans*=ifact[slots-1], ans%=modul;
	return ans;
}
int main()
{
	fact[0]=1, ifact[0]=1;
	rep(i,1,sz)
	{
		fact[i]=i*fact[i-1], fact[i]%=modul;
		ifact[i]=inv(fact[i]);
	}
	int f, w, h;
	scanf("%d%d%d",&f,&w,&h);
	long long num=0, den=0;
	// food boxes first
	for(int n=1;n<=f;++n)
		for(int m=n-1;m<=n;++m)
		{
			den+=distribute(f,n,1)*distribute(w,m,1), den%=modul;
			num+=distribute(f,n,1)*distribute(w,m,h+1), num%=modul;
		}
	// wine barrels first
	for(int m=1;m<=w;++m)
		for(int n=m-1;n<=m;++n)
		{
			den+=distribute(f,n,1)*distribute(w,m,1), den%=modul;
			num+=distribute(f,n,1)*distribute(w,m,h+1), num%=modul;
		}
	// debug(num);
	// debug(den);
	if(num==0)
		printf("0\n");
	else
		printf("%lld\n",(num*inv(den))%modul);
}