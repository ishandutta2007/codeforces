#include<bits/stdc++.h>
using namespace std;
#define N 1000010
typedef long long ll;
int n;
struct Rec{
	int x,y;
	ll w;
	friend bool operator < (const Rec &a,const Rec &b){
		return a.x<b.x;
	}
}a[N];
ll dp[N],ans;
inline ll X(int i){return a[i].x;}
inline ll Y(int i){return dp[i];}
inline long double Slope(int i,int j){
	return 1.0L*(Y(j)-Y(i))/(X(j)-X(i));	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].x>>a[i].y>>a[i].w;
	}
	sort(a+1,a+n+1);
	static int q[N],l,r;
	q[l=r=1]=0;
	for(int i=1;i<=n;++i){
		while(l<r&&a[i].y<=Slope(q[l],q[l+1]))++l;
		dp[i]=dp[q[l]]-a[i].w+1LL*a[i].y*(a[i].x-a[q[l]].x);
		while(l<r&&Slope(i,q[r])>=Slope(q[r],q[r-1]))--r;
		q[++r]=i;	
		ans=max(ans,dp[i]);
	}
	cout<<ans<<'\n';
	return 0;
}