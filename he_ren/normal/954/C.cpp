#include<cstdio>
#include<cstdlib>
const int MAXN = 2e5 + 5;
const int inf = 1e9;

int Abs(int x){ return x<0? -x: x;}
void NO(void){ printf("NO"); exit(0);}

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int m=-1;
	for(int i=1; i<n; ++i)
	{
		int dif = Abs(a[i]-a[i+1]);
		if(!dif) NO();
		if(dif > 1)
		{
			if(m==-1) m=dif;
			else if(m!=dif) NO();
		}
	}
	
	if(m==-1) printf("YES\n%d %d",inf,inf);
	else
	{
		for(int i=1; i<n; ++i)
		{
			int x=(a[i]+m-1)/m, y=a[i]%m, xx=(a[i+1]+m-1)/m, yy=a[i+1]%m;
			if(!y) y=m;
			if(!yy) yy=m;
			if(Abs(x-xx)+Abs(y-yy) != 1) NO();
		}
		printf("YES\n%d %d",inf,m);
	}
	return 0;
}