#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(NULL)
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define INF 1e18
#define inf 1e9
#define pb push_back
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a);
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n, m;
vector<pii> ans;
int a[100][100];
int b[100][100];

int main() {
	fast;

	cin >> n >> m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> a[i][j];
		}
	}

	for(int i=0; i+1<n; i++) {
		for(int j=0; j+1< m; j++) {
			if(a[i][j] + a[i+1][j] + a[i][j+1] + a[i+1][j+1] == 4) {
				ans.eb(i+1, j+1);
				b[i][j] = 1;
				b[i+1][j] = 1;
				b[i][j+1] = 1;
				b[i+1][j+1] = 1;
			}
		}
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(a[i][j] != b[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << ans.size() << "\n";
	for(auto i : ans) {
		cout << i.first << " " << i.second << "\n";
	}
}