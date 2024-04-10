#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=200010;
int n,a,b,c,ans;
int p[N],v[N];
int find(int d)
{
	return upper_bound(p+1,p+1+n,d)-p-1;
}
int main()
{
	scanf("%d",&n);
	scanf("%d%d%d",&a,&b,&c);
	if (a>b) swap(a,b);
	if (b>c) swap(b,c);
	if (a>b) swap(a,b);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<=n;i++) v[i]=1;
	sort(p+1,p+1+n);
	if (p[n]>a+b+c) { printf("-1\n");return 0;}
	while (p[n]>b+c) ans++,n--;
	int i=find(a);
	while (p[n]>a+c)
	{
		ans++;n--;
		while (!v[i]&&i>0) i--;
		if (i<=n&&i>0&&v[i]) v[i]=0,i--;
	}
	i=find(b);
	while (p[n]>a+b&&p[n]>c)
	{
		ans++;n--;
		while (!v[i]&&i>0) i--;
		if (i<=n&&i>0&&v[i]) v[i]=0,i--;
	}
	
	if (a+b>c)
	{
		i=find(c);
		while (p[n]>c)
		{
			ans++;n--;
			while (!v[i]&&i>0) i--;
			if (i<=n&&i>0&&v[i]) v[i]=0,i--;
		}
		int j,k;
		i=find(a),j=find(b),k=n;
		while (1)
		{
			while (!v[k]&&k>0) k--;
			if (j>=k) j=k-1;
			while (!v[j]&&j>0) j--;
			if (i>=j) i=j-1;
			while (!v[i]&&i>0) i--;
			if (i>0&&j>0&&k>0) v[i]=v[j]=v[k]=0,ans++;else break;
		}
		int cnt=0;
		for (int i=1;i<=n;i++) cnt+=v[i];
		ans+=(cnt+1)/2;
		printf("%d\n",ans);
	}
	else
	{
		int j,k;
		i=find(a),j=find(b),k=n;
		while (1)
		{
			while (!v[k]&&k>0) k--;
			if (j>=k) j=k-1;
			while (!v[j]&&j>0) j--;
			if (i>=j) i=j-1;
			while (!v[i]&&i>0) i--;
			if (i>0&&j>0&&k>0) v[i]=v[j]=v[k]=0,ans++;else break;
		}
		i=find(a+b),j=n;
		while (1)
		{
			while (!v[j]&&j>0) j--;
			if (i>=j) i=j-1;
			while (!v[i]&&i>0) i--;
			if (i>0||j>0) v[i]=v[j]=0,ans++;else break;
		}
		printf("%d\n",ans);
	}
	return 0;
}