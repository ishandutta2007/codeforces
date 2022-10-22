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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

inline bool div(string a, string b){
	int al = a.size(), bl = b.size();
	if (al % bl != 0) return false;
	for (int i = 0; i < al; i++){
		if (a[i] != b[ i%bl ]){ return false; }
	}
	return true;
}

void Main(){
	int t;
	cin >> t;
	while (t--){
		string a, b;
		cin >> a >> b;
		int al = a.size(), bl = b.size();
		if (al < bl){ swap(a, b); swap(al, bl); }
		string c = "";
		for (int i = 1; i <= 30; i++){
			c += a;
			bool res = div(c, b);
			if (res){
				cout << c << endl;
				goto nextTest;
			}
		}
		cout << "-1" << endl;
		nextTest: ;
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