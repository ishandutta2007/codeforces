#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
#define newline() printf("\n");
#define printint(x) printf("%d\n");
const int sz = 1e6;

int n, q, a[sz],l[sz],r[sz], dif[sz], f[sz];
int main()
{
	scanf("%d%d",&n,&q);
	rep(i,0,n)
		scanf("%d",&a[i]);
	rep(i,0,q)
		scanf("%d%d",&l[i],&r[i]);
	rep(i,0,n)
		dif[i] = 0;
	rep(i,0,q)
	{
		if(l>0)
			++dif[l[i]-1];
		--dif[r[i]];
	}
	int s=0;
	rep(i,0,n)
	{
		s+=dif[i];
		dif[i]=s;
	}
	sort(dif,dif+n);
	sort(a,a+n);
	long long sum=0;
	rep(i,0,n)
	{
		long long x = a[i];
		x*=dif[i];
		sum+=x;
	}
	cout<<sum<<endl;
}