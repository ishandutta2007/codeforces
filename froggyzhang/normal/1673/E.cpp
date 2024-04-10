#include<bits/stdc++.h>
using namespace std;
#define N 1233333
typedef long long ll;
int n,k,ans[N],g[26][N],a[N];
inline int C(int n,int m){
	return (n&m)==m;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=0;i<=min(n,25);++i){
		for(int j=n;j>=0;--j){
			g[i][j]=g[i][j+1]^C(n-i,j);
		}
	}
	for(int l=1;l<=n;++l){
		int now=1;
		for(int r=l;r<=n;++r){
			if(l==r)now=a[l];
			else{
				if(a[r]>20||1LL*now*(1<<a[r])>(1<<20))break;
				now*=1<<a[r];
			}
			int _n=max(0,l-2)+max(0,n-r-1);
			int _k=max(0,k-(l>1)-(r<n));
			ans[now]^=g[n-_n][_k];
		}
	}
	int zz=(1<<20)-1;
	while(zz&&!ans[zz])--zz;
	for(int i=zz;i>=0;--i){
		cout<<ans[i];
	}
	cout<<'\n';
	return 0;
}