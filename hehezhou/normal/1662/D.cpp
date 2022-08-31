#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

bool u, v;
vector<int> X, Y;
string A, B;
void gen(vector<int>& r, bool& s, string t)
{
	r.clear(); s = 0;
	rep(i, t.size()) if(t[i] == 'B') s ^= 1;
	else {
		r.push_back(t[i]);
		while((int)r.size() >= 2 && r.back() == r[(int)r.size() - 2]) {
			r.pop_back(); r.pop_back();
		}
	}
}
void solve()
{
	cin >> A >> B;
	gen(X, u, A); gen(Y, v, B);
	if(u == v && X == Y) printf("YES\n");
	else printf("NO\n");
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T --) solve();
	return 0;
}