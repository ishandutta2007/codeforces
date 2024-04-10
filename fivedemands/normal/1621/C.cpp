#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
ll n,m;
int p[N];
int use=0;
int ask(int x){
	cout << "? " << x << endl;
	int y;cin >> y;
	use++;
	return y;
}
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++) p[i]=0;
	for(int i=1; i<=n ;i++){
		if(p[i]==0){
			int x=ask(i);
			while(x!=i) x=ask(i);
			vector<int>v;
			p[i]=ask(i);
			int y=p[i];
			while(y!=i){
				p[y]=ask(i);
				y=p[y];
			}
		}
	}
	cout << "! ";
	for(int i=1; i<=n ;i++){
		cout << p[i] << ' ';
	}
	cout << endl;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;
	while(t--) solve();
}