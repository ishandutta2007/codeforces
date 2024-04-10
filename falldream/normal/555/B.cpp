#include<algorithm>
#include<iostream>
#include<cstdio>
#include<queue>
#define MN 200000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
#define pa pair<long long,int>
pa b[MN+5];long long L[MN+5],R[MN+5];
int n,m,res[MN+5];
struct data{long long l,r,id;}a[MN+5];
priority_queue<pa,vector<pa>,greater<pa> >q;
bool cmp(const data&a,const data&b){return a.l<b.l;}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)scanf("%lld%lld",&L[i],&R[i]);
	for(int i=1;i<n;++i) a[i]=(data){L[i+1]-R[i],R[i+1]-L[i],i};
	for(int i=1;i<=m;++i) scanf("%lld",&b[i].first),b[i].second=i;
	sort(a+1,a+n,cmp);sort(b+1,b+m+1);
//	for(int i=1;i<=n;++i) printf("%lld %lld\n",a[i].l,a[i].r);
//	for(int j=1;j<=m;++j) printf("%lld %lld\n",b[j].first,b[j].second);
	int j=1,k=1;
	for(;k<=m;++k) if(j<n&&a[j].l<=b[k].first)
		q.push(make_pair(a[j].r,a[j].id)),++j,--k;
	else if(q.size()) 
	{
		pa p=q.top();q.pop();
		if(p.first<b[k].first) return 0*puts("No");
		else res[p.second]=b[k].second; 
	}
	if(q.size()||j<n) return 0*puts("No"); 
	puts("Yes");
	for(int i=1;i<n;++i) printf("%d ",res[i]);
	return 0;
}