#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
ll n;
int p[100001];
pair<int,int>a[100001],b[100001];
int c[100001];

void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i].fi;
		a[i].se=i;
		p[i]=false;
	}
	for(int i=1; i<=n ;i++){
		cin >> b[i].fi;
		b[i].se=i;
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for(int i=1; i<=n ;i++){
		c[b[i].se]=i;
	}
	int mn=n+1;
	for(int i=n; i>=1 ;i--){
		mn=min(mn,c[a[i].se]);
		p[a[i].se]=1;
		if(mn==i){
			for(int j=1; j<=n ;j++) cout << p[j];
			cout << '\n';
			return;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;
	while(t--){
		solve();
	}
}