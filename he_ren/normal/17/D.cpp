#include<cstdio>
#include<cstring>
#include<cmath>
typedef long long ll;
const int MAXN = 1e6 + 5;

inline void add(int &a,int b,int mod){ a+=b; if(a>=mod) a-=mod;}
inline void minus(int &a,int mod){ --a; if(a<0) a+=mod;}
int gcd(int a,int b){ return b? gcd(b,a%b): a;}

char s[MAXN],t[MAXN],t2[MAXN];

bool can(int m,int m2)
{
	if(m!=m2) return m>m2;
	for(int i=1; i<=m; ++i)
		if(t[i] != t2[i]) return t[i]>t2[i];
	return 1;
}

int pw(ll a,int b,int mod)
{
	ll res = 1;
	while(b)
	{
		if(b&1ll) res = res*a %mod;
		a = a*a %mod;
		b>>=1ll;
	}
	return res;
}

int main(void)
{
	int c;
	scanf("%s%s%d",s+1,t+1,&c);
	int n=strlen(s+1), m=strlen(t+1);
	for(int i=1; i<=n; ++i) s[i]-='0';
	for(int i=1; i<=m; ++i) t[i]-='0';
	
	int sc=sqrt(c),tmp=c, phi=1;
	for(int i=2; i<=sc && tmp>1; ++i)
		if(tmp%i==0)
		{
			phi *= i-1;
			tmp/=i;
			while(tmp%i==0) tmp/=i, phi*=i;
		}
	if(tmp>1) phi *= tmp-1;
	
	int a=0, b=0;
	for(int i=1; i<=n; ++i) a = ((ll)a*10 + s[i]) %c;
	for(int i=1; i<=m; ++i) b = ((ll)b*10 + t[i]) %phi;
	
	sprintf(t2+1, "%d",phi+1);
	int m2 = strlen(t2+1);
	for(int i=1; i<=m2; ++i) t2[i]-='0';
	
	minus(b,phi);
	if(can(m,m2)) b+=phi;
	int ans = pw(a,b,c);
	minus(a,c);
	ans = (ll)ans*a %c;
	
	if(!ans) ans=c;
	printf("%d",ans);
	return 0;
}