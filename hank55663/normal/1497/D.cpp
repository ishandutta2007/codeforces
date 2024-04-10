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
#define index Index
using namespace std;
LL Max[5005];
bool solve(){
	MEM(Max);
	int n;
	scanf("%d",&n);
	int tag[5005],s[5005];
	for(int i = 1;i<=n;i++)scanf("%d",&tag[i]);
	for(int i=1;i<=n;i++)scanf("%d",&s[i]);
	LL ans=0;
	for(int i = 2;i<=n;i++){
		LL dp[5005];
		MEM(dp);
		LL Max2[5005];
		MEM(Max2);
		for(int j = i-1;j>=1;j--){
			Max2[j]=Max2[j+1];
			if(tag[i]!=tag[j]){
				Max2[j]=max(Max2[j],Max[j]+abs(s[i]-s[j]));
				Max[i]=max(Max[i],Max[j]+abs(s[i]-s[j]));
				ans=max(ans,Max[i]);
			//	printf("(%d,%d),%d\n",j,i,Max[j]+abs(s[i]-s[j]));
			}
		}
		for(int j = 1;j<i;j++){
			if(tag[j]!=tag[i]){
				Max[j]=max(Max[j],Max2[j+1]+abs(s[i]-s[j]));
				//printf("(%d,%d),%d\n",i,j,Max2[j+1]+abs(s[i]-s[j]));
				ans=max(ans,Max[j]);
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	int t=1;//000000;
	scanf("%d",&t);
	while(t--)solve();
}