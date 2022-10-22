#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int n,u,d,l,r;
int p,q,rr,s;
bool f;
signed main()
{
	int T=read();
	while(T--)
	{
		f=0;
		n=read(),u=read(),r=read(),d=read(),l=read();
		for(int i=0; i<16; i++)
		{
			p=u,q=r,rr=d,s=l;
			if(i&1) --p,--q;
			if(i&2) --rr,--q;
			if(i&4) --rr,--s;
			if(i&8) --p,--s;
			if(p>=0&&q>=0&&rr>=0&&s>=0&&p<=n-2&&q<=n-2&&rr<=n-2&&s<=n-2)
			{
				f=1;
				break;
			}
		}
		if(f) puts("YES");
		else puts("NO");
	}
	return 0;
}