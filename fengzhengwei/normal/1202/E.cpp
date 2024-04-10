#include <bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans*10)+c-'0';
	return ans*w;
}
char m[1000005];
char c[1000005];
int n,size;
struct node
{
	struct trie
	{
		int to[26];
		int fail;
		int res;
	}e[1000005];
	int cst;
	void insert()
	{
		int p=strlen(c+1);
		int last=0;
		for(int i=1;i<=p;i++)
		{
			if(!e[last].to[c[i]-'a'])e[last].to[c[i]-'a']=++cst;
			last=e[last].to[c[i]-'a'];
		}
		e[last].res++;
	}
	void getf()
	{
		queue<int>q;
		for(int i=0;i<26;i++)
		{
			if(e[0].to[i])q.push(e[0].to[i]);
		}
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			for(int i=0;i<26;i++)
			{
				if(!e[x].to[i])
				{
					e[x].to[i]=e[e[x].fail].to[i];
					continue;
				}
				e[e[x].to[i]].fail=e[e[x].fail].to[i];
				q.push(e[x].to[i]);
			}
		}
	}
	int vis[1000005];
	void js(int x)
	{
//		cout<<x<<endl;
		if(!vis[e[x].fail])js(e[x].fail);
		vis[x]=1;e[x].res+=e[e[x].fail].res;
	}
	void pre()
	{
		getf();
//		cout<<"wqeqe"<<endl;
		vis[0]=1;
		for(int i=1;i<=cst;i++)
		{
//			cout<<"qweqe"<<endl;
			if(!vis[i])js(i);
//			cout<<e[i].res<<endl;
		}
	}
	ll ans[1000005];
	void pp()
	{
		int last=0;
		for(int i=1;i<=size;i++)
		{
			last=e[last].to[m[i]-'a'];
			ans[i]=e[last].res;
//			cout<<last<<" "<<i<<" "<<ans[i]<<endl;
		}
	}
}s1,s2;
int main(){
	scanf("%s",m+1);
	size=strlen(m+1);
	n=read();
	while(n--)
	{
		scanf("%s",c+1);
		int p=strlen(c+1);
		s1.insert();
		reverse(c+1,c+p+1);
		s2.insert();
	}
//	cout<<"qweqe"<<endl;
	s1.pre();
	s2.pre();
	s1.pp();
	reverse(m+1,m+size+1);
	s2.pp();
	ll ans=0;
	reverse(s2.ans+1,s2.ans+size+1);
	for(int i=1;i<size;i++)
	{
		ans+=s1.ans[i]*s2.ans[i+1];
	}
	cout<<ans<<endl;
	return 0;
}