//#include<stdio.h>
//#include<stdlib.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define MEM(x) memset(x,0,sizeof(x))
#define N 100005
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int solve(){
	LL a,b,h,w,n;
	scanf("%I64d %I64d %I64d %I64d %I64d",&a,&b,&h,&w,&n);
	unsigned long long aa[N];
	if(h>=a&&w>=b){
		printf("0\n");
		return 0;
	}
	if(h>=b&&w>=a){
		printf("0\n");
		return 0;
	}
	for(int i=0;i<n;i++)
	scanf("%I64u",&aa[i]);
	sort(aa,aa+n);
	//reverse(aa,aa+n);
	unsigned long long  dp[100005];
	MEM(dp);
	dp[1]=1;
	unsigned long long  sum=1;
	int ans=0;
	for(int i=n-1;i>=0&&i>=n-40;i--){
	//	printf("%d",i);
		sum*=aa[i];
		ans++;
		for(int j=100000;j>=0;j--){
			if(dp[j]){
				if(aa[i]*j>=100000){
					if(dp[100001]==0)
					dp[100001]=aa[i]*j;
					else
					dp[100001]=min(aa[i]*j,dp[100001]);
				}
				else
				dp[aa[i]*j]=1; 
			}
		}
	// 	printf("%d",i);
		for(int j=1;j<=100000;j++){
			if(dp[j]){
			//	printf("%d",j);
				if(h*j>=a&&w*sum/j>=b){
					printf("%d\n",ans);
					return 0;
				}
				if(h*j>=b&&w*sum/j>=a){
					printf("%d\n",ans);
					return 0;
				}
				if(w*j>=a&&h*sum/j>=b){
					printf("%d\n",ans);
					return 0;
				}
				if(w*j>=b&&h*sum/j>=a){
					printf("%d\n",ans);
					return 0;
				}
			}
		}
		if(dp[100001]!=0){
			if(h*dp[100001]>=a&&w*sum/dp[100001]>=b){
				printf("%d\n",ans);
				return 0;
			}
			if(h*dp[100001]>=b&&w*sum/dp[100001]>=a){
				printf("%d\n",ans);
				return 0;
			}
			if(w*dp[100001]>=a&&h*sum/dp[100001]>=b){
				printf("%d\n",ans);
				return 0;
			}
			if(w*dp[100001]>=b&&h*sum/dp[100001]>=a){
				printf("%d\n",ans);
				return 0;
			}
		}
	}
	printf("-1\n");
}
int main() {
//	while(1)
	solve();
} 
//1 1 2 6 3 8 4 11 5 17 6 15 7 13 8 25 9 22 10 27
//1
//2 4 6 8 10
//3 6 9
//4 2 6 8 10
//5 5 10
//6 2 3 4 6 8 10