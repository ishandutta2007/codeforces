#include<cstdio>
const int N=300005;
typedef long long ll;
ll f[N][3];
inline ll max(const ll &a,const ll &b){return a>b?a:b;}
inline void chmax(ll &a,const ll &b){(a<b)&&(a=b);}
int main()
{
	int n,k,x;
	ll ans=0;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		f[i][0]=max(f[i-1][0],0)+x;
		f[i][1]=max(max(f[i-1][0],f[i-1][1]),0)+1ll*x*k;
		f[i][2]=max(max(f[i-1][1],f[i-1][2]),0)+x;
		chmax(ans,max(f[i][0],max(f[i][1],f[i][2])));
	}
	printf("%lld\n",ans);
	return 0;
}