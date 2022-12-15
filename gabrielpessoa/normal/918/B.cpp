#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;
typedef pair<ll, ll> llll;

const int SIZE  = 1005;
const int MOD = 1E6;
const int DELTA = 1E5+2;
const double PI = atan(1)*4;
const double EPS = 8e-5;
const int INF = 0x3f3f3f3f;

map<string, string> dic;

int main() {
	int n, m;
	cin >> n >> m;
	string name, ip;
	while(n--) {
		cin >> name >> ip;
		ip.push_back(';');
		dic[ip] = name;
	}
	while(m--) {
		cin >> name >> ip;
		cout << name << " " << ip << " #" << dic[ip] << '\n';
	}

	return 0;
}