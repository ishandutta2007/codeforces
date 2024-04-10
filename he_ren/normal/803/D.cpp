#include<cstdio>
const int MAXL = 1e6 + 5;
const int MAXN = 1e6 + 5;

char s[MAXL];
int a[MAXN],n=0,k;

inline void read_a(void)
{
	int now=0;
	char c=getchar();
	while(c!='\n')
	{
		++now;
		if(c==' ' || c=='-')
		{
			a[++n]=now;
			now=0;
		}
		c=getchar();
	}
	a[++n]=now;
}

inline bool chk(int mid)
{
	int cnt=1,now=0;
	for(int i=1; i<=n; ++i)
	{
		if(now+a[i]>mid)
		{
			now=0;
			++cnt;
		}
		now+=a[i];
		
		if(cnt>k) return 0;
	}
	return 1;
}

int main(void)
{
	scanf("%d\n",&k);
	read_a();
	
	int l=0, r=1e6;
	for(int i=1; i<=n; ++i)
		if(l<a[i]) l=a[i];
	
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(chk(mid)) r=mid;
		else l=mid+1;
	}
	
	printf("%d",l);
	return 0;
}