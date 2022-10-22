#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define eb emplace_back
#define em emplace
#define mp make_pair
  
typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll;  
const long long INF = 1e18;  
const int inf = 1e9;

int n;
int a[111];
int b[111];
int c[111];
int p[111];

void solve() {
	cin >> n;

	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n; i++) cin >> b[i];
	for(int i=0; i<n; i++) cin >> c[i];

	for(int i=0; i<n-1; i++) {
		if(i && a[i] == p[i-1]) p[i] = b[i];
		else p[i] = a[i];
	}

	if(p[n-2] != a[n-1] && p[0] != a[n-1]) p[n-1] = a[n-1];
	else if(p[n-2] != b[n-1] && p[0] != b[n-1]) p[n-1] = b[n-1];
	else p[n-1] = c[n-1];

	for(int i=0; i<n; i++) cout << p[i] << " ";
	cout << "\n";
} 

int main() {
	fast;

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}