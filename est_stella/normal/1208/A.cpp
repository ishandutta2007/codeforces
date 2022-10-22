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

int t;

int main() {
	fast;

	cin >> t;
	while(t--) {
		int a, b, n;
		cin >> a >> b >> n;

		if(n%3==0) cout << a << "\n";
		else if(n%3==1) cout << b << "\n";
		else cout << (a^b) << "\n";
	}
}