#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m;
ll a[300001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++) cin >> a[i];
	cin >> m;
	ll sum=0;
	for(int i=1; i<=n ;i++) sum+=a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=m ;i++){
		ll q;cin >> q;
		cout << sum-a[n+1-q] << '\n';
	}
}