#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define last Last
using namespace std;
typedef long long LL;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	LL sum=0;
	LL a[55];
	for(int i=0;i<n;i++){	
		scanf("%lld",&a[i]);
	}
	vector<pair<LL,pii> > v;
	for(int i=0;i<n;i++){
		LL sum=0;
		for(int j=i;j<n;j++){
			sum+=a[j];
			v.pb(mp(sum,mp(i,j)));
		}
	}
	LL ans=0;
	for(int j=60;j>=0;j--){
		int dp[62][62];
		vector<pair<LL,pii> > temp;
		MEM(dp);
		for(auto it:v){
			if(it.x&(1ll<<j)){
				temp.pb(it);
				if(it.y.x==0)
					dp[it.y.y][1]=1;
				else{
					for(int k=0;k<60;k++)
						dp[it.y.y][k+1]|=dp[it.y.x-1][k];
				}
			}
		}
		if(dp[n-1][k]){
			swap(temp,v);
			ans+=(1ll<<j);
		}
	}
	printf("%lld\n",ans);
}