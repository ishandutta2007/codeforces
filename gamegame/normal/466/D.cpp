#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
int n;
int a[2002];

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> a[0];
	a[n+1]=a[0];
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	n++;
	for(int i=n; i>=1 ;i--) a[i]-=a[i-1];
	int duh=0;
	ll ans=1;
	for(int i=1; i<=n ;i++){
		if(abs(a[i])>1){
			return cout << 0 << '\n',0;
		}
		a[i]*=-1;
		if(a[i]==1) duh++;
		else if(a[i]==0){
			ans=(ans*(duh+1))%mod;
		}
		else{
			ans=ans*duh%mod;
			duh--;
		}
	}
	cout << ans << endl;
}