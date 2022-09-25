#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,p[N],q[N];
ll a[N];
int dp[66][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];	
	}
	ll mx=*max_element(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		a[i]=mx-a[i];p[i]=i;
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	#define update(x,y) x=min(x,y)
	for(int k=1;k<=60;++k){
		for(int i=1;i<=n;++i)q[i]=p[i];
		sort(p+1,p+n+1,[&](int i,int j){return a[i]%(1LL<<k)==a[j]%(1LL<<k)?i<j:a[i]%(1LL<<k)>a[j]%(1LL<<k);});
		int t=1;
		while(t<=n&&a[p[t]]>>(k-1)&1)++t;
		int x=0,y=t-1;
		for(int i=0;i<=n;++i){
			int w=dp[k-1][i];
			if(i){
				x<t-1&&q[i]==p[x+1]?++x:++y;
			}
			update(dp[k][x],w+y-x);
			update(dp[k][y],w+n-(y-x));
		}
	}
	cout<<dp[60][0]<<'\n';
	return 0;
}