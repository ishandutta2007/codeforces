#include<cstdio>
#include<cstring>
const int MAXN = 1e5 + 5;

int p[MAXN];

int main(void)
{
	memset(p,-1,sizeof(p));
	
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int n=a+b+c+d;
	
	int ccc = b-a+d, l=1, r=n;
	if(ccc != c)
	{
		if(ccc+1 == c && a) p[1]=0, --a, ++l;
		else if(ccc+1 == c && c) p[1]=2, --c, ++l;
		else if(ccc-1 == c && b) p[1]=1, --b, ++l;
		else if(ccc-1 == c && d) p[1]=3, --d, ++l;
		else{ printf("NO"); return 0;}
	}
	
	for(int i=l; i<=r; ++i)
	{
		if(i==1)
		{
			if(a) p[i]=0, --a;
			else if(b) p[i]=1, --b;
			else if(c) p[i]=2, --c;
			else if(d) p[i]=3, --d;
			continue;
		}
		
		if(a && p[i-1]==1) p[i]=0, --a;
		else if(b && p[i-1]==0) p[i]=1, --b;
		else if(b && p[i-1]==2) p[i]=1, --b;
		else if(c && p[i-1]==1) p[i]=2, --c;
		else if(c && p[i-1]==3) p[i]=2, --c;
		else if(d && p[i-1]==2) p[i]=3, --d;
	}
	if(a || b || c || d){ printf("NO"); return 0;}
	
	printf("YES\n");
	for(int i=1; i<=n; ++i) printf("%d ",p[i]);
	return 0;
}