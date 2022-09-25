#include<bits/stdc++.h>
using namespace std;
#define N 55
typedef long long ll;
const double inf=1e18;
const double eps=1e-6;
int n,a[N],b[N];
map<int,vector<int> > mp;
bool check(double x){
	static double c[N],dp[2][N];
	double tot=0;
	for(int i=1;i<=n;++i){
		c[i]=a[i]-x*b[i];
		tot+=c[i];
	}
	int u=0;
	for(int i=0;i<=n;++i){
		dp[0][i]=-inf;
	}
	dp[0][0]=0;
	#define update(x,y) x=max(x,y)
	for(auto [jb,V]:mp){
		auto p=V;
		sort(p.begin(),p.end(),[&](int i,int j){return c[i]>c[j];});
		double now=0;
		u^=1;
		for(int i=0;i<=n;++i){
			dp[u][i]=-inf;	
		}
		for(int i=0;i<=(int)p.size();++i){
			for(int j=0;j<=n;++j){
				if(dp[u^1][j]>-inf)update(dp[u][max(0,j-((int)p.size()-i))+i],dp[u^1][j]+now);
			}
			if(i<(int)p.size())now+=c[p[i]];
		}
	}
	return tot-dp[u][0]<=0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		mp[a[i]].push_back(i);
	}
	for(int i=1;i<=n;++i){
		cin>>b[i];
	}
	double l=0,r=1e9;
	while(r-l>eps){
		double mid=(l+r)/2.0;
		if(check(mid)){
			r=mid;	
		}
		else{
			l=mid;
		}
	}
	cout<<(ll)ceil(l*1000)<<'\n';
	return 0;
}