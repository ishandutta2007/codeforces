#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int mod=1e9+7;
bool solve(){
	int n;
	scanf("%d",&n);
	map<LL,LL> m;
	LL b[200005];
	LL dp[200005];
	dp[0]=1;
	dp[1]=1;
	m[0]=1;
	for(int i = 1;i<=n;i++){
		scanf("%lld",&b[i]);
	}
	LL sum=b[1];
	for(int i = 2;i<=n;i++){
		
		dp[i]=(dp[i-1]*2-m[sum]+mod)%mod;
		//printf("%d %d\n",i,m[sum]);
		//if(m[sum]==0)
		m[sum]=dp[i-1];
		//printf("%d %d %lld\n",i,m[sum],sum);
		m[sum]%=mod;
		
		sum+=b[i];
	}
	/*set<vector<int> > s;
	for(int i = 0;i<(1<<n);i++){
		int sum=0;
		vector<int> a;
		for(int j =1;j<=n;j++){
			if(i&(1<<(j-1))){
				a.pb(b[j]);
				sum+=b[j];
			}
			else{
				a.pb(b[j]-sum);
				sum=b[j];
			}
		}
		s.insert(a);
	}
	printf("%d\n",s.size());
	for(auto it:s){
		for(auto it2:it)
		printf("%d ",it2);
		printf("\n");
	}*/
	printf("%lld\n",dp[n]);
}
int main(){
	int t=1;//000000;
    scanf("%d",&t);
    while(t--)solve();
}