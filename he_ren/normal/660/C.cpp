#include<cstdio>
const int MAXN = 3e5 + 5;

int a[MAXN];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int al=0,ar=0,cnt=0;
	if(!a[1]) ++cnt;
	for(int l=1,r=1; r<=n;)
	{
		while(r<=n && cnt<=m)
		{
			++r;
			if(!a[r]) ++cnt;
		}
		if(r-l > ar-al) al=l, ar=r;
		//printf("%d %d\n",l,r);
		if(!a[l]) --cnt;
		++l;
	}
	
	printf("%d\n",ar-al);
	for(int i=1; i<=n; ++i)
	{
		if(i>=al && i<ar) printf("1");
		else printf("%d",a[i]);
		putchar(' ');
	}
	return 0;
}