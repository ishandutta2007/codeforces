#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef pair<ld, ld> pld;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int arr[100020];
int nxt[100020], p[100020];
int ptr[100020];

void Main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	for (int i = 0; i <= n; i++){ p[i] = ptr[i] = 1e9; }
	for (int i = n; i >= 1; i--){
		nxt[i] = p[ arr[i] ];
		ptr[ arr[i] ] = p[ arr[i] ] = i;
	}
	//for (int i = 1; i <= n; i++){ cout << nxt[i] << ' '; } cout << endl;
	int lst1 = 0, lst2 = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++){
		int n1 = ptr[lst1], n2 = ptr[lst2];
		if (lst1 == arr[i]){ n1 = 2e9; }
		if (lst2 == arr[i]){ n2 = 2e9; }
		//cout << lst1 << ' ' << lst2 << ' ' << ptr[lst1] << ' ' << ptr[lst2] << endl;
		if (n1 < n2){
			if (lst1 != arr[i]){ ans += 1; }
			lst1 = arr[i];
		}
		else{
			if (lst2 != arr[i]){ ans += 1; }
			lst2 = arr[i];
		}
		ptr[ arr[i] ] = nxt[i];
	}
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(15);
	Main();
}