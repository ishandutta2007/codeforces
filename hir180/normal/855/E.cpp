#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int n;
ll dp[105][15][1025];
ll calc(int base,ll num){
    if(num<=0) return 0LL;
	ll up = 1,ret = 0;
	for(int i=1;;i++){
		up = up*base;
		if(num >= up){
			for(int x=1;x<base;x++){
				ret += dp[i-1][base][(1<<x)];
			}
			//cout<<ret<<" " <<num<<" " <<i<<endl;
		}
		else{
			int v[65],N=0;
			while(num){
				v[i-N] = num%base;
				N++; num/=base;
			}
			//assert(N==i);
			//top j digit is same
			int premask = 0;
			for(int j=0;j<=i;j++){
				if(j==i){
				    //cout<<ret<<endl;
					ret+=!premask; 
					return ret;
				}
				for(int x=(!j?1:0);x<v[j+1];x++){
					ret += dp[i-j-1][base][premask^(1<<x)];
					
				}
				premask ^= (1<<v[j+1]);
			}
		}
	}
}
int main(){
	cin>>n;
	for(int b=2;b<=10;b++){
		dp[0][b][0] = 1;
		for(int x=0;x<100;x++){
			for(int y=0;y<(1<<b);y++){
				if(dp[x][b][y]==0) continue;
				for(int z=0;z<b;z++){
					dp[x+1][b][y^(1<<z)] += dp[x][b][y];
				}
			}
		}
	}
	rep(i,n){
		int b; ll l,r;
		scanf("%d%lld%lld",&b,&l,&r);
		//cout<<calc(b,l-1)<<endl;
		printf("%lld\n",calc(b,r)-calc(b,l-1));
	}
}