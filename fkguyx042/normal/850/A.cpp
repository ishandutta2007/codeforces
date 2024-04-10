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

int i,j,m,n,p,k,l,ans[N];

struct Node{
		int  a[5];
		void read()
		{
				int i;
				for (i=0;i<5;++i) scanf("%d",&a[i]); 
		}
}A[N];
int main()
{
		scanf("%d",&n);
		for (i=1;i<=n;++i) A[i].read(); 
		if (n>=100) printf("%d\n",0);
		else 
		{
				for (i=1;i<=n;++i)
				{
					int flag=0; 
					for (j=1;j<=n;++j)
						for (k=1;k<=n;++k)
							if (i!=j&&i!=k&&j!=k)
							{
								 int s=0;
								 for (l=0;l<5;++l) s+=(A[j].a[l]-A[i].a[l])*(A[k].a[l]-A[i].a[l]);
									 if (s>0) flag=1;
							}
					if (!flag) ans[++ans[0]]=i;
				}
				printf("%d\n",ans[0]);
				for (i=1;i<=ans[0];++i) 
				printf("%d\n",ans[i]);
		}
}