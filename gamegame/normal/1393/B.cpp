#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
typedef pair<ll,ll> pll;
const int N=2e6+1;
int n;
int f[N];
int s1,s2;
void upd(int g,int v){
	s1+=(g/2)*v;
	s2+=(g/4)*v;
}
void solve(){
	cin >> n;
	s1=0,s2=0;
	for(int i=1; i<=n ;i++){
		int x;cin >> x;
		upd(f[x],-1);
		f[x]++;
		upd(f[x],1);
	}
	int q;cin >> q;
	for(int i=1; i<=q ;i++){
		char c;int x;
		cin >> c >> x;
		upd(f[x],-1);
		if(c=='-') f[x]--;
		else f[x]++;
		upd(f[x],1);
		if(s1>=4 && s2>=1) cout << "YES\n";
		else cout << "NO\n";
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	//int t;cin >> t;while(t--) 
	solve();
}