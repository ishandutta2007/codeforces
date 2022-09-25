#include<bits/stdc++.h>
using namespace std;
#define N 400020
typedef long long ll;
int n,a[N],f[N][20],lg[N],T;
inline int Query(int l,int r){
	int k=lg[r-l+1];
	return __gcd(f[l][k],f[r-(1<<k)+1][k]);
}
void Solve(){
	int ans=0;
	cin>>n;
	int p=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		f[i][0]=f[n+i][0]=a[n+i]=a[i];
		p=__gcd(p,a[i]);
	}
	for(int i=2;i<=n;++i){
		lg[i]=lg[i>>1]+1;
	}
	for(int j=1;j<=19;++j){
		for(int i=1;i+(1<<j)-1<=(n<<1);++i){
			f[i][j]=__gcd(f[i][j-1],f[i+(1<<j-1)][j-1]);	
		}
	}
	for(int i=1,j=1;i<=n;++i){
		while(i>j||Query(i,j)>p)++j;
		ans=max(ans,j-i);
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}