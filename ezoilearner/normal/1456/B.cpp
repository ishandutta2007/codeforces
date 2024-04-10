#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010
int n,a[MAXN],h[MAXN],add[MAXN],ans=2147483647;

#define lowbit(x) (x&(-x))
inline int highest(int x){while(x-lowbit(x)!=0)x-=lowbit(x);return x;}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		h[i]=highest(a[i]);
		if(h[i]==h[i-1] && h[i-1]==(i==1?0:h[i-2])){puts("1");return 0;}
		add[i]=add[i-1]^a[i];
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=i;++j)for(int k=i+1;k<=n;++k)
		if((add[i]^add[j-1])>(add[k]^add[i]))ans=min(ans,k-j-1);
	printf("%d\n",ans==2147483647?-1:ans);
}