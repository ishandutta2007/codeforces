#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
typedef long long ll;
const int MAXL = 1e6 + 5;
const int mod1 = 19260817;
const int mod2 = 19491001;

int b1,pb1[MAXL],b2,pb2[MAXL];
int hans1[MAXL],hans2[MAXL];

char ans[MAXL],s[MAXL];

int main(void)
{
	srand(time(0));
	
	b1 = rand()%321 + 233;
	pb1[0] = 1;
	for(int i=1; i<MAXL; ++i) pb1[i] = (ll)pb1[i-1]*b1 %mod1;
	
	b2 = rand()%233 + 321;
	pb2[0] = 1;
	for(int i=1; i<MAXL; ++i) pb2[i] = (ll)pb2[i-1]*b2 % mod2;
	
	int n;
	scanf("%d",&n);
	
	int ansl=0;
	for(int j=1; j<=n; ++j)
	{
		scanf("%s",s+1);
		int sl = strlen(s+1);
		
		int h1=0, h2=0, len=0;
		for(int i=1; i<=sl && i<=ansl; ++i)
		{
			h1 = ((ll)h1*b1%mod1 + s[i]) %mod1;
			h2 = ((ll)h2*b2%mod2 + s[i]) %mod2;
			
			if(hans1[ansl] == (h1 + (ll)hans1[ansl-i]*pb1[i])%mod1 && hans2[ansl] == (h2 + (ll)hans2[ansl-i]*pb2[i])%mod2)
				len=i;
		}
		
		for(int i=len+1; i<=sl; ++i)
		{
			ans[++ansl] = s[i];
			hans1[ansl] = ((ll)hans1[ansl-1]*b1 + s[i])%mod1;
			hans2[ansl] = ((ll)hans2[ansl-1]*b2 + s[i])%mod2;
		}
	}
	printf("%s",ans+1);
	return 0;
}