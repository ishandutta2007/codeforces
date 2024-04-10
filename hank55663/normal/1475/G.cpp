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
int dp[200005];
bool solve(){
	int n;
	scanf("%d",&n);
	int cnt[200005];
	fill(cnt,cnt+200005,0);
	fill(dp,dp+200005,0);
	for(int i = 0;i<n;i++){
		int x;
		scanf("%d",&x);
		cnt[x]++;
	//	scanf("%d",&a[i]);
	}
	int ans=0;
	for(int i = 200000;i>=1;i--){
		for(int j = i;j<=200000;j+=i){
			dp[i]=max(dp[i],dp[j]+cnt[i]);
		}
		ans=max(ans,dp[i]);
	}
	printf("%d\n",n-ans);
}
int main(){
    int t=1;//00000;
    scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/