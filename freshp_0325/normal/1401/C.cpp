#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],n,cnt;
bool mov[100005];
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d",&n);
		bool flag=true;
		a[0]=0;
		int re=2147483647;
		for(int i=1;i<=n;++i)	scanf("%d",&a[i]),flag&=(a[i]<=a[i-1]),b[i]=a[i],re=min(re,a[i]),mov[i]=false;
		if(flag)
		{
			puts("YES");
			continue;
		}
		sort(b+1,b+1+n);
		for(int i=1;i<=n;++i)	if(a[i]%re==0)	mov[i]=true;
		for(int i=1;i<=n;++i)
		{
			if(mov[i])	continue;
			if(a[i]!=b[i])
			{
				puts("NO");
				goto fail;
			}
		}
		puts("YES");
		fail:;
	}
	return 0;
}