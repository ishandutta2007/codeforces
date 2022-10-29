#include <bits/stdc++.h>
#define	int 		long long
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii 		vector<pii>
#define mi 			map<int,int>
#define mii			map<int,pii>	
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
int expo(int base, int exponent, int mod) {								//return base^exponent modulo modulus
	int ans = 1;
	while(exponent !=0 ) {
		if((exponent&1) == 1) {
			ans = ans*base ;
			ans = ans%mod;
		}
		base = base*base;
		base %= mod;
		exponent>>= 1;
	}
	return ans%mod;
}
int n,cnt=0,f[2002],cnt2=0,inv[2002];
int C(int x,int y){
	return (((f[x]*inv[y])%hell)*inv[x-y])%hell;
}
void solve()
{
	cin>>n;
	f[0]=1;
	inv[0]=1;
	set<int> s1,s2;
	rep(i,1,n+1){
		f[i]=(i*f[i-1])%hell;
		inv[i]=expo(f[i],hell-2,hell);
		s1.insert(i);
	}
	vi a(n);
	rep(i,0,n){
		cin>>a[i];
		if(a[i]==-1){
			cnt++;
			s2.insert(i+1);
		}
		if(a[i]!=-1)
			s1.erase(a[i]);
	}
	rep(i,1,n+1){
		if(s1.find(i)!=s1.end() && s2.find(i)!=s2.end())
			cnt2++;
	}
	int ans=0;
	rep(i,0,cnt2+1){
		if(i%2==0){			
			ans=(ans+(f[cnt-i]*C(cnt2,i))%hell)%hell;
		}
		else{ 
			ans=(ans-(f[cnt-i]*C(cnt2,i))%hell+hell)%hell;
		}
	}
	cout<<ans;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	return 0;
}