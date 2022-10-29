#include <bits/stdc++.h>
#define ll          long long
#define hell        1000000007
using namespace std;
ll expo(ll base, ll exponent, ll mod)
{
    ll ans = 1;
    while(exponent !=0 )
    {
        if((exponent&1) == 1)
        {
            ans = ans*base ;
            ans = ans%mod;
        }
        base = base*base;
        base %= mod;
        exponent>>= 1;
    }
    return ans%mod;
}
int ways[1002];
int fact[1000006];
int invfact[1000006];
int C[1005][1005];
void solve()
{
	int n,m,k,i,j;
	cin>>n>>m>>k;
	for(i=0;i<1005;++i)
    for(j=0;j<i+1;++j)
    if(j==0 or j==i) C[i][j]=1;
    else C[i][j]=(C[i-1][j]+C[i-1][j-1])%hell;
    for(i=1;i<=min(k,n);++i)
	{
		ways[i]=expo(i,n,hell);
		for(j=1;j<i;++j)
		ways[i]=((ways[i]-1LL*C[i][j]*ways[i-j])%hell+hell)%hell;
	}
	fact[0]=1;
	invfact[0]=1;
	for(i=1;i<1000006;++i)
	{
		fact[i]=(1LL*fact[i-1]*i)%hell;
		invfact[i]=expo(fact[i],hell-2,hell);
	}
	ll ans=0;
	if(m==1)
	{
		cout<<expo(k,n,hell);
		return;
	}
	for(i=1;i<min(n,k)+1;++i)
	{
		for(j=0;j<i+1;++j)
		{
			int intersection=j;
			int onlystart=i-j;
			int onlyend=i-j;
			ll cur=1;
			cur*=fact[k];
			cur%=hell;
			cur*=invfact[onlystart];
			cur%=hell;
			cur*=invfact[intersection];
			cur%=hell;
			cur*=invfact[onlyend];
			cur%=hell;
			cur*=invfact[k-onlystart-onlyend-intersection];
			cur%=hell;
			cur*=expo(ways[i],2,hell);
			cur%=hell;
			cur*=expo(intersection,n*(m-2),hell);
			cur%=hell;
			ans=(ans+cur)%hell;
		}
	}
	cout<<ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}