#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int arr[200020];

bool cmp(int a, int b){
	return a > b;
}

void Main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> arr[i];
		}
		sort(arr+1, arr+n+1, cmp);
		ll ali=0, bob=0;
		for (int i = 1; i <= n; i++){
			if (i & 1){
				if (arr[i] & 1){  }
				else{ ali += arr[i];}
			}
			else{
				if (arr[i] & 1){ bob += arr[i]; }
				else{  }
			}
		}
		if (ali > bob){ cout << "Alice" << endl; }
		else if (ali < bob){ cout << "Bob" << endl; }
		else{ cout << "Tie" << endl; }
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}