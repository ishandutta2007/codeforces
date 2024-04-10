#include <bits/stdc++.h>
using namespace std;

#define error(arg...){vector<string>_v =split(#arg,',');err(_v.begin(),arg);}
vector<string> split(const string& s,char c){vector<string> v;stringstream ss(s);
string x;while(getline(ss,x,c))v.push_back(move(x));return v;}
void err(vector<string>::iterator it){}template<typename T,typename...Args>
void err(vector<string>::iterator it,T a, Args... args){cerr<<it->
substr((*it)[0]==' ',it->length())<<" = "<<a<<'\n';err(++it, args...);}

typedef long long LL;
const double PI = 4 * atan(1);

#define MOD 1000000007
LL N, M;
int k;

LL mpow(LL n) {
	if (n == 0) return 1;
	LL ret = mpow(n / 2);
	ret = (ret * ret) % MOD;
	if (n & 1) ret = (ret * 2) % MOD;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> k;

	if ((N + M) % 2 == 1 && k == -1) {
		cout << 0 << endl;
		return 0;
	}

	// otherwise, find 2^(N-1 * M-1) mod MOD
	N--; M--;
	N %= MOD - 1;
	M %= MOD - 1;
	cout << mpow(N * M) << endl;
	return 0;
}