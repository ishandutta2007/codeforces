#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;

typedef double dd;
dd x[N];
dd px[N],sx[N];
void solve(){
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		cin >> x[i];
	}
	x[n+1]=m;
	n++;
	for(int i=0; i<=n+1 ;i++) px[i]=sx[i]=0;
	for(int i=1; i<=n ;i++){
		px[i]=px[i-1]+(dd)(x[i]-x[i-1])/(i);
	}
	for(int i=n-1; i>=0 ;i--){
		sx[i]=sx[i+1]+(dd)(x[i+1]-x[i])/(n-i);
	}
	for(int i=1; i<=n ;i++){
		if(px[i]>=sx[i]){
			dd fuck=x[i]/(n-i+1)+x[i-1]/i-((px[i-1]-sx[i])); 
			fuck=fuck/((dd)1/i+(dd)1/(n-i+1));
			printf("%.10lf\n",px[i-1]+(fuck-x[i-1])/i);
			return;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
	//solve();
}