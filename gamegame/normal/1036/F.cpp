#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
const int m=1e5;
ll n;
vector<ll>v[63];
int maxi[11];
ll f[63],a[63];
void solve(){
	cin >> n;
	a[1]=n-1;
	ll l=0,r=1e9,mid;
	while(l!=r){
		mid=(l+r+1)/2;
		if(mid*mid<=n) l=mid;
		else r=mid-1;
	}
	a[2]=l-1;
	l=0,r=1e6;
	while(l!=r){
		mid=(l+r+1)/2;
		if(mid*mid*mid<=n) l=mid;
		else r=mid-1;
	}
	a[3]=l-1;
	for(int i=4; i<=62 ;i++) a[i]=upper_bound(v[i].begin(),v[i].end(),n)-v[i].begin()-2;
	ll ans=0;
	for(int i=1; i<=62 ;i++){
		ans+=f[i]*a[i];
	}
	//for(int i=1; i<=10 ;i++) cout << a[i] << ' ';
	//cout << endl;
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	v[0].resize(m+1);
	v[0][0]=0;
	for(int i=1; i<=m ;i++) v[0][i]=1;
	for(int i=1; i<=62 ;i++){
		v[i].resize(m+1);
		v[i][0]=0;
		for(int j=1; j<=m ;j++){
			if(v[i-1][j]>((ll)1e18)/j){
				v[i][j]=(ll)1e18+1;
			}
			else v[i][j]=v[i-1][j]*j;
		}
	}
	f[1]=1;
	for(int i=2; i<=62 ;i++){
		for(int j=1; j<i ;j++){
			if(i%j==0) f[i]-=f[j];
		}
	}
	int t;
	cin >> t;
	while(t--) solve();
}