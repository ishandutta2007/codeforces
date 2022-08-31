#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;
vector<vector<char> >a;
int bad[N];
vector<int>ban;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	a.resize(n);
	for(int i=0; i<n ;i++){
		a[i].resize(m);
		for(int j=0; j<m ;j++){
			cin >> a[i][j];
			if(i>0 && j>0 && a[i-1][j]=='X' && a[i][j-1]=='X') bad[j-1]=true;
		}
	}
	for(int j=0; j<m ;j++) if(bad[j]) ban.push_back(j+1);
	ban.push_back(m);
	int q;cin >> q;
	for(int i=1; i<=q ;i++){
		int l,r;cin >> l >> r;
		int x=*lower_bound(ban.begin(),ban.end(),l);
		if(x>=r) cout << "YES\n";
		else cout << "NO\n";
	}
}