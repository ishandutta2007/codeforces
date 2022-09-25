
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include<bits/stdc++.h>
using namespace std;
#define N 100010
const int inf=0x3f3f3f3f;
typedef long long ll;
int n,w,Q,mx[N],mn[N],a[N],ans[N],m,q[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>w>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=m;++i){
		cin>>q[i];
		q[i]=w-q[i];
		mx[i]=-inf,mn[i]=inf;
	}
	for(int i=1;i<=n;++i){
		int t=a[i];
		for(int j=1;j<=m;++j){
			mx[j]=max(mx[j],t);
			mn[j]=min(mn[j],t);
			if(mx[j]-mn[j]>q[j])++ans[j],mx[j]=mn[j]=t;
		}
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<'\n';
	}
	return 0;
}