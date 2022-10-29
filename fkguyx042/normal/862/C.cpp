#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 300005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,p,k,x;

int main()
{
		scanf("%d%d",&n,&x);
		if (n==2&&x==0) puts("NO");
		else 
		{
				puts("YES");
				if (n==1) printf("%d\n",x);
				else if (n==2) printf("%d %d\n",0,x);
				else 
				{
						for (i=1;i<=n-3;++i) x^=i,printf("%d ",i);
						int now=(1<<17);
						if (x==0) printf("%d %d %d\n",now,now*2,(now*2)^now);
						else printf("%d %d %d\n",0,now,now^x);
				}
		}
}