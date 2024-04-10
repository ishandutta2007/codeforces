#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n;
int pos[200005];
int a[200005];
int b[200005];
int lb(int x)
{
	return x&(-x);
}
int sum[200005];
void add(int x)
{
	for(;x<=n;x+=lb(x))sum[x]+=1;
}
int ask(int x)
{
	int ans=0;
	for(;x;x-=lb(x))ans+=sum[x];
	return ans;
}
stack<int>stk;
int main(){
	n=read();
	int tot=0;
	for(int i=1;i<=n*2;i++)
	{
		char c;
		while((c=getchar())!='+'&&c!='-');
		if(c=='+')
		{
			pos[i]=1;
			stk.push(++tot);
		}
		if(c=='-')
		{
			pos[i]=0;
			a[i]=read();
			if(stk.empty())
			{
				printf("NO\n");
				return 0;
			}
			b[stk.top()]=a[i];
			if((n-a[i]+1)-(ask(n)-ask(a[i]))<stk.size())
			{
				printf("NO\n");
				return 0;
			}
			add(a[i]);
			stk.pop();
		}
	}
	tot=0;
	set<int>q;
	for(int i=1;i<=n*2;i++)
	{
		if(pos[i]==1)
		{
//			if(!q.empty()&&(*(--q.end()))<b[++tot])
//			{
//				printf("NO\n");
//				return 0;
//			}
			q.insert(b[++tot]);
		}
		else
		{
			if(*(q.begin())!=a[i])
			{
				printf("NO\n");
				return 0;
			}
			q.erase(a[i]);
		}
	}
	printf("YES\n");
	for(int i=1;i<=n;i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;
	return 0;
}