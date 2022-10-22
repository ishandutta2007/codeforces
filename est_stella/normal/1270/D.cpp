#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)
  
typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll;  
const long long INF = 1e18;  
const int inf = 1e9;

int n, k;
int cnt[555];
int num[555];

int main() {
	cin >> n >> k;

	for(int i=1; i<=k+1; i++) {
		cout << "? ";
		for(int j=1; j<=k+1; j++) {
			if(i == j) continue;
			cout << j << " ";
		}
		cout << endl;

		int x, y;
		cin >> x;
		if(x == -1) return 0;
		cin >> y;

		cnt[x]++;
		num[x] = y;
	}

	vector<int> v;

	for(int i=1; i<=n; i++) {
		if(cnt[i]) v.pb(i); 
	}

	cout << "! ";
	if(v.size() < 2) {
		cout << 1 << endl;
	}
	else if(num[v[0]] < num[v[1]]) {
		cout << cnt[v[1]] << endl;
	}
	else cout << cnt[v[0]] << endl; 
}