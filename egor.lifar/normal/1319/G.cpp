#include <bits/stdc++.h>


using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define rank rank228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;
// const int MAXMEM = 200 * 1000 * 1024;
// char _memory[MAXMEM];
// size_t _ptr = 0;
// void* operator new(size_t _x) { _ptr += _x; return _memory + _ptr - _x; }
// void operator delete (void*) noexcept {}
const string FILENAME = "input";
const int MAXN = 200228;
const int Mod = 1000000009;
const int P = 1000003;
const int Mod1 = 1000000007;
const int P1 = 424243;


int n;
string t;
int f[MAXN];
int nxtz[MAXN];
int nxto[MAXN];
ll p[MAXN];
ll p1[MAXN];
vector<int> fg;
vector<int> start;
vector<pair<int, int> > st;
int ft[MAXN];


int get(int l, int r, int l1, int r1) {
	return min(r, r1) - max(l, l1) + 1;
}


ll hs[MAXN];
ll hs1[MAXN];


int gethashik(int l, int r) {
	return ((hs[r] - (l ? (ll)hs[l - 1] * p[r - l + 1] % Mod: 0)) % Mod + Mod) % Mod;
}

int gethashik1(int l, int r) {
	return ((hs1[r] - (l ? (ll)hs1[l - 1] * p1[r - l + 1] % Mod1: 0)) % Mod1 + Mod1) % Mod1;
}


int gethash(int l, int r) {
	int ls = upper_bound(all(start), l) - start.begin() - 1;
	int rs = upper_bound(all(start), r) - start.begin() - 1;
	if (ls == rs) {
		if (t[l] == '1') {
			return (r - l + 1) % 2 == 0 ? 0: 1;
		}
		return 0;
	}
	int llen = get(l, r, start[ls], start[ls] + st[ls].second - 1);
	int rlen = get(l, r, start[rs], start[rs] + st[rs].second - 1);
	int sl = lower_bound(all(fg), ls + 1) - fg.begin();
	int sr = lower_bound(all(fg), rs) - fg.begin() - 1;
	vector<pair<int, int> > s;
	int last = l - 1;
	if (t[l] == '1' && llen % 2 == 1) {
		s.pb({1, 1});
		last = l + llen - 1;
	}
	if (sl >= 0 && sl < sz(fg) && sr >= 0 && sr < sz(fg) && ls < fg[sl] && sl <= sr && fg[sr] < rs) {
	//	cout << ft[fg[sl]] - (l ? ft[l - 1]: 0) << endl;
		//cout << fg[sl] << endl;
		s.pb({ft[start[fg[sl]]] - (l ? ft[l - 1]: 0) + 1, 1});
		if (sl < sr) {
			s.pb({gethashik(sl + 1, sr), sr - sl});
		}
		last = start[fg[sr]] + st[fg[sr]].second - 1;
	}
	if (t[r] == '1' && rlen % 2 == 1) {
		//cout << ft[r] - (last >= 0 ? ft[last]: 0) << endl;
		s.pb({ft[r] - (last >= 0 ? ft[last]: 0) + 1, 1});
	}
	ll cur = 0;
	for (auto x: s) {
		cur = (cur * p[x.second] + x.first) % Mod;
	}
	return cur;
}

int gethash1(int l, int r) {
	int ls = upper_bound(all(start), l) - start.begin() - 1;
	int rs = upper_bound(all(start), r) - start.begin() - 1;
	if (ls == rs) {
		if (t[l] == '1') {
			return (r - l + 1) % 2 == 0 ? 0: 1;
		}
		return 0;
	}
	int llen = get(l, r, start[ls], start[ls] + st[ls].second - 1);
	int rlen = get(l, r, start[rs], start[rs] + st[rs].second - 1);
	int sl = lower_bound(all(fg), ls + 1) - fg.begin();
	int sr = lower_bound(all(fg), rs) - fg.begin() - 1;
	vector<pair<ll, int> > s;
	int last = l - 1;
	if (t[l] == '1' && llen % 2 == 1) {
		s.pb({1, 1});
		last = l + llen - 1;
	}
	if (sl >= 0 && sl < sz(fg) && sr >= 0 && sr < sz(fg) && ls < fg[sl] && sl <= sr && fg[sr] < rs) {
	//	cout << ft[fg[sl]] - (l ? ft[l - 1]: 0) << endl;
		//cout << fg[sl] << endl;
		s.pb({ft[start[fg[sl]]] - (l ? ft[l - 1]: 0) + 1, 1});
		if (sl < sr) {
			s.pb({gethashik1(sl + 1, sr), sr - sl});
		}
		last = start[fg[sr]] + st[fg[sr]].second - 1;
	}
	if (t[r] == '1' && rlen % 2 == 1) {
		//cout << ft[r] - (last >= 0 ? ft[last]: 0) << endl;
		s.pb({ft[r] - (last >= 0 ? ft[last]: 0) + 1, 1});
	}
	ll cur = 0;
	for (auto x: s) {
		cur = (cur * p1[x.second] + x.first) % Mod1;
	}
	return cur;
}


string getstring(int l, int r) {
	string ts;
	for (int i = l; i <= r; i++) {
		ts += t[i];
	}
	while (true) {
		bool was = false;
		for (int j = 0; j <= sz(ts) - 3; j++) {
			if (ts[j] == '0' && ts[j + 1] == '1' && ts[j + 2] == '1') {
				ts[j] = '1';
				ts[j + 2] = '0';
				was = true;
			}
		}
		if (!was) {
			break;
		}
	}
	return ts;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	read(FILENAME);
	cin >> n >> t;
	p[0] = 1;
	for (int i = 1; i <= n; i++) {
		p[i] = ((ll)p[i - 1] * P) % Mod;
	}
	p1[0] = 1;
	for (int i = 1; i <= n; i++) {
		p1[i] = ((ll)p1[i - 1] * P1) % Mod1;
	}
	for (int i = 0; i < n; i++) {
		int c = t[i] - '0';
		f[i] = c;
		ft[i] =1  - c;
		if (i) {
			f[i] += f[i - 1];
			ft[i] += ft[i - 1];
		}
		if (st.empty() || st.back().first != c) {
			st.pb({c, 1});
		} else {
			st.back().second++;
		}
	}
	int cur = 0;
	for (int i = 0; i < sz(st); i++) {
		start.pb(cur);
		if (st[i].first == 1 && st[i].second % 2 == 1) {
			fg.pb(i);
		}
		cur += st[i].second;	
	}
	for (int i = 0; i < sz(fg); i++) {
		int kek = ft[start[fg[i]]] - (i ? ft[start[fg[i - 1]] + st[fg[i - 1]].second - 1]: 0) + 1;
		hs[i] = (i ? hs[i - 1] * P + kek: kek) % Mod; 
	}
	for (int i = 0; i < sz(fg); i++) {
		int kek = ft[start[fg[i]]] - (i ? ft[start[fg[i - 1]] + st[fg[i - 1]].second - 1]: 0) + 1;
		hs1[i] = (i ? hs1[i - 1] * P1 + kek: kek) % Mod1; 
	}
	//cout << t << endl;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l1, l2, len;
		cin >> l1 >> l2 >> len;
		l1--, l2--;
		if (f[l1 + len - 1] - (l1 ? f[l1 - 1]: 0) != f[l2 + len - 1] - (l2 ? f[l2 - 1]: 0)) {
		 	cout << "No\n";
	 		continue;
		}
		bool ok = gethash(l1, l1 + len - 1) != gethash(l2, l2 +  len - 1) || gethash1(l1, l1 + len - 1) != gethash1(l2, l2 +  len - 1);
		if (ok) {
			cout << "No\n";
		} else {
			cout << "Yes\n";
		}
	}
}