#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() )
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl
#define mkp(a,b) make_pair(a,b)
#define gcd(a,b) __gcd(a,b)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using cpl = complex<ld>;
const ld pi = 3.14159265358979323846264338327950288;
const ld tau = 2 * pi;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

// #define DEBUG

int cnt[10];
queue<int> man[20];
int ans[100020];

void f(int i0, int i1, int i2){
	while (!man[i0].empty()){
		int ptr = man[i0].front(); man[i0].pop();
		if (cnt[i1] == 0){
			if (cnt[i2] == 0){ cout << "NO"; exit(0); }
			cnt[i2] -= 1;
			ans[ptr] = i2;
		}
		else{
			cnt[i1] -= 1;
			ans[ptr] = i1;
		}
	}
}

void Main(){
	for (int i = 1; i <= 6; i++){ cin >> cnt[i]; }
	int n; cin >> n;
	for (int i = 1; i <= n; i++){
		string s; cin >> s;
		if (s == "S"){ man[1].push(i); }
		if (s == "M"){ man[2].push(i); }
		if (s == "L"){ man[3].push(i); }
		if (s == "XL"){ man[4].push(i); }
		if (s == "XXL"){ man[5].push(i); }
		if (s == "XXXL"){ man[6].push(i); }
		if (s == "S,M"){ man[7].push(i); }
		if (s == "M,L"){ man[8].push(i); }
		if (s == "L,XL"){ man[9].push(i); }
		if (s == "XL,XXL"){ man[10].push(i); }
		if (s == "XXL,XXXL"){ man[11].push(i); }
	}
	for (int i = 1; i <= 6; i++){
		while (!man[i].empty()){
			int ptr = man[i].front(); man[i].pop();
			if (cnt[i] == 0){ cout << "NO"; return; }
			ans[ptr] = i;
			cnt[i] -= 1;
		}
	}
	f(7, 1, 2); f(11, 6, 5);
	f(8, 2, 3); f(10, 5, 4);
	f(9, 3, 4);
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++){
		if (ans[i] == 1){ cout << "S"; }
		if (ans[i] == 2){ cout << "M"; }
		if (ans[i] == 3){ cout << "L"; }
		if (ans[i] == 4){ cout << "XL"; }
		if (ans[i] == 5){ cout << "XXL"; }
		if (ans[i] == 6){ cout << "XXXL"; }
		cout << endl;
	}
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}