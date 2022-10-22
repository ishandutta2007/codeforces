#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(NULL)
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define pre(a) cout<<fixed;cout.precision(a)

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

int n;
int arr[1010][1010];
int t = 0;

int main() {
	fast;

	cin >> n;

	for(int i=0; i<n; i+=2) {
		for(int j=0; j<n; j+=2) {
			arr[i][j] = t;
			arr[i][j+1] = t+1;
			arr[i+1][j] = t+2;
			arr[i+1][j+1] = t+3;
			t+= 4;
		}
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}