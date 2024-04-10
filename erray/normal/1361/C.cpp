#include<bits/stdc++.h>

using namespace std;

template<typename st, typename nd> string to_string(pair<st, nd> P);
string to_string (const string& Str) { 
	string r;
	r+= (char) 34; r+= Str; r+= (char) 34;
	return r;
}
string to_string (const bool& B) {
	return (B ? "true" : "false");
}
string to_string (const char& c) {
	string rs;
	return rs + (char) 39 + c + (char) 39;
}
string to_string (const char* Sr) {
	return to_string((string) Sr);
}
template<size_t sz> string to_string (const bitset<sz> Bs) {
	string r;
	for (size_t i = 0; i < sz; ++i) {
		r += static_cast<char>((int) Bs[i] + 48);
	}
	return r;
}
string to_string (const vector<int> V) {
	string r;
	r += 123;
	for (auto& el : V) {
		if (r.size() != 1) {
			r += ", ";
		}	
		r += to_string(el);
	}
	r += 125;
	return r;
}
template<typename dimV> string to_string (dimV vd) {
	string r;
	r += 123;
	for (auto& el : vd) {
		if (r.size() != 1) {
			r += ", ";
		}
		r += to_string(el);
	}
	r += 125;
	return r;
}
template<typename st, typename nd> string to_string(pair<st, nd> P) {
	return "(" + to_string(P.first) + ", " + to_string(P.second) + ")"; 
}
template<typename f, typename s, typename t> string to_string(tuple<f, s, t> T) {
	return "(" + to_string(get<0>(T)) + ", " + to_string(get<1>(T)) + ", " + to_string(get<2>(T)) + ")";
}
template<typename f, typename s, typename t, typename th> string to_string(tuple<f, s, t, th> T) {
	return "(" + to_string(get<0>(T)) + ", " + to_string(get<1>(T)) + ", " + to_string(get<2>(T)) + ", " + to_string(get<3>(T)) + ")";
}
void dbg () {
	cerr << endl;
}
template<typename st, typename... en> void dbg (st St, en... E){
	cerr << "  " << to_string(St);
	dbg(E...);
}
#ifdef LOCAL 
	#define debug(...) cerr << "[" <<  #__VA_ARGS__ << "]:", dbg(__VA_ARGS__)
#else
	#define debug(...) 37
#endif

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(2));
	int e = 20;
	for (int i = 0; i < n; ++i) {
		cin >> a[i][0] >> a[i][1];
		//if (a[i][0] != a[i][1]) e = min(e, __builtin_ctz(a[i][0] ^ a[i][1]));
		//debug(e, a[i][0] ^ a[i][1]);
	} 
	auto check = [&](int mid) -> vector<int> {
		int Max = 1 << mid;
		vector<vector<pair<int, pair<int, int>>>> g(Max);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 2; ++j) {
				g[a[i][j] & (Max - 1)].emplace_back(a[i][j ^ 1] & (Max - 1), make_pair(i, j));
			}
		}						
		vector<int> r, vis(n);
		if (any_of(g.begin(), g.end(), [](auto el) {
			return el.size() & 1;		
		})) return vector<int>(0);
		for (int i = 0; i < Max; ++i) {   
			function<void(int, int)> dfs = [&] (int nd, int source) {
				while (!g[nd].empty()) {
					int next = g[nd].back().first, ind = g[nd].back().second.first, oe = g[nd].back().second.second;
					g[nd].pop_back();
					if (!vis[ind]) {
						vis[ind] = true;
						dfs(next, ind * 2 + oe);
					}
				}
				debug(nd, source);
				if (source != -1) {
					r.push_back(source ^ 1);
					r.push_back(source);
				}
			};
			if (!r.empty() && !g[i].empty()) {
				return vector<int>(0);
			}
			if (!g[i].empty()) {
				 dfs(i, -1);
			}	
		}
		assert(r.size() == n * 2);
		return r;
	};
	int s = 0;
	debug(e, s);
	while (e - s > 1) {
		debug(e, s);
		int mid = s + e >> 1;
		if (check(mid).empty()) e = mid;
		else s = mid;	
	}
	if (!check(e).empty()) s = e;
	vector<int> ans = check(s);
	cout << s << '\n';
	for (int el : ans) cout << el + 1 << ' '; 
}