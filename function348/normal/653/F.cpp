#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1000010,C=500000;
int n;
char s[N];
int val[N],c[N],last[N],r[N];
int id[N],g1[N],g2[N];
int cmp(int i,int j) { return c[i]<c[j]||(c[i]==c[j]&&i<j);}
struct SA
{
	int ws[N],wv[N],x[N],y[N];
	int s[N],sa[N],rank[N],h[N];
	int cmp(int i,int j,int k)
	{ return y[i]==y[j]&&y[i+k]==y[j+k]&&i+k<n&&j+k<n;}
	void get_SA(int m)
	{
		for (int i=0;i<n;i++) ws[x[i]=s[i]]++;
		for (int i=1;i<m;i++) ws[i]+=ws[i-1];
		for (int i=n-1;i>=0;i--) sa[--ws[x[i]]]=i;
		for (int j=1;j<=n;j<<=1)
		{
			int p=0;
			for (int i=n-j;i<n;i++) y[p++]=i;
			for (int i=0;i<n;i++) if (sa[i]>=j) y[p++]=sa[i]-j;
			for (int i=0;i<m;i++) ws[i]=0;
			for (int i=0;i<n;i++) wv[i]=x[y[i]];
			for (int i=0;i<n;i++) ws[wv[i]]++;
			for (int i=1;i<m;i++) ws[i]+=ws[i-1];
			for (int i=n-1;i>=0;i--) sa[--ws[wv[i]]]=y[i];
			swap(x,y);
			p=1;
			x[sa[0]]=0;
			for (int i=1;i<n;i++)
				x[sa[i]]=cmp(sa[i-1],sa[i],j)?p-1:p++;
			m=p;
			if (m>=n) break;
		}
	}
	void get_H()
	{
		for (int i=0;i<n;i++) rank[sa[i]]=i;
		for (int i=0,j=0;i<n;i++)
		{
			if (j) j--;
			if (rank[i]==0) continue;
			int k=sa[rank[i]-1];
			while (s[i+j]==s[k+j]) j++;
			h[rank[i]]=j;
		}
	}
};
SA a;
int calc(int p,int l,int r)
{
	if (g1[p+C]==0) return 0;
	if (l>r) return 0;
	int res=upper_bound(id+g1[p+C],id+g2[p+C]+1,r)-
		    lower_bound(id+g1[p+C],id+g2[p+C]+1,l);
//	printf("%d %d %d %d\n",p,l,r,res);
	return res;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) val[i]=s[i]=='('?1:-1;
	for (int i=1;i<=n;i++) c[i]=c[i-1]+val[i];
	for (int i=0;i<=C*2;i++) last[i]=n+1;
	for (int i=n;i>=1;i--)
	{
		last[c[i]+C]=i;
		r[i]=last[c[i-1]-1+C]-1;
		
	}
	for (int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+1+n,cmp);
	for (int i=1;i<=n;i++) g2[c[id[i]]+C]=i;
	for (int i=n;i>=1;i--) g1[c[id[i]]+C]=i;
	for (int i=1;i<=n;i++) a.s[i-1]=s[i];
	a.s[n]=23332;
	a.get_SA(200);
//	for (int i=0;i<n;i++) printf("%d ",a.sa[i]);
	a.get_H();
	long long ans=0;
	for (int i=1;i<=n;i++) ans+=calc(c[i-1],i,r[i]);
//	printf("%d\n",ans);
//	for (int i=0;i<n;i++) printf("%d ",a.sa[i]);printf("\n");
//	for (int i=0;i<n;i++) printf("%d ",a.h[i]);printf("\n");
	for (int i=1;i<n;i++) 
	{
		int j=a.sa[i]+1;
		int t=min(r[j],j+a.h[i]-1);
		ans-=calc(c[j-1],j,t);
	}
	cout<<ans<<endl;
	return 0;
}