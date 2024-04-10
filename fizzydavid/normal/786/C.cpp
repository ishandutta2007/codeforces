#include<bits/stdc++.h>
using namespace std;
const int B=333,mxn=100111;
int l,r,f[mxn],n,a[mxn],it[mxn],cnt,ans[mxn];
void del(int x){cnt-=!(--f[a[x]]);}
void add(int x){cnt+=!(f[a[x]]++);}
void init(){memset(f,0,sizeof(f));cnt=0;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=B;i++)
	{
		init();
		l=1,r=0;
		for(int j=1;j<=n;j++)
		{
			if(it[j]==n)break;
			while(l<=r&&l<=it[j])del(l++);
			if(l>r)l=it[j]+1,r=it[j];
			while(r<=n&&cnt<=j)add(++r);
			del(r--);
			it[j]=r;
			ans[j]++;
		}
	}
	for(int i=1;i<=B&&i<=n;i++)
	{
		init();
		l=it[i]+1,r=it[i];
		while(it[i]<n)
		{
			while(cnt<=i&&r<=n)add(++r);
			del(r--);
			ans[i]++;
			it[i]=r;
			for(int j=l;j<=r;j++)del(j);
			l=r+1;
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}