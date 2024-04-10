#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;
ll a[N],b[N];
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	if(n%2==1){
		cout << "NO\n";
		return;
	}
	sort(a+1,a+n+1);
	for(int i=2; i<=n/2 ;i++){
		if(a[i]==a[i+n/2-1]){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	for(int i=2; i<=n/2 ;i+=2){
		b[i]=i;
	}
	int king=1,pos=n;
	while(king<=n/2){
		b[pos]=king;
		pos-=2;king+=2;
	}
	king=n/2+1;pos=1;
	while(king<=n){
		b[pos]=king;
		pos+=2;king+=2;
	}
	king=n/2+2; pos=n-1;
	while(king<=n){
		b[pos]=king;
		pos-=2;king+=2;
	}
	for(int i=1; i<=n ;i++){
		cout << a[b[i]] << ' ';
	}
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}