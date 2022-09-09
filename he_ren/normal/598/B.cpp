#include<cstdio>
#include<cstring>
const int MAXN = 1e4 + 5;

char s[MAXN],t[MAXN];

inline int add(int a,int mod)
{
	return a<mod? a: a-mod;
}

int main(void)
{
	int m;
	scanf("%s%d",s+1,&m);
	while(m--)
	{
		int l,r,p;
		scanf("%d%d%d",&l,&r,&p);
		p %= r-l+1;
		
		for(int i=l; i<=r; ++i)
		{
			int j=i+p;
			if(j>r) j-=r-l+1;
			t[j]=s[i];
		}
		for(int i=l; i<=r; ++i)
			s[i]=t[i];
	}
	printf("%s",s+1);
	return 0;
}