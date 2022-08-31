#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=4e6+1;
ll n,mod;
int a[N];
vector<int>ans;
void make(int pos){
	for(int i=1; i<=pos/2 ;i++){
		swap(a[i],a[pos+1-i]);
	}
	ans.push_back(pos);
}
void solve(){
	ans.clear();
	cin >> n;
	for(int i=1; i<=n ;i++) cin >> a[i];
	for(int j=n; j>1 ;j-=2){
		int pos=1;
		for(int i=1; i<=n ;i++) if(a[i]==j) pos=i;
		if(pos%2==0){
			cout << "-1\n";
			return;
		}
		make(pos);
		int pos2=1;
		for(int i=1; i<=n ;i++) if(a[i]==j-1) pos2=i;
		if(pos2%2==1){
			cout << "-1\n";
			return;
		}
		make(pos2-1);
		make(pos2+1);
		make(3);
		make(j);
	}
	cout << ans.size() << '\n';
	for(auto c:ans) cout << c << ' ';
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}