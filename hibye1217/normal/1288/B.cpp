#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll mod = 1000000007;

int main(){
	Fast;
	int t;
	cin >> t;
	while (t--){
		ll a, b;
		cin >> a >> b;
		ll nine = 9, cnt=0;
		for (nine = 9; nine <= b; nine = (nine*10)+9){
			cnt++;
		}
		cout << a*cnt << endl;
	}
}