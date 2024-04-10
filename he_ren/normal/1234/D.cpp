#include<cstdio>
#include<cstring>
const int MAXN = 1e5 + 5;

int n;
char s[MAXN];

struct BIT
{
	int ans[MAXN];
	#define lowbit(x) ((x)&-(x))
	
	inline void update(int x,int k)
	{
		while(x<=n)
			ans[x] += k,
			x += lowbit(x);
	}
	
	inline int query(int x)
	{
		int res=0;
		while(x)
			res += ans[x],
			x^=lowbit(x);
		return res;
	}
}t[27];



int main(void)
{
	int q;
	scanf("%s%d",s+1,&q);
	n=strlen(s+1);
	
	for(int i=1; i<=n; ++i) s[i]-='a';
	for(int i=0; i<26; ++i)
		for(int j=1; j<=n; ++j)
			if(s[j]==i) t[i].update(j, 1);
	
	while(q--)
	{
		int qry;
		scanf("%d",&qry);
		if(qry==1)
		{
			int p;
			scanf("%d",&p);
			char c=getchar();
			while(c<'a' || c>'z') c=getchar();
			c-='a';
			
			t[(int)s[p]].update(p,-1);
			t[(int)c].update(p,1);
			
			s[p]=c;
		}
		else
		{
			int l,r;
			scanf("%d %d",&l,&r);
			int cnt=0;
			for(int i=0; i<26; ++i)
				if(t[i].query(r)-t[i].query(l-1) > 0) ++cnt;
			printf("%d\n",cnt);
		}
	}
	return 0;
}