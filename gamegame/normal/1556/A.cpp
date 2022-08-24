#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const ll mod=1e9+7;
ll n,m;
ll a[N],b[N];
void solve(){
	ll c,d;cin >> c >> d;
	if((c+d)%2!=0 || c+d<0){
		cout << "-1\n";
	}
	else if(c==0 && d==0){
		cout << "0\n";
	}
	else if(c+d!=0 && c!=d){
		cout << "2\n";
	}
	else{
		cout << "1\n";
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}