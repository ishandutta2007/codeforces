#include<cstdio>
#include<iostream>
#include<vector>
#define FR first
#define SC second
#define MP make_pair
#define pb push_back
using namespace std;
const int N=5010,M=1000100;
typedef pair<int,int> PII;
int n,m,c;
int cnt[M];
PII q[M][12];int len[M];
int a[N],v[M];
PII r[100];
int abs(int n) { return n>0?n:-n;}
/*
int dfs(int j,int k)
{
	if (j==cnt) return 1;
	while (v[r[j].FR]||v[r[j].SC]) 
	{
		j++;
		if (j==cnt) return 1;
	}
	if (k==0) return 0;

	int t=0;
	v[r[j].FR]^=1;
	t=dfs(j+1,k-1);
	v[r[j].FR]^=1;
	if (t) return 1;

	v[r[j].SC]^=1;
	t=dfs(j+1,k-1);
	v[r[j].SC]^=1;
	if (t) return 1;
	return 0;
}*/
int main()
{
	scanf("%d%d",&n,&c);
	m=0;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),m=max(m,a[i]);
	for (int i=1;i<n;i++)
	for (int j=i+1;j<=n;j++)
	{
		int t=abs(a[i]-a[j]);
		if (len[t]<10) q[t][len[t]]=MP(i,j);
		len[t]++;
	}
	for (int i=1;i<=m;i++)
	{
		int res=0,all=0;
		for (int j=i;j<=m;j+=i)
		{
			if (all+len[j]>10) { res=c+1;break;}
			all+=len[j];
			for (int k=0;k<len[j];k++)
			{
				if (v[q[j][k].FR]!=i)
				{
					v[q[j][k].FR]=i;
					if (cnt[a[q[j][k].FR]%i]!=i) cnt[a[q[j][k].FR]%i]=i;else res++;
				}
				
				if (v[q[j][k].SC]!=i)
				{
					v[q[j][k].SC]=i;
					if (cnt[a[q[j][k].SC]%i]!=i) cnt[a[q[j][k].SC]%i]=i;else res++;
				}
			}
			if (res>c) break;
		}
		if (res>c) continue;
		printf("%d\n",i);
		return 0;
	}
	printf("%d\n",m+1);
	return 0;
}