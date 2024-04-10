#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
const int inf=0x3f3f3f3f;
int n,a[N],K,m,dp[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>K;
	for(int i=1;i<=K;++i){
		int l,r;
		cin>>l>>r;
		a[++m]=l,a[++m]=r;
	}
	if(a[m]<2*n)a[++m]=n<<1;
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=m;++i){
		static int g[N];
		memset(g,0x3f,sizeof(g));
		int t=a[i]-a[i-1];
		for(int j=t;j<=2*n;++j){
			g[j]=dp[j-t];
		}
		if(!(i&1)){
			/*twice*/{
				deque<int> q;
				for(int j=0;j<t;++j){
					while(!q.empty()&&dp[j]<dp[q.back()])q.pop_back();
					q.push_back(j);
				}
				for(int j=t;j<=a[i];++j){
					while(!q.empty()&&q.front()<j-t)q.pop_front();
					while(!q.empty()&&dp[j]<dp[q.back()])q.pop_back();
					q.push_back(j);
					g[j]=min(g[j],dp[q.front()]+2);
				}
			}
			/*once*/{
				deque<int> q;
				for(int j=a[i];j>=0;--j){
					while(!q.empty()&&q.front()<a[i-1]-j)q.pop_front();
					while(!q.empty()&&dp[a[i]-j]<dp[q.back()])q.pop_back();
					q.push_back(a[i]-j);
					g[j]=min(g[j],dp[q.front()]+1);
				}
			}
		}
		memcpy(dp,g,sizeof(dp));
	}
	if(dp[n]==inf){
		cout<<"Hungry\n";
	}
	else{
		cout<<"Full\n"<<dp[n]<<'\n';
	}
	return 0;
}