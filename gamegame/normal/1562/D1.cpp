#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
#define fi first
#define se second
const int N=2000001;
const ll mod=998244353;
ll a[N],b[N];
int n,q;

//<edge>
//</groups>
int p[N];
void solve(){
	cin >> n >> q;
	for(int i=1; i<=n ;i++){
		char c;cin >> c;
		int x=1;
		if(c=='-') x=-1;
		if(i%2) x*=-1;
		p[i]=p[i-1]+x;
	}
	for(int i=1; i<=q ;i++){
		int l,r;cin >> l >> r;
		if(p[r]==p[l-1]) cout << "0\n";
		else if(l%2==r%2) cout << "1\n";
		else cout << "2\n";
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}