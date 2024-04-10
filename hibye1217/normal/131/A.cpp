#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 9
using namespace std;
#define all(v) v.begin(),v.end()
using ll = long long;
#define fr first
#define sc second
using pi2 = pair<int, int>;

int arr[100020];

void Main(){
	string s; cin >> s; int sl = s.size();
	bool chk = 1;
	for (int i = 1; i < sl; i++){ chk &= !!(~s[i] & 32); }
	if (chk){ for (int i = 0; i < sl; i++){ s[i] ^= 32; } }
	cout << s;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}