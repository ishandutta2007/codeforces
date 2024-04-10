#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const int SIZE = 200005;

int main() {
	ll n;
	cin >> n;
	ll k = 1, maior = 0;
	while(true) {
		ll beaut = ((1ll << k) - 1) * (1ll << (k-1));
		if(beaut > n) {
			cout << maior << endl;
			break;
		}
		if(n % beaut == 0) {
			maior = beaut;
		}
		k++;
	}
	return 0;
}