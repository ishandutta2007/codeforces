#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define endl '\n'
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int ca[30], cb[30];

void Main(){
	int t;
	cin >> t;
	while (t--){
		int n, k;
		string a, b;
		cin >> n >> k >> a >> b;
		for (int i = 0; i < n; i++){
			ca[ a[i]-'a' ] += 1;
		}
		for (int i = 0; i < n; i++){
			cb[ b[i]-'a' ] += 1;
		}
		bool chk = true;
		for (int i = 0; i <= 25; i++){
			if (ca[i] < cb[i]){
				chk = false;
				//cout << "a";
			}
			if (i != 25 && (ca[i] - cb[i]) % k != 0){
				chk = false;
				//cout << "b";
			}
			if (i == 25 && ca[i] != cb[i]){
				chk = false;
				//cout << "c";
			}
			//cout << i << ' ' << ca[i] << ' ' << cb[i] << endl;
			ca[i+1] += ca[i] - cb[i];
			ca[i] = cb[i];
		}
		cout << (chk ? "Yes" : "No") << endl;
		for (int i = 0; i <= 25; i++) ca[i] = cb[i] = 0;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(15);
	Main();
}