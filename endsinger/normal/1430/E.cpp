#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N],b[N];
char s[N];
vector<int>v[26],r[26];
long long ans=0;
void add(int x,int v)
{
	for(int i=x;i<=n;i+=i&(-i))
		b[i]+=v;
}
int sum(int x)
{
	int v=0;
	for(int i=x;i;i-=i&(-i))
		v+=b[i];
	return v;
}
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
		v[s[i]-'a'].push_back(i);
	for(int i=0;i<26;i++)
	{
		r[i]=v[i];
		reverse(r[i].begin(),r[i].end());
		for(int j=0;j<v[i].size();j++)
			a[v[i][j]]=n-r[i][j]+1;
	}
	for(int i=1;i<=n;i++)
	{
		ans+=sum(n)-sum(a[i]);
		add(a[i],1);
	}
	printf("%lld\n",ans);
	return 0;
}