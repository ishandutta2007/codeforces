#include<bits/stdc++.h>
using namespace std;
const int N=10000;
typedef short int st;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<st,st> pss;
int n;
#define Maxn 101
#define cout cerr
#define FR first
#define SE second
int a[Maxn],b[Maxn];
double ans[Maxn];
pss *dp[Maxn][Maxn];

/*inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}*/

int main(){
	cin>>n;
	for(int i=0;i<=n;++i)
		for(int j=0;j<=i;++j){
			dp[i][j]=new pair<st,st>[N*2+1];
			for(register int k=0;k<=2*N;++k)dp[i][j][k].FR=dp[i][j][k].SE=-30000;
		}
	st S=0,a,b,r=0;
	dp[0][0][0].FR=dp[0][0][0].SE=0;
	for(int i=0;i<n;++i){
		cin>>a>>b;S+=b;
		int ad=2*a-b;
		for(int j=0;j<=i;++j)
			for(int k=0;k<=r;++k){
				st to=dp[i][j][k].FR+a;
				dp[i+1][j+1][k+ad].FR=max(dp[i+1][j+1][k+ad].FR,to);
				dp[i+1][j][k].FR=max(dp[i+1][j][k].FR,dp[i][j][k].FR);
				to=dp[i][j][k].SE+b;
				dp[i+1][j][k].SE=max(dp[i+1][j][k].SE,dp[i][j][k].SE);
				dp[i+1][j+1][k+ad].SE=max(dp[i+1][j+1][k+ad].SE,to);
			}
		r+=2*a-b;
	}
	int res=0;
	for(int j=1;j<=n;++j){
	  	for(int i=0;i<=S;++i)ans[j]=max(ans[j],(double)dp[n][j][i].FR);
	  	for(int i=S+1;i<=2*N;++i){
		  	double to=(dp[n][j][i].SE+S)/2.0;
			  ans[j]=max(ans[j],to);
		  }
		printf("%.10lf ",ans[j]);
	}
	puts("");
	return 0;
}