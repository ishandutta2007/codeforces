#include<cstdio>
#include<algorithm>
typedef long long ll;
int gcd(int a,int b){return (!b)?a:gcd(b,a%b);}
inline int abs(int a){return a>0?a:-a;}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
inline void swap(int &a,int &b){int tmp=a;a=b,b=tmp;}
const int N=100005;

int main()
{
	ll a,b,c,d;
	scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
	ll ans=(a+2)*(b+1)+(c+2)*(d+1)+a-c-a*b-c*d;
	printf("%lld\n",ans);
	return 0;
}