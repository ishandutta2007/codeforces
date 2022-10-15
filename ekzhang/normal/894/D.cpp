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

#define INF 10000013
#define MAXN 1000013
int N, M;
LL L[MAXN];
vector<LL> cdists[MAXN];
vector<LL> pref[MAXN];

void dfs(int n, int a, LL d) {
	if (n > N) return;
	d += L[n];
	if (d >= INF) return;
	cdists[a].push_back(d);
	dfs(2 * n, a, d);
	dfs(2 * n + 1, a, d);
}

LL go(int v, LL h) {
	// only check the subtree of v
	if (v > N || h < 0) return 0;
	// LL ret = h;
	// if (2 * v <= N) ret += go(2 * v, h - L[2 * v]);
	// if (2 * v  + 1<= N) ret += go(2 * v + 1, h - L[2 * v + 1]);
	// return ret;
	auto it = lower_bound(cdists[v].begin(), cdists[v].end(), h);
	int i = it - cdists[v].begin();
	return h * i - pref[v][i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 2; i <= N; i++)
		cin >> L[i];

	for (int i = 1; i <= N; i++) {
		dfs(i, i, -L[i]);
		cdists[i].push_back(INF);
		sort(cdists[i].begin(), cdists[i].end());
		LL t = 0;
		pref[i].push_back(0);
		for (int j = 0; j < cdists[i].size(); j++) {
			t += cdists[i][j];
			pref[i].push_back(t);
		}
	}

	while (M--) {
		int A;
		LL H;
		cin >> A >> H;
		LL ans = go(A, H);
		while (A != 1) {
			int u = A >> 1;
			H -= L[A];
			if (H <= 0) break;
			ans += H;
			int v = A ^ 1;
			if (v <= N) {
				LL h = H - L[v];
				if (h > 0)
					ans += go(v, h);
			}
			A = u;
		}
		cout << ans << '\n';
	}

	cout.flush();
	return 0;
}