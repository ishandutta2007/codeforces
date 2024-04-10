#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+1;
ll n;
ll a[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	if(n==1){
		cout << "1 1\n";
		cout << -a[1] << '\n';a[1]=0;
		cout << "1 1\n";
		cout << -a[1] << '\n';cout << "1 1\n";
		cout << -a[1] << '\n';
		return 0;
	}
	cout << "1 " << n << '\n';
	for(int i=1; i<=n ;i++){
		ll x=a[i]%(n-1);
		if(x<0) x+=n-1;
		cout << -x*n << ' ';
		a[i]-=x*n;
	}
	cout << '\n';
	cout << "1 " << n-1 << '\n';
	for(int i=1; i<n ;i++){
		if(a[i]%(n-1)!=0) while(true);
		cout << -a[i] << ' ';
	}
	cout << '\n';
	cout << n << ' ' << n << '\n';
	cout << -a[n] << '\n';
}