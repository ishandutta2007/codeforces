#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;

int T;
ll dp[55][55];

char opt[20];
bool ask(ll x){
	if(x>1e14)return false;
	printf("? %lld\n",x);
	fflush(stdout);
	scanf("%s",opt);
	if(opt[0]=='L')return true;
	if(opt[1]=='i')exit(0);
	return false;
}

void report(ll x){
	printf("! %lld\n",x);
	fflush(stdout);
	if(!T)exit(0);
}

int main(){
	scanf("%d",&T);
	rep(i,0,54)dp[0][i]=1;
	rep(i,1,54){
		dp[i][0]=dp[i-1][1];
		rep(j,1,54-i)dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
	}
	while(T--){
		ll K=1;
		while(ask(K))K<<=1;
		if(K==1)report(0ll);
		else{
			ll len=K/2,l=K/2,r=K;
			int y=0,x=0;while(dp[x][y]<len)x++;
			rep(j,1,4)ask(l);
			while(len>1){
				assert(x>=0);
				if(!y){
					ask(l);y++;
				}else{
					ll t=min(dp[x-1][y-1],len);
					if(ask(l+t)){
						l+=t;y++;len-=t;
					}else{
						r=l+t;y--;len=t;
					}
				}
				x--;
			}
			report(l);
		}
	}
	return 0;
}