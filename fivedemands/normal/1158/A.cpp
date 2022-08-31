#include<iostream>
using namespace std;
typedef long long ll;
const int N=1e5+1,M=1e5+1;
int n,m;
int b[N],g[M];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int mab=0,mig=1e9;
	int ma2=0;
	ll ans=0;
	for(int i=1; i<=n ;i++){
		cin >> b[i];ma2=max(ma2,b[i]);
		if(ma2>mab) swap(mab,ma2);
		ans+=1LL*b[i]*m;
	}
	for(int i=1; i<=m ;i++){
		cin >> g[i];mig=min(mig,g[i]);
		ans+=g[i]-mab;
	}
	if(mig<mab){
		cout << "-1\n";
		return 0;
	}
	if(mab!=mig) ans+=mab-ma2;
	cout << ans << endl;
}