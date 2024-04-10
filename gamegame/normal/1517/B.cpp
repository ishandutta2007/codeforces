#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
ll n,m;
ll a[101][101];
pair<ll,pair<int,int> >b[10001];
int ans[101][101];
void solve(){
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cin >> a[i][j];
			b[(i-1)*m+j]={a[i][j],{i,j}};
			ans[i][j]=j;
		}
	}
	sort(b+1,b+n*m+1);
	for(int j=1; j<=m ;j++){
		int cx=b[j].se.fi;
		int cy=b[j].se.se;
		//cout << cx << ' ' << cy << endl;
		//make sure ans[cx][j]=cy
		int k=1;
		for(int i=1; i<=m ;i++){
			if(ans[cx][i]==cy) k=i;
		}
		swap(ans[cx][k],ans[cx][j]);
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cout << a[i][ans[i][j]] << ' ';
		}
		cout << '\n';
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}