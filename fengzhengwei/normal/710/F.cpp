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
char c[1000005];
struct ADD_DEL
{
	int val[1000005];
	int sum[1000005];
	int to[1000005][26];
	int fail[1000005];
	int pp[1000005][26];
	int cst;
	void insert(int last)
	{
		int p=strlen(c);
		for(int i=0;i<p;i++)
		{
			if(!to[last][c[i]-'a'])to[last][c[i]-'a']=++cst;
			last=to[last][c[i]-'a'];
		}
		sum[last]=1;
//		cout<<"qweqeqe"<<endl;
	}
	int rt[205],rtnt,rts[205];
	void getfail(int s)
	{
		queue<int>q;
		fail[s]=s;
		for(int i=0;i<26;i++)
		{
			if(to[s][i])q.push(to[s][i]),pp[s][i]=to[s][i],fail[to[s][i]]=s;
			else pp[s][i]=s;
		}
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			val[x]=sum[x]+val[fail[x]];
			for(int i=0;i<26;i++)
			{
				if(!to[x][i])pp[x][i]=pp[fail[x]][i];
				else 
				{
					q.push(to[x][i]);
					pp[x][i]=to[x][i];
					fail[to[x][i]]=pp[fail[x]][i];
				}
			}
		}
	}
	int merge(int x,int y)
	{
//		cout<<x<<" "<<y<<endl;
		if(!x||!y)return x+y;
		sum[x]+=sum[y];
		for(int i=0;i<26;i++)to[x][i]=merge(to[x][i],to[y][i]);
		return x;
	}
	void insert()
	{
		rt[++rtnt]=++cst;
		rts[rtnt]=1;
		insert(cst);
		while(rts[rtnt]==rts[rtnt-1])
		{
			rts[rtnt-1]*=2;
//			cout<<"qweqeqe"<<endl;
			rt[rtnt-1]=merge(rt[rtnt-1],rt[rtnt]);
			rtnt--;
		}
		getfail(rt[rtnt]);
	}
	int ask(int last)
	{
		int ans=0;
		int p=strlen(c);
		for(int i=0;i<p;i++)
		{
//			cout<<last<<"Q"<<" "<<val[last]<<endl;
			last=pp[last][c[i]-'a'];
			ans+=val[last];
		}
		return ans;
	}
	int ask()
	{
		int ans=0;
		for(int i=1;i<=rtnt;i++)ans+=ask(rt[i]);
		return ans;
	}
}ad,re;
signed main(){
//	cout<<sizeof(ad)+sizeof(re)<<endl;
	n=read();
	for(int i=1;i<=n;i++)
	{
		int op=read();
		if(op==1)
		{
			scanf("%s",c);
			ad.insert();
		}
		if(op==2)
		{
			scanf("%s",c);
			re.insert();
		}
		if(op==3)
		{
			scanf("%s",c);
//			cout<<ad.ask()<<endl;
			cout<<ad.ask()-re.ask()<<"\n";
			fflush(stdout);
		}
	}
	return 0;
}