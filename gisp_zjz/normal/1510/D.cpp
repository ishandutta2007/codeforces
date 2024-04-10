#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef double db;
const int maxn=1e5+10;
db dp[maxn][10];
vector<int> ans;
int a[maxn],n,d,pre[maxn][10];

int main(){
    cin >> n >> d;
    for (int i=1;i<=n;i++) cin >> a[i];
    memset(pre,-1,sizeof(pre));
    for (int i=0;i<=9;i++) dp[0][i]=-1e9;
    dp[0][1]=0;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=9;j++) dp[i][j]=dp[i-1][j];
        for (int j=0;j<=9;j++){
			int k=j*a[i]%10;
			if (a[i]==1||dp[i][k]<dp[i-1][j]+log2(a[i])){
				dp[i][k]=dp[i-1][j]+log2(a[i]);
				pre[i][k]=j;
			}
        }
    }
	if (dp[n][d]<0){
		puts("-1");
	} else {
		for (int i=n;i;i--){
			if (pre[i][d]!=-1) ans.pb(a[i]),d=pre[i][d];
		}
		if (ans.size()==0){puts("-1");return 0;}
		printf("%d\n",(int)ans.size());
		for (auto x:ans) printf("%d ",x);puts("");
	}
	return 0;
}