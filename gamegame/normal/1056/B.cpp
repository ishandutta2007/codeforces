#include<iostream>
using namespace std;
typedef long long ll;
ll n,m;
ll f[1001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=0; i<m ;i++){
		if(n<i) continue;
		f[i*i%m]+=(n-i)/m+1;
	}
	f[0]--;
	ll ans=0;
	for(int i=0; i<m ;i++){
		ans+=f[i]*f[(m-i)%m];
	}
	
	cout << ans << endl;
}