#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,p1,p2,pre,pos;
bool used[222222];
pair<int,int> a[222222];
vector<int> po;
void out()
{
	if (po.size()==0) return;
	for (int i=0;i<(int)po.size()-1;i++)
	{
		printf("1 %d %d\n",po[i],po[i+1]);
	}
	printf("2 %d\n",po[(int)po.size()-1]);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i].first);
		a[i].second=i;
	}
	sort(a+1,a+n+1);
	p1=n+1;
	for (int i=1;i<=n;i++)
	{
		if (a[i].first>=0) 
		{
			p1=i;
			break;
		}
	}
	p2=n+1;
	for (int i=1;i<=n;i++)
	{
		if (a[i].first>0) 
		{
			p2=i;
			break;
		}
	}
	if ((p1-1)&1)
	{
		po.push_back(a[p1-1].second);
		used[p1-1]=1;
	}
	if (p1==1 && p2==n+1)
	{
		for (int i=1;i<n;i++)
		{
			po.push_back(a[i].second);
		}
		out();
		return 0;
	}
	if (p1==2 && p2==n+1)
	{
		for (int i=2;i<n;i++)
		{
			po.push_back(a[i].second);
		}
		out();
		return 0;
	}
	for (int i=p1;i<p2;i++)
	{
		po.push_back(a[i].second);
		used[i]=1;
	}
	out();
	for (int i=1;i<=n;i++) 
	{
		if (!used[i]) 
		{
			pre=i;
			used[i]=1;
			break;
		}
	}
	pos=pre;
	while(pos<=n)
	{
		while(pos<=n && used[pos]) pos++;
		if (pos>n) break;
		printf("1 %d %d\n",a[pre].second,a[pos].second);
		pre=pos;
		used[pos]=1;
	}
	return 0;
}