#include<cstdio>
#include<cstdlib>
const int MAXN = 1e5 + 5;

void error(void){ printf("-1"); exit(0);}
inline int max(int a,int b){ return a>b? a: b;}

int a[MAXN],s[MAXN],mx[MAXN];

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i) s[i] = s[i-1]+a[i];
	mx[n]=s[n];
	for(int i=n-1; i>=1; --i) mx[i] = max(mx[i+1], s[i]);
	
	if(mx[1] > d) error();
	int now=0,ans=0;
	for(int i=1; i<=n; ++i)
		if(!a[i])
		{
			s[i]+=now;
			if(s[i]<0)
			{
				if(-s[i] > d-(mx[i]+now)) error();
				now += d-(mx[i]+now);
				++ans;
			}
		}
	printf("%d",ans);
	return 0;
}