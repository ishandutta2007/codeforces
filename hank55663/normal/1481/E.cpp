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
int l[500005],r[500005],cnt[500005];
void solve(){
	int n;

	scanf("%d",&n);
	int a[500005];
	for(int i = 1;i<=n;i++){
		l[i]=1e9;
		r[i]=0;
		cnt[i]=0;
	}
	int dp[500005];
	for(int i =1;i<=n;i++){
		scanf("%d",&a[i]);
		l[a[i]]=min(l[a[i]],i);
		r[a[i]]=max(r[a[i]],i);
		cnt[a[i]]++;
	}
	dp[0]=0;
	for(int i = 1;i<=n;i++){
		dp[i]=dp[i-1];
		if(r[a[i]]==i){
			dp[i]=max(dp[i],dp[l[a[i]]-1]+cnt[a[i]]);
		}
	}
	int ans=0;
	for(int i = 1;i<=n;i++){
		ans=max(ans,dp[i-1]+cnt[a[i]]);
		cnt[a[i]]--;
	}
	printf("%d\n",n-ans);
}
int main(){
    int t=1;//00000;
    //scanf("%d",&t);
    while(t--)solve();
}
/*

*/