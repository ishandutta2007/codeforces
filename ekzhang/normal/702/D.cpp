#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
#define MAX (1LL<<62)
LL D, K, A, B, T;

LL tim(LL amtCar) {
	if (amtCar > (D + K - 1) / K) {
		return MAX;
	}
	if (amtCar == (D + K - 1) / K) {
		LL ret = 0;
		ret += A * D;
		ret += (amtCar - 1) * T;
		return ret;
	}
	return (A * amtCar * K) + (amtCar ? (amtCar - 1) * T : 0) + (D - amtCar * K) * B;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> D >> K >> A >> B >> T;
	LL lo = 0;
	LL hi = (D + K - 1) / K;

	LL ans = tim(lo);
	ans = min(ans, tim(hi));
	ans = min(ans, tim(1));
	ans = min(ans, tim(hi - 1));

	cout << ans << endl;
	return 0;
}