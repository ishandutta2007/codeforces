#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
typedef long long LL;
int q;
map<LL,LL> S;
int main()
{
	scanf("%d",&q);
	while (q--)
	{
		int kd,z;
		LL x,y;
		scanf("%d%lld%lld",&kd,&x,&y);
		if (kd==1)
		{
			scanf("%d",&z);
			while (x!=y)
			{
				if (x>y) swap(x,y);
				if (!S.count(y)) S[y]=z;
				else S[y]=S[y]+z;
				y>>=1;
			}
		}
		else
		{
			LL ans=0;
			while (x!=y)
			{
				if (x>y) swap(x,y);
				if (S.count(y)) ans+=S[y];
				y>>=1;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}