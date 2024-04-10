#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> PII;
priority_queue<PII> S;
int n,k;
long long w,ans;
int c[301010];
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n+k;i++)
	{
		if (i<=n)
		{
		int x;
		scanf("%d",&x);
		w+=x;
		S.push(make_pair(x,i));
		}
		if (i>k) 
		{
			PII tmp=S.top();S.pop();
			w-=tmp.first;
			c[tmp.second]=i;
		}
		ans+=w;
	}
	cout<<ans<<endl;
	for (int i=1;i<=n;i++) printf("%d ",c[i]);
	return 0;
}