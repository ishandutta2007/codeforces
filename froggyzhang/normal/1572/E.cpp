#include<bits/stdc++.h>
using namespace std;
#define N 404
typedef long long ll;
int n,m;
struct Point{
	int x,y;
	Point(int _x=0,int _y=0){
		x=_x,y=_y;
	}
	friend Point operator - (const Point &a,const Point &b){
		return Point(a.x-b.x,a.y-b.y);
	}
	friend ll operator % (const Point &a,const Point &b){
		return 1LL*a.x*b.y-1LL*a.y*b.x;
	}
}p[N];
ll Z;
bool check(ll z){
	static pair<int,ll> dp[N][N];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n*2-2;++i){
		ll w=(p[i+1]-p[i])%(p[i+2]-p[i]);
		dp[i][i+2]=w>=z?make_pair(1,0LL):make_pair(0,w);
		if(dp[i][i+2].first>=m)return true;
	}
	for(int len=4;len<=n+1;++len){
		for(int l=1;l+len-1<=2*n;++l){
			int r=l+len-1;
			dp[l][r]=make_pair(0,0LL);
			for(int k=l+1;k<r;++k){
				auto t=make_pair(dp[l][k].first+dp[k][r].first,dp[l][k].second+dp[k][r].second+(p[k]-p[l])%(p[r]-p[l]));
				if(t.second>=z)++t.first,t.second=0;
				if(t.first>=m)return true;
				dp[l][r]=max(dp[l][r],t);	
			}
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	++m;
	for(int i=1;i<=n;++i){
		cin>>p[i].x>>p[i].y;
	}
	for(int i=1;i<=n;++i){
		p[i+n]=p[i];	
	}
	ll l=1,r=1e17+233,ans=0;
	while(l<r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			ans=mid,l=mid+1;
		}
		else{
			r=mid;
		}	
	}
	cout<<ans<<'\n';
	return 0;
}