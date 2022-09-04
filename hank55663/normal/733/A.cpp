#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define pii pair<int,int>
#define mp(x,y) make_pair((x),(y))
#define x first
#define y second  
using namespace std;
typedef long long ll;
int main(){
	char c[105];
	gets(c);
	char c1[10]={'A','E','I','O','U','Y'};
	int dp[105];
	dp[0]=1;
	int ans=1;
	for(int i=0;c[i]!=0;i++){
		int ok=0;
		for(int j=0;j<6;j++)
		if(c[i]==c1[j])
		{
			ok=1;
			break;
		}
		if(ok)
		dp[i+1]=1;
		else
		dp[i+1]=dp[i]+1;
		ans=max(dp[i+1],ans);
	}
	printf("%d\n",ans);
}