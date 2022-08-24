#include<iostream>
using namespace std;
typedef long long ll;
int n;
ll l[100001];
ll hv[11];
ll ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> l[i];
		ans+=l[i]*2;
	}
	bool hvw=false;
	ll pw=0;
	char c=0;
	for(int i=1; i<=n ;i++){
		cin >> c;
		if(c=='G') hv[10]=1e18;
		if(c=='G') hv[4]+=l[i]*2;
		if(c=='W') hv[6]=1e18;
		if(c=='W') hv[2]+=l[i]*2;
		pw-=l[i];
		for(int j=2; j<=10 ;j++){
			ll cur=min(-pw,hv[j]);
			hv[j]-=cur;
			pw+=cur;
			ans+=cur*j;
			if(pw>=0) break;
		}
	}
	cout << ans/2 << endl;
}