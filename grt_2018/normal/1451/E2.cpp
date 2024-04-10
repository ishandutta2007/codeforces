#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

int ask(int a, int b, bool typ = 1) {
	if(typ) cout << "XOR " << a << " " << b << endl;
	else cout << "OR " << a << " " << b << endl;
	int w;
	cin >> w;
	return w;
}

const int nax = (1 << 16) + 10;
int n;
int ans[nax];
int res[nax];
map<int, int>m;

int main() {
	cin >> n;
	res[1] = -1;
	int A = -1, B = -1, C = -1, D = -1;
	for(int i = 2; i <= n; ++i) {
		ans[i] = ask(1, i);
		if(ans[i] == 1) C = i;
		if(ans[i] == 3) D = i;
		if(ans[i] == 0 && res[1] == -1) {
			int w = ask(1, i, 0);
			res[1] = w;
		}
		if(res[1] == -1 && m.find(ans[i]) != m.end()) {
			A = i;
			B = m[ans[i]];
			int w = ask(A, B, 0);
			res[A] = w;
			res[1] = ans[A] ^ res[A];
		}
		m[ans[i]] = i;
	}
	if(res[1] != -1) {
		for(int i = 2; i <= n; ++i) res[i] = res[1] ^ ans[i];
	} else {
		int cur = ask(1, C, 0);
		cur -= 1;
		cout << "AND " << C << " " << D << endl;
		int w;
		cin >> w;
		if(w & 1) {
			cur += 0;
		} else {
			cur++;
		}
		res[1] = cur;
		for(int i = 2; i <= n; ++i) {
			res[i] = res[1] ^ ans[i];
		}
	}
	cout << "! ";
	for(int i = 1; i <= n; ++i) {
		cout << res[i] << " ";
	}
	cout << endl;		
	
}