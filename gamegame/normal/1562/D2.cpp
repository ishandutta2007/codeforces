#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
#define fi first
#define se second
const int N=600001;
const ll mod=998244353;
ll a[N];
int n,q;
const int iu=3e5;
vector<int>b[3][N];
//<edge>
//</groups>
int p[N];
void solve(){
	cin >> n >> q;
	for(int i=-n ;i<=n ;i++){
		b[0][i+iu].clear();
		b[2][i+iu].clear();
	}
	for(int i=1; i<=n ;i++){
		char c;cin >> c;
		int x=1;
		if(c=='-') x=-1;
		if(i%2) x*=-1;
		p[i]=p[i-1]+x;
		b[x+1][p[i]+iu].push_back(i);
	}
	for(int i=1; i<=q ;i++){
		int l,r;cin >> l >> r;
		vector<int>ans;
		if(p[r]==p[l-1]){
			cout << "0\n";
			continue;
		}
		else if(l%2!=r%2){
			ans.push_back(r);
			r--;
		}
		l--;
		if(p[l]<p[r]){
			int want=(p[r]+p[l]+1)/2;
			int duh=* lower_bound(b[2][want+iu].begin(),b[2][want+iu].end(),l+1);
			ans.push_back(duh);
		}
		else{
			int want=(p[r]+p[l]-1)/2;
			int duh=*lower_bound(b[0][want+iu].begin(),b[0][want+iu].end(),l+1);
			ans.push_back(duh);
		}
		cout << ans.size() << '\n';
		for(auto c:ans) cout << c << ' ';
		cout << '\n';
		ans.clear();
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}