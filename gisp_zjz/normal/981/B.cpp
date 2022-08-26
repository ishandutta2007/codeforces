#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll ans,n,m,k,p;
map <ll,ll> f;

int main(){
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> k >> p;
		f[k]=p; ans+=p;
	}
	cin >> m;
	for (int i=0;i<m;i++){
		cin >> k >> p;
		if (f.find(k)==f.end()) ans+=p;
		else ans+=max(p,f[k])-f[k];
	}
	cout << ans << endl;
	return 0;
}