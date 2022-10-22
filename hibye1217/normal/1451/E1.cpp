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

int arr[65540];

void Main(){
	int n;
	cin >> n;
	int axb, anb, aob;
	int bxc, bnc, boc;
	int cxa, cna, coa;
	cout << "AND 1 2" << endl; cout.flush();
	cin >> anb;
	cout << "AND 2 3" << endl; cout.flush();
	cin >> bnc;
	cout << "AND 3 1" << endl; cout.flush();
	cin >> cna;
	cout << "OR 1 2" << endl; cout.flush();
	cin >> aob;
	cout << "OR 2 3" << endl; cout.flush();
	cin >> boc;
	axb = anb ^ aob;
	bxc = bnc ^ boc;
	cxa = axb ^ bxc;
	coa = cna ^ cxa;
	int a=0, b=0, c=0;
	for (int i = 0; i < 20; i++){
		bool abx = axb & 1<<i, bcx = bxc & 1<<i, cax = cxa & 1<<i;
		bool abo = aob & 1<<i, bco = boc & 1<<i, cao = coa & 1<<i;
		bool abn = anb & 1<<i, bcn = bnc & 1<<i, can = cna & 1<<i;
		if (!abo && !bco && !cao){}
		else if (abn && bcn && can){ a ^= 1<<i; b ^= 1<<i; c ^= 1<<i; }
		else if (abo && cao && !bco){ a ^= 1<<i; }
		else if (abo && bco && !cao){ b ^= 1<<i; }
		else if (cao && bco && !abo){ c ^= 1<<i; }
		else if (abn){ a ^= 1<<i; b ^= 1<<i; }
		else if (bcn){ b ^= 1<<i; c ^= 1<<i; }
		else if (can){ c ^= 1<<i; a ^= 1<<i; }
	}
	arr[1] = a; arr[2] = b; arr[3] = c;
	for (int i = 4; i <= n; i++){
		cout << "XOR 1 " << i << endl; cout.flush();
		int res;
		cin >> res;
		arr[i] = arr[1] ^ res;
	}
	cout << "! ";
	for (int i = 1; i <= n; i++){
		cout << arr[i] << ' ';
	}
	cout << endl; cout.flush();
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(15);
	Main();
}