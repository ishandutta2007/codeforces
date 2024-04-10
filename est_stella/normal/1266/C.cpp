#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(NULL)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define pre(a) cout<<fixed; cout.precision(a)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;

int r, c;
int R[555];
int C[555];

int main() {
	fast;

	cin >> r >> c;

	if(r == 1 && c == 1) {
		cout << 0;
		return 0;
	}
	if(r == 1) {
		for(int i=0; i<c; i++) {
			cout << i+2 << " ";
		}
		return 0;
	}
	if(c == 1) {
		for(int i=0; i<r; i++) {
			cout << i+2 << "\n";
		}
		return 0;
	}

	R[1] = 1;
	R[2] = 2;
	C[1] = 3;
	C[2] = 4;
	int cnt = 5;

	for(int i=3; i<=r; i++) {
		R[i] = cnt++;
	}

	for(int i=3; i<=c; i++) {
		C[i] = cnt++;
	}

	for(int i=1; i<=r; i++) {
		for(int j=1; j<=c; j++) {
			cout << R[i] * C[j] << " ";
		}
		cout << "\n";
	}
}