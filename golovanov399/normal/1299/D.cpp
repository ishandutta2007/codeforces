#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int L = 5;
const int M = 1 << L;
using Bs = bitset<M>;

Bs add(Bs b, int x) {
	for (int i = 0; i < M; ++i) {
		if (b[i]) {
			b.set(i ^ x);
		}
	}
	return b;
}

// vector<Bs> subspaces;
// void rec(Bs b, Bs forb) {
// 	subspaces.push_back(b);
// 	for (int i = 0; i < M; ++i) {
// 		if (!b[i] && !forb[i]) {
// 			auto c = add(b, i);
// 			forb |= c;
// 			rec(c, forb);
// 		}
// 	}
// }

template <int mod>
struct Modular {
	int val;

	Modular(long long _val = 0) {
		if (_val < 0 || _val >= mod) {
			val = _val % mod;
			if (val < 0) {
				val += mod;
			}
		} else {
			val = _val;
		}
	}

	Modular operator +(const Modular& ot) const {
		int res = val + ot.val;
		if (res >= mod) {
			res -= mod;
		}
		return {res};
	}

	Modular operator -(const Modular& ot) const {
		int res = val - ot.val;
		if (res < 0) {
			res += mod;
		}
		return {res};
	}

	Modular operator *(const Modular& ot) const {
		return {1ll * val * ot.val};
	}

	Modular& operator ++() {
		val += 1;
		if (val == mod) {
			val = 0;
		}
		return *this;
	}

	Modular operator ++(int) {
		Modular tmp(*this);
		operator ++();
		return tmp;
	}

	void operator +=(const Modular& ot) {
		val += ot.val;
		if (val >= mod) {
			val -= mod;
		}
	}

	void operator -=(const Modular& ot) {
		val -= ot.val;
		if (val < 0) {
			val += mod;
		}
	}

	void operator *=(const Modular& ot) {
		val = 1ll * val * ot.val % mod;
	}

	bool operator ==(const Modular& ot) const {
		return val == ot.val;
	}

	bool operator !=(const Modular& ot) const {
		return val != ot.val;
	}
};

template <int mod>
ostream& operator <<(ostream& ostr, const Modular<mod>& x) {
	return ostr << x.val;
}

const vector<Bs> subspaces = {Bs(1ull), Bs(3ull), Bs(5ull), Bs(9ull), Bs(15ull), Bs(17ull), Bs(33ull), Bs(51ull), Bs(65ull), Bs(85ull), Bs(105ull), Bs(129ull), Bs(153ull), Bs(165ull), Bs(195ull), Bs(255ull), Bs(257ull), Bs(513ull), Bs(771ull), Bs(1025ull), Bs(1285ull), Bs(1545ull), Bs(2049ull), Bs(2313ull), Bs(2565ull), Bs(3075ull), Bs(3855ull), Bs(4097ull), Bs(4369ull), Bs(4641ull), Bs(5185ull), Bs(6273ull), Bs(8193ull), Bs(8481ull), Bs(8721ull), Bs(9345ull), Bs(10305ull), Bs(12291ull), Bs(13107ull), Bs(15555ull), Bs(16385ull), Bs(16705ull), Bs(17025ull), Bs(17425ull), Bs(18465ull), Bs(20485ull), Bs(21845ull), Bs(23205ull), Bs(24585ull), Bs(26265ull), Bs(26985ull), Bs(32769ull), Bs(33153ull), Bs(33345ull), Bs(33825ull), Bs(34833ull), Bs(36873ull), Bs(38505ull), Bs(39321ull), Bs(40965ull), Bs(42405ull), Bs(43605ull), Bs(49155ull), Bs(50115ull), Bs(52275ull), Bs(61455ull), Bs(65535ull), Bs(65537ull), Bs(131073ull), Bs(196611ull), Bs(262145ull), Bs(327685ull), Bs(393225ull), Bs(524289ull), Bs(589833ull), Bs(655365ull), Bs(786435ull), Bs(983055ull), Bs(1048577ull), Bs(1114129ull), Bs(1179681ull), Bs(1310785ull), Bs(1572993ull), Bs(2097153ull), Bs(2162721ull), Bs(2228241ull), Bs(2359425ull), Bs(2621505ull), Bs(3145731ull), Bs(3342387ull), Bs(3932355ull), Bs(4194305ull), Bs(4259905ull), Bs(4325505ull), Bs(4456465ull), Bs(4718625ull), Bs(5242885ull), Bs(5570645ull), Bs(5898405ull), Bs(6291465ull), Bs(6684825ull), Bs(6881385ull), Bs(8388609ull), Bs(8454273ull), Bs(8519745ull), Bs(8650785ull), Bs(8912913ull), Bs(9437193ull), Bs(9830505ull), Bs(10027161ull), Bs(10485765ull), Bs(10813605ull), Bs(11141205ull), Bs(12582915ull), Bs(12779715ull), Bs(13369395ull), Bs(15728655ull), Bs(16711935ull), Bs(16777217ull), Bs(16843009ull), Bs(16908801ull), Bs(17040385ull), Bs(17303553ull), Bs(17829889ull), Bs(18882561ull), Bs(20987905ull), Bs(25198593ull), Bs(33554433ull), Bs(33620481ull), Bs(33685761ull), Bs(33818625ull), Bs(34079745ull), Bs(34611201ull), Bs(35655681ull), Bs(37781505ull), Bs(41959425ull), Bs(50331651ull), Bs(50529027ull), Bs(51121155ull), Bs(53489667ull), Bs(62963715ull), Bs(67108865ull), Bs(67175425ull), Bs(67241985ull), Bs(67371265ull), Bs(67633665ull), Bs(68173825ull), Bs(69238785ull), Bs(71307265ull), Bs(75505665ull), Bs(83886085ull), Bs(84215045ull), Bs(84544005ull), Bs(89149445ull), Bs(94412805ull), Bs(100663305ull), Bs(101058825ull), Bs(101254665ull), Bs(106991625ull), Bs(110125065ull), Bs(134217729ull), Bs(134285313ull), Bs(134349825ull), Bs(134480385ull), Bs(134742273ull), Bs(135299073ull), Bs(136331265ull), Bs(138420225ull), Bs(142610433ull), Bs(150994953ull), Bs(151389705ull), Bs(151587081ull), Bs(157310985ull), Bs(160469001ull), Bs(167772165ull), Bs(168102405ull), Bs(168428805ull), Bs(173056005ull), Bs(178278405ull), Bs(201326595ull), Bs(201526275ull), Bs(202113795ull), Bs(204521475ull), Bs(213921795ull), Bs(251658255ull), Bs(252645135ull), Bs(267448335ull), Bs(268435457ull), Bs(268505089ull), Bs(268574721ull), Bs(268713985ull), Bs(268992513ull), Bs(269484289ull), Bs(270533121ull), Bs(272630785ull), Bs(276826113ull), Bs(285212689ull), Bs(286331153ull), Bs(287449617ull), Bs(289686545ull), Bs(294160401ull), Bs(301989921ull), Bs(303178017ull), Bs(304157217ull), Bs(306742305ull), Bs(310659105ull), Bs(335544385ull), Bs(336871745ull), Bs(338199105ull), Bs(339809345ull), Bs(344074305ull), Bs(402653313ull), Bs(404259201ull), Bs(405029505ull), Bs(406987905ull), Bs(411113601ull), Bs(536870913ull), Bs(536944641ull), Bs(537006081ull), Bs(537165825ull), Bs(537411585ull), Bs(537920001ull), Bs(538968321ull), Bs(541067265ull), Bs(545260545ull), Bs(553648161ull), Bs(554832417ull), Bs(555819297ull), Bs(558385185ull), Bs(562332705ull), Bs(570425361ull), Bs(571548177ull), Bs(572657937ull), Bs(574916625ull), Bs(579355665ull), Bs(603979905ull), Bs(605569665ull), Bs(606372225ull), Bs(608311425ull), Bs(612443265ull), Bs(671088705ull), Bs(672432705ull), Bs(673726785ull), Bs(675358785ull), Bs(679613505ull), Bs(805306371ull), Bs(805515267ull), Bs(806141955ull), Bs(808452867ull), Bs(817892355ull), Bs(855638067ull), Bs(858993459ull), Bs(869059635ull), Bs(1006633155ull), Bs(1010615235ull), Bs(1019428035ull), Bs(1073741825ull), Bs(1073823745ull), Bs(1073905665ull), Bs(1074008065ull), Bs(1074274305ull), Bs(1074791425ull), Bs(1075841025ull), Bs(1077936385ull), Bs(1082130945ull), Bs(1090519105ull), Bs(1091834945ull), Bs(1093150785ull), Bs(1094795585ull), Bs(1099072065ull), Bs(1107296385ull), Bs(1108878465ull), Bs(1109661825ull), Bs(1111654785ull), Bs(1115767425ull), Bs(1140850705ull), Bs(1141982225ull), Bs(1143113745ull), Bs(1145311505ull), Bs(1149772305ull), Bs(1207959585ull), Bs(1209173025ull), Bs(1210140705ull), Bs(1212686625ull), Bs(1216614945ull), Bs(1342177285ull), Bs(1342525445ull), Bs(1342873605ull), Bs(1347421445ull), Bs(1352665605ull), Bs(1426063445ull), Bs(1431655765ull), Bs(1437248085ull), Bs(1509949605ull), Bs(1515890085ull), Bs(1520786085ull), Bs(1610612745ull), Bs(1611042825ull), Bs(1611227145ull), Bs(1616906505ull), Bs(1620051465ull), Bs(1711276185ull), Bs(1718000025ull), Bs(1721329305ull), Bs(1761607785ull), Bs(1768515945ull), Bs(1771476585ull), Bs(2147483649ull), Bs(2147581953ull), Bs(2147631105ull), Bs(2147753985ull), Bs(2148012033ull), Bs(2148534273ull), Bs(2149581825ull), Bs(2151678465ull), Bs(2155872513ull), Bs(2164260993ull), Bs(2165840001ull), Bs(2166629505ull), Bs(2168603265ull), Bs(2172748161ull), Bs(2181038145ull), Bs(2182359105ull), Bs(2183664705ull), Bs(2185331265ull), Bs(2189574465ull), Bs(2214592545ull), Bs(2215790625ull), Bs(2216789025ull), Bs(2219315745ull), Bs(2223251745ull), Bs(2281701393ull), Bs(2282850321ull), Bs(2283947025ull), Bs(2286166545ull), Bs(2290618641ull), Bs(2415919113ull), Bs(2416336905ull), Bs(2416545801ull), Bs(2422212105ull), Bs(2425358601ull), Bs(2516582505ull), Bs(2523502185ull), Bs(2526439785ull), Bs(2566914201ull), Bs(2573624985ull), Bs(2576980377ull), Bs(2684354565ull), Bs(2684723205ull), Bs(2685030405ull), Bs(2689600005ull), Bs(2694841605ull), Bs(2768240805ull), Bs(2774162085ull), Bs(2779096485ull), Bs(2852126805ull), Bs(2857740885ull), Bs(2863289685ull), Bs(3221225475ull), Bs(3221471235ull), Bs(3222024195ull), Bs(3224374275ull), Bs(3233809155ull), Bs(3271557315ull), Bs(3275504835ull), Bs(3284386755ull), Bs(3422552115ull), Bs(3425946675ull), Bs(3435934515ull), Bs(4026531855ull), Bs(4027576335ull), Bs(4042264335ull), Bs(4278190335ull), Bs(4294967295ull)};
const int sz = 374;
int where_one[sz][M];
int where[sz][sz];
const int mod = 1000000007;
using Mint = Modular<mod>;
using State = array<Mint, sz>;

const int N = 111111;
struct Edge {
	int to;
	int w;
};
vector<Edge> a[N];
bool is_special[N];
char used[N];
int tree_w[N];
int subs_idx[N];
int gay_pair[N];
char bad[N];

void dfs(int v, int p) {
	used[v] = 1;
	for (const auto& [to, w] : a[v]) {
		if (is_special[v] && is_special[to]) {
			if (to > v) {
				gay_pair[v] = to;
				gay_pair[to] = v;
			}
			continue;
		}
		if (to == p || used[to] == 2) {
			continue;
		} else if (used[to] == 1) {
			if (subspaces[subs_idx[v]][tree_w[v] ^ tree_w[to] ^ w]) {
				bad[v] = true;
			}
			subs_idx[v] = where_one[subs_idx[v]][tree_w[v] ^ tree_w[to] ^ w];
		} else {
			tree_w[to] = tree_w[v] ^ w;
			dfs(to, v);
			if ((subspaces[subs_idx[v]] & subspaces[subs_idx[to]]).count() != 1ul) {
				bad[v] = true;
			}
			subs_idx[v] = where[subs_idx[v]][subs_idx[to]];
			bad[v] |= bad[to];
		}
	}
	used[v] = 2;
}

int main() {
	// Bs init = {};
	// init.flip(0);
	// rec(init, init);
	// cout << subspaces.size() << "\n";
	// sort(all(subspaces), [](const Bs& a, const Bs& b) {
	// 	return a.to_ullong() < b.to_ullong();
	// });
	// subspaces.resize(unique(all(subspaces), [](const Bs& a, const Bs& b) {
	// 	return a.to_ullong() == b.to_ullong();
	// }) - subspaces.begin());
	// for (auto b : subspaces) {
	// 	cout << "Bs(" << b.to_ullong() << "ull), ";
	// }
	// cout << "\n";

	assert(sz == (int)subspaces.size());
	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j < M; ++j) {
			if (!subspaces[i][j]) {
				where_one[i][j] = find(all(subspaces), add(subspaces[i], j)) - subspaces.begin();
			}
		}
	}
	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j < sz; ++j) {
			Bs b = subspaces[i];
			for (int k = 0; k < M; ++k) {
				if (subspaces[j][k] && !b[k]) {
					b = add(b, k);
				}
			}
			where[i][j] = find(all(subspaces), b) - subspaces.begin();
		}
	}

	memset(gay_pair, -1, sizeof(gay_pair));
	int n = nxt(), m = nxt();
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1, w = nxt();
		a[u].push_back({v, w});
		a[v].push_back({u, w});
	}

	for (const auto& e : a[0]) {
		is_special[e.to] = 1;
	}

	dfs(0, -1);

	State state = {};
	state[0] = 1;
	vector<pair<int, int>> nonint;
	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j < sz; ++j) {
			if ((subspaces[i] & subspaces[j]).count() == 1ul) {
				nonint.push_back({i, j});
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (!is_special[i]) {
			continue;
		}
		if (gay_pair[i] > i) {
			if ((subspaces[subs_idx[i]] & subspaces[subs_idx[gay_pair[i]]]).count() != 1ul) {
				bad[i] = true;
			}
			subs_idx[gay_pair[i]] = where[subs_idx[i]][subs_idx[gay_pair[i]]];
			bad[gay_pair[i]] |= bad[i];
			continue;
		}
		if (bad[i]) {
			continue;
		}
		State new_state = state;
		if (gay_pair[i] == -1) {
			int cur = subs_idx[i];
			for (int j = 0; j < sz; ++j) {
				if ((subspaces[j] & subspaces[cur]).count() == 1ul) {
					new_state[where[j][cur]] += state[j];
				}
			}
		} else {
			// add only one
			int cur = subs_idx[i];
			for (int j = 0; j < sz; ++j) {
				if ((subspaces[j] & subspaces[cur]).count() == 1ul) {
					new_state[where[j][cur]] += state[j] * 2;
				}
			}
			// add both
			int ww = 0;
			for (auto e : a[i]) {
				if (e.to == gay_pair[i]) {
					ww = e.w;
				}
			}
			if (!subspaces[cur][tree_w[i] ^ tree_w[gay_pair[i]] ^ ww]) {
				cur = where_one[cur][tree_w[i] ^ tree_w[gay_pair[i]] ^ ww];
				for (int j = 0; j < sz; ++j) {
					if ((subspaces[j] & subspaces[cur]).count() == 1ul) {
						new_state[where[j][cur]] += state[j];
					}
				}
			}
		}
		state = new_state;
	}

	cout << accumulate(all(state), Mint(0)) << "\n";

	return 0;
}