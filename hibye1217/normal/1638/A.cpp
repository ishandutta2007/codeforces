#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

int arr[520];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		for (int i = 1; i <= n; i++){
			if (arr[i] == i){ continue; }
			int j = i;
			while (j <= n){
				if (arr[j] == i){ break; }
				else{ j += 1; }
			}
			int ip = i, jp = j;
			while (ip < jp){
				swap(arr[ip], arr[jp]);
				ip += 1; jp -= 1;
			}
			break;
		}
		for (int i = 1; i <= n; i++){ cout << arr[i] << ' '; }
		cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}