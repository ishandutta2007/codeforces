#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char s[500005];
int n;
int a[500005];
int sg[500005];
void Solve()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int R=0,B=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='R')	++R;
		else	++B;
	}
	if(R^B)
	{
		if(R>B)	puts("Alice");
		else	puts("Bob");
		return ;
	}
	int cnt=0;
	for(int i=1;i<=n;++i)
	{
		int l=i,r=i;
		while(r<n && s[r]!=s[r+1])	++r;
		int d=r-l+1;
		a[++cnt]=d;
		i=r;
	}
	int SG=0;
	for(int i=1;i<=cnt;++i)	SG^=sg[a[i]];
	puts(SG?"Alice":"Bob");
}
int mex(vector<int> &c)
{
	if(c.empty())	return 0;
	sort(c.begin(),c.end());
	c.erase(unique(c.begin(),c.end()),c.end());
	if(c[0]!=0)	return 0;
	for(int i=0;i<int(c.size());++i)	if(i^c[i])	return i;
	return c.size();
}
int main(){
	sg[2]=1;
	for(int i=3;i<=1000;++i)
	{
		vector<int> f;
		for(int j=1;j<=i-1;++j)	f.push_back(sg[j-1]^sg[i-j-1]);
		sg[i]=mex(f);
	}
	for(int i=1001;i<=500000;++i)	sg[i]=sg[i-68]; // OEIS
	int T;
	scanf("%d",&T);
	while(T-->0)	Solve();
	return 0;
}