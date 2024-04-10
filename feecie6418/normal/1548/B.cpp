#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,mx;
ll a[200005],g[200005][20];
ll ABS(ll x){
	if(x<0)return -x;
	return x;
}
ll gcd2(ll x,ll y){
	assert(x>=0&&y>=0);
	if(!x&&!y)return 0;
	if(!x||!y)return x+y;
	return __gcd(x,y);
}
void Solve(){
	scanf("%d",&n),mx=1;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<n;i++)g[i][0]=ABS(a[i]-a[i+1]);
	for(int j=1;j<=18;j++)
		for(int i=1;i+(1<<j)-1<n;i++){
			g[i][j]=gcd2(g[i][j-1],g[i+(1<<j-1)][j-1]);
		}
	for(int i=1;i<n;i++){
		int p=i;
		ll cur=0;
		for(int j=18;j>=0;j--)
			if(g[p][j]!=-1&&gcd2(g[p][j],cur)!=1){
				cur=gcd2(g[p][j],cur),p+=(1<<j);
			}
		mx=max(mx,p-i+1);
	}
	cout<<mx<<'\n';
	for(int i=1;i<=n;i++)a[i]=0;
	for(int j=0;j<=18;j++)for(int i=1;i<=n;i++)g[i][j]=-1;
}
int main(){
	memset(g,-1,sizeof(g));
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}