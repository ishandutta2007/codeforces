#include<iostream>
using namespace std;
typedef long long ll;
ll k;
int n;
string s,t;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k >> s >> t;
	ll dif=0;
	bool f=true;
	ll ans=0;
	for(int i=0; i<n ;i++){
		dif*=2;
		if(s[i]=='b') dif--;
		if(t[i]=='b') dif++;
		ans+=min(k,dif+1);
		if(dif>=1e18) dif=1e18;
	}
	cout << ans << endl;
}