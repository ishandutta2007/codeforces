#include<cstdio>
typedef long long ll;

int gcd(int a,int b){ return b? gcd(b,a%b): a;}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int x;
		scanf("%d",&x);
		int n = 180/gcd(180,x);
		int ans=n;
		while((ll)ans*x/180 >= ans-1)
			ans += n;
		printf("%d\n",ans);
	}
	return 0;
}