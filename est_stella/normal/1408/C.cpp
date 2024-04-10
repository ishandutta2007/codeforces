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
#define pre(a) cout<<fixed; cout.precision(a);
  
typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll; 
typedef long double ld;
const long long INF = 1e18;  
const int inf = 1e9;

int n, l;
ld a[100010];
ld A[100010];
ld B[100010];

void solve() {
	cin >> n >> l;

	a[n+1] = l;
	for(int i=1; i<=n; i++) cin >> a[i];

	ld speed = 1;
	for(int i=1; i<=n+1; i++) {
		A[i] = A[i-1] + (a[i] - a[i-1]) / speed;
		speed++;
	}

	B[n+1] = 0;

	speed = 1;
	for(int i=n; i>=0; i--) {
		B[i] = B[i+1] + (a[i+1] - a[i]) / speed;
		speed++;
	}

	int idx[2] = {0, n+1};

	while(idx[0] + 1 < idx[1]) {
		if(A[idx[0]+1] < B[idx[1] - 1]) idx[0]++;
		else idx[1]--;
	}

	int x = idx[0];
	
	cout << (a[x+1] - a[x] + (x + 1) * A[x] + (n - x + 1) * B[x+1]) / (n+2) << "\n";
} 

int main() {
	fast;
	pre(15);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}