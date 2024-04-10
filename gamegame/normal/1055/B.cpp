#include<iostream>
using namespace std;
typedef long long ll;
int n,m;
ll a[100002];
ll l;
int ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> l;
	l++;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		if(a[i]>=l && a[i-1]<l) ans++;
	}
	for(int i=1; i<=m ;i++){
		int qr;
		cin >> qr;
		if(qr==0){
			cout << ans << '\n';
			continue;
		}
		int p;
		ll d;
		cin >> p >> d;
		if(a[p]>=l) continue;
		a[p]+=d;
		if(a[p]<l) continue;
		if(a[p-1]>=l && a[p+1]>=l) ans--;
		else if(a[p-1]<l && a[p+1]<l) ans++;
	}
}