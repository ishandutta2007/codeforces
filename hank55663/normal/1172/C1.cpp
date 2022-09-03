#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
int mod=998244353;
LL f_pow(LL a,LL b){
	LL res=1,temp=a;
	while(b){
		if(b&1)res=res*temp%mod;
		temp=temp*temp%mod;
		b>>=1;
	}
	return res;
}
int cache[5005];
LL inv(int a){
	if(cache[a]!=0)return cache[a];
	return cache[a]=f_pow(a,mod-2);
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int a[55],w[55];
	int li=0,no=0;
	for(int i = 0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i = 0;i<n;i++){
		scanf("%d",&w[i]);
		if(a[i]==0)
			no+=w[i];
		else
			li+=w[i];
	}
	for(int i = 0;i<n;i++){
		LL dp[55][55][55];
		MEM(dp);
		dp[0][0][0]=1;
		//for(int j = 0;j<m;j++){
			for(int ll=0;ll<=m;ll++){
				for(int nn=0;nn<=m&&nn<=no;nn++){
					for(int bb=0;bb<=m;bb++){
						if(a[i]){
							dp[ll+1][nn][bb]+=dp[ll][nn][bb]*(ll+li-bb-w[i])%mod*inv(ll-nn+li+no)%mod;
							dp[ll+1][nn][bb]%=mod;
							dp[ll+1][nn][bb+1]+=dp[ll][nn][bb]*(bb+w[i])%mod*inv(ll-nn+li+no)%mod;
							dp[ll+1][nn][bb+1]%=mod;
							dp[ll][nn+1][bb]+=dp[ll][nn][bb]*(no-nn)%mod*inv(ll-nn+li+no)%mod;
							dp[ll][nn+1][bb]%=mod;
						}
						else{
							if(bb>w[i])
								continue;
							dp[ll+1][nn][bb]+=dp[ll][nn][bb]*(ll+li)%mod*inv(ll-nn+li+no)%mod;
							dp[ll+1][nn][bb]%=mod;
							dp[ll][nn+1][bb+1]+=dp[ll][nn][bb]*(w[i]-bb)%mod*inv(ll-nn+li+no)%mod;
							dp[ll][nn+1][bb+1]%=mod;
							dp[ll][nn+1][bb]+=dp[ll][nn][bb]*(no-nn-w[i]+bb)%mod*inv(ll-nn+li+no)%mod;
							dp[ll][nn+1][bb]%=mod;
						}
						
					}
				}
			}
	//	}
		LL ans=0;
		for(int ll=0;ll<=m;ll++){
			for(int nn=m-ll;nn<=m-ll&&nn<=no;nn++){
				for(int bb=0;bb<=m;bb++){
					if(a[i]){
						ans+=(bb+w[i])*dp[ll][nn][bb]%mod;
					}
					else{
						if(bb>w[i])
							continue;
						ans+=(w[i]-bb)*dp[ll][nn][bb]%mod;
					}
				}
			}
		}
		printf("%lld\n",ans%mod);
	}

}