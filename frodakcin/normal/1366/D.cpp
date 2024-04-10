#include <cstdio>
#include <cassert>

const int MV = 1e7+10, MN = 5e5+10;
int p[MV], P, c[MV], l[MV], n[MV], f0[MN], f1[MN], N;
int main()
{
	n[1]=1;
	for(int i=2;i<MV;++i)
	{
		if(!c[i])
			l[i]=P, p[P++]=i, n[i]=1;
		for(int j=0,k;j<=l[i]&&(k=i*p[j])<MV;++j)
		{
			assert(k>0);
			assert(!c[k]);
			c[k]=1;
			l[k]=j;
			if(j==l[i])
				n[k]=n[i];
			else
				n[k]=i;
		}
	}
	scanf("%d", &N);
	for(int i=0;i<N;++i)
	{
		int a;
		scanf("%d", &a);
		if(n[a] == 1) f0[i] = f1[i] = -1;
		else
		{
			f0[i]=p[l[a]];
			f1[i]=1;
			for(a=n[a];a!=1;a=n[a]) f1[i]*=p[l[a]];
		}
	}
	for(int i=0;i<N;++i) printf("%d%c", f0[i], " \n"[i+1==N]);
	for(int i=0;i<N;++i) printf("%d%c", f1[i], " \n"[i+1==N]);
}