#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define LL long long
#define get(x,y,z) ((x-y)*(x-y)+(x-z)*(x-z)+(y-z)*(y-z))

using namespace std;

LL read()
{
	LL ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const LL N=1e5+5;
LL t,x,y,z,a[N],b[N],c[N],ans;

int main()
{
	t=read();
	while(t--)
	{
		x=read();y=read();z=read();
		ans=9223372036854775807;
		for(LL i=1;i<=x;++i)
			a[i]=read();
		for(LL i=1;i<=y;++i)
			b[i]=read();
		for(LL i=1;i<=z;++i)
			c[i]=read();
		sort(a+1,a+1+x);
		sort(b+1,b+1+y);
		sort(c+1,c+1+z);
		for(LL i=1;i<=x;++i)
		{
			LL A=i;
			LL B=lower_bound(b+1,b+1+y,a[i])-b;
			if(B==y+1)
				B=y;
			LL C=lower_bound(c+1,c+1+z,a[i])-c;
			if(C==z+1)
				C=z;
			LL res=get(a[A],b[B],c[C]);
			if(B!=1&&C!=1)
				res=min(res,get(a[A],b[B-1],c[C-1]));
			if(B!=1)
				res=min(res,get(a[A],b[B-1],c[C]));
			if(C!=1)
				res=min(res,get(a[A],b[B],c[C-1]));
			ans=min(ans,res);
		}
		for(LL i=1;i<=y;++i)
		{
			LL B=i;
			LL A=lower_bound(a+1,a+1+x,b[i])-a;
			if(A==x+1)
				A=x;
			LL C=lower_bound(c+1,c+1+z,b[i])-c;
			if(C==z+1)
				C=z;
			LL res=get(a[A],b[B],c[C]);
			if(A!=1&&C!=1)
				res=min(res,get(b[B],a[A-1],c[C-1]));
			if(A!=1)
				res=min(res,get(b[B],a[A-1],c[C]));
			if(C!=1)
				res=min(res,get(b[B],a[A],c[C-1]));
			ans=min(ans,res);
		}
		for(LL i=1;i<=z;++i)
		{
			LL C=i;
			LL B=lower_bound(b+1,b+1+y,c[i])-b;
			if(B==y+1)
				B=y;
			LL A=lower_bound(a+1,a+1+x,c[i])-a;
			if(A==x+1)
				A=x;
			LL res=get(a[A],b[B],c[C]);
			if(B!=1&&A!=1)
				res=min(res,get(c[C],b[B-1],a[A-1]));
			if(B!=1)
				res=min(res,get(c[C],b[B-1],a[A]));
			if(A!=1)
				res=min(res,get(c[C],b[B],a[A-1]));
			ans=min(ans,res);
		}
		printf("%lld\n",ans);
	}
	return 0;
}