//
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
signed main()
{
		int n=read();
		// int shit_problem=read();
		// if(shit_problem>1999){puts("-1");continue;}
		puts("1999");
		bool flg=0;
		for(int a=1; !flg; ++a)
		{
			n+=1999;
			for(int La=1; !flg&&La<1999; ++La)
				if(n%La==0&&(n/La)<=(1999-La)*1000000)
				{
					flg=1;
					for(int i=1; i<La; ++i) printf("0 ");
					printf("%lld ",-a);
					for(int i=1,q=n/La; i<=1999-La; ++i)
					{
						int s=min(1000000ll,q);
						printf("%lld ",s);
						q-=s;						
					}
					puts("");
				}
		}
	return 0;
}