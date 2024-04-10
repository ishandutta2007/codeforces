#include<cstdio>
#include<cmath>
const int MAXP = 1e7 + 5;
const int lb = 26;

int son[MAXP][2],ans[MAXP],pcnt=1;

inline void insert(int p,int k)
{
	int u=1;
	ans[u]+=k;
	for(int i=lb; i>=0; --i)
	{
		int bit=(p>>i)&1;
		if(!son[u][bit]) son[u][bit]=++pcnt;
		u=son[u][bit];
		ans[u]+=k;
	}
}
inline int query(int p,int l)
{
	int u=1,res=0;
	for(int i=lb; i>=0; --i)
	{
		if(!u) break;
		int bit=(p>>i)&1;
		if((l>>i)&1)
		{
			res+=ans[son[u][bit]];
			u=son[u][bit^1];
		}
		else
		{
			u=son[u][bit];
		}
	}
	return res;
}

int main(void)
{
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int t,p;
		scanf("%d%d",&t,&p);
		if(t==1) insert(p,1);
		else if(t==2) insert(p,-1);
		else
		{
			int l;
			scanf("%d",&l);
			printf("%d\n",query(p,l));
		}
	}
	return 0;
}