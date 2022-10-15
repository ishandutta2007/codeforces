#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 103
typedef long long LL;
int N;
LL K;
LL A[MAXN];
vector<LL> inter;

void calc_inter(LL x) {
	LL y = sqrt(x) + 1;
	for (LL k = 1; k <= y; k++) {
		inter.push_back(k);
		inter.push_back((x + k - 1) / k);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		K += A[i];
		calc_inter(A[i]);
	}

	inter.push_back(K + 1);

	sort(inter.begin(), inter.end());
	inter.resize(distance(inter.begin(), unique(inter.begin(), inter.end())));

	LL ans = 1;
	for (int i = 0; i < inter.size() - 1; i++) {
		LL d = inter[i];
		LL tot = 0;
		for (int i = 0; i < N; i++) {
			tot += (A[i] + d - 1) / d;
		}
		d = min(K / tot, inter[i + 1] - 1);
		if (d >= inter[i]) {
			ans = max(ans, d);
		}
	}

	cout << ans << endl;
	return 0;
}