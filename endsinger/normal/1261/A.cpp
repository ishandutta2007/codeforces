#include<bits/stdc++.h>
using namespace std;
const int N=2005;
char s[N];
int n,k,m,t;
vector<int>ans;
void change(int l,int r)
{
	ans.push_back(l);
	ans.push_back(r);
	for(int i=l,j=r;;i++,j--)
	{
		if(i>j)
			break;
		swap(s[i],s[j]);
	}
}
void solve(int i,char p)
{
	if(s[i]==p)
		return;
	for(int j=i+1;j<=n;j++)
	{
		if(s[j]==p)
		{
			change(i,j);
			return;
		}
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		k--;
		scanf("%s",s+1);
		ans.clear();
		for(int i=1;i<=k*2;i+=2)
		{
			solve(i,'(');
			solve(i+1,')');
		}
		m=n/2-k;
		for(int i=2*k+1;i<=2*k+m;i++)
			solve(i,'(');
		for(int i=2*k+m+1;i<=n;i++)
			solve(i,')');
		printf("%d\n",ans.size()/2);
		for(int i=0;i<ans.size();i+=2)
			printf("%d %d\n",ans[i],ans[i+1]);
	}
	return 0;
}