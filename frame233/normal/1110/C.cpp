#include<cstdio>
int gcd(int a,int b){return (!b)?a:gcd(b,a%b);}
inline int max(int a,int b){return a>b?a:b;}
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n,ans=3;
		scanf("%d",&n);
		if(n==3) ans=1;
		else if(n==7) ans=1;
		else if(n==15) ans=5;
		else if(n==31) ans=1;
		else if(n==63) ans=21;
		else if(n==127) ans=1;
		else if(n==255) ans=85;
		else if(n==511) ans=73;
		else if(n==1023) ans=341;
		else if(n==2047) ans=89;
		else if(n==4095) ans=1365;
		else if(n==8191) ans=1;
		else if(n==16383) ans=5461;
		else if(n==32767) ans=4681;
		else if(n==65535) ans=21845;
		else if(n==131071) ans=1;
		else if(n==262143) ans=87381;
		else if(n==524287) ans=1;
		else if(n==1048575) ans=349525;
		else if(n==2097151) ans=299593;
		else if(n==4194303) ans=1398101;
		else if(n==8388607) ans=178481;
		else if(n==16777215) ans=5592405;
		else if(n==33554431) ans=1082401;
		else
		{
			ans=3;
			for(int i=2;i<=25;++i)
			{
				if(n<(1<<i)) break;
				ans=ans<<1|1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}