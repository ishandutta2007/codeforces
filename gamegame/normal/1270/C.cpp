#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mg=1e17;
int a[200001];
void solve(){
	int n;
	cin >> n;
	ll s=0,x=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		s+=a[i];
		x^=a[i];
	}
	ll p,q,r;
	if(s%2==1) p=mg-1;
	else p=mg;
	s+=p;
	x^=p;
	if(2*x-s<0) while(true);
	q=(2*x-s)/2;
	r=q;
	cout << 3 << '\n' << p << ' ' << q << ' ' << r << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();
}