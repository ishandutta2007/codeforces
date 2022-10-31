#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
#define double long double
#define pb push_back
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define pqi priority_queue<int>
#define test int tcase; cin>>tcase; for(int tc = 1; tc <= tcase; tc++)
#define inp(a,n,f) int a[n+f];for(int hh=f;hh<n+f;hh++)cin>>a[hh];
#define printdecimal(k) cout<<fixed<<setprecision(k);
#define mem(a,k) memset(a,k,sizeof(a))
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(),v.end()
#define mod (int)(1e9+7)
#define inf LLONG_MAX
int exp(int x,int y){int res=1;x=x%mod;while(y>0){if(y&1)res=(res*x)%mod;y=y>>1;x=(x*x)%mod;}return res;}
int modinv(int x){return exp(x,mod-2);}
int add(int a,int b){a%=mod,b%=mod;a=((a+b)%mod+mod)%mod;return a;}
int sub(int a,int b){a=((a-b)%mod+mod)%mod;return a;}
int mul(int a,int b){a%=mod,b%=mod;a=((a*b)%mod+mod)%mod;return a;}


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int power[60];
	power[0]=1;
	for(int i=1;i<60;i++)
		power[i]=power[i-1]*2;
	test
	{
		int n,result=0;
		cin>>n;
		inp(a,n,0);
		int bit[60]={0};
		for(int i=0;i<n;i++)
			for(int j=0;j<60;j++)
				if(a[i]&power[j]) bit[j]++;
		for(int i=0;i<n;i++)
		{
			int res=0,ret=0;
			for(int j=0;j<60;j++)
			{
				if(a[i]&power[j]) res=add(res,mul(n,power[j]));
				else ret=add(ret,mul(bit[j],power[j]));
			}
			for(int j=0;j<60;j++)
			{
				if(a[i]&power[j])
				{
					int val=mul(bit[j],power[j]);
					result=add(result,mul(val,add(res,ret)));
				}
			}
		}
		cout<<result<<'\n';
	}
	return 0;
}