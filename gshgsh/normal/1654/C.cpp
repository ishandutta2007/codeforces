#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
#include<map>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int T,N,a[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get();map<ll,int>cnt;For(i,1,N)cnt[a[i]]++;priority_queue<ll>q;ll sum=0;For(i,1,N)sum+=a[i];q.push(sum);
		int flag=N;int opt=0;
		while(!q.empty())
		{
			ll u=q.top();q.pop();if(cnt[u])cnt[u]--,flag--;else q.push(u>>1),q.push(u+1>>1),opt++;
			if(opt>N+5)break;
		}
		cout<<(!flag?"YES\n":"NO\n");
	}
}