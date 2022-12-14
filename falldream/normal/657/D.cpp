#include<algorithm>
#include<iostream>
#include<cstdio>
#define MN 150000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,rt[MN+5],rk[MN+5],lt[MN+5];long long T[MN+5];
pair<int,int> s[MN+5];
bool cmp2(int x,int y){return s[x].first<s[y].first;}
bool cmp(pair<int,int> x,pair<int,int> y){return 1LL*x.first*y.second>1LL*y.first*x.second;}

bool Solve(double mid)
{
//	cout<<"Solve"<<mid<<endl;
	double mx=-1e18;	
	for(int i=1,j;i<=n;i=j+1)
	{
		for(j=i+1;j<=n&&s[rk[j]].first==s[rk[i]].first;++j);--j;
		for(int k=i;k<=j;++k)
		{
			double c=s[rk[k]].first*(1-mid*T[rt[rk[k]]]/T[n]);
			if(c<mx) return false;
		//	cout<<rk[k]<<" "<<c<<" "<<s[rk[k]].first<<" "<<T[rt[rk[k]]]<<" "<<mx<<endl;
		}
		for(int k=i;k<=j;++k) mx=max(mx,s[rk[k]].first*(1-mid*(T[lt[rk[k]]-1]+s[rk[k]].second)/T[n]));
	}
	return true;
}

int main()
{
	n=read();
	for(int i=1;i<=n;++i) s[i].first=read(),rk[i]=i;
	for(int i=1;i<=n;++i) s[i].second=read();
	sort(s+1,s+n+1,cmp);sort(rk+1,rk+n+1,cmp2);
	for(int i=1;i<=n;++i) T[i]=T[i-1]+s[i].second;
	for(int i=1,j;i<=n;i=j+1)
	{
		for(j=i+1;j<=n&&1LL*s[j].second*s[i].first==1LL*s[i].second*s[j].first;++j);--j;	
		for(int k=i;k<=j;++k) rt[k]=j,lt[k]=i;
	}
	double l=0,r=1,mid;
	for(int i=1;i<=100;++i)
	{
		mid=(l+r)/2.0;
		if(Solve(mid)) l=mid;
		else r=mid;
	}	
	printf("%.10lf\n",(l+r)/2.0);
	return 0;
}