#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<#x<<": "<<x<<endl
const int sz=1025;

int n,k,x,f1[sz],f2[sz];
int main()
{
	scanf("%d%d%d",&n,&k,&x);
	rep(i,0,sz)
		f1[i]=0;
	rep(i,0,n)
	{
		int a;
		scanf("%d",&a);
		++f1[a];
	}
	rep(it,0,k)
	{
		rep(i,0,sz)
			f2[i]=0;
		bool par=true;
		rep(i,0,sz)
			if(f1[i]!=0)
			{
				int v=f1[i]/2;
				if(par)
				{
					f2[i]+=v;
					f2[i^x]+=f1[i]-v;
				}
				else
				{
					f2[i^x]+=v;
					f2[i]+=f1[i]-v;
				}
				if(f1[i]%2==1)
					par=!par;
			}
		rep(i,0,sz)
			f1[i]=f2[i];
	}
	int smallest=0;
	for(;f1[smallest]==0;++smallest);
	int biggest=sz-1;
	for(;f1[biggest]==0;--biggest);
	printf("%d %d\n",biggest,smallest);
}