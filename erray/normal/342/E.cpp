#include<bits/stdc++.h>
 
using namespace std;
template<typename st, typename nd> string to_string(pair<st, nd> P);
template<typename f, typename s, typename t> string to_string(tuple<f, s, t> T);
template<typename f, typename s, typename t, typename th> string to_string(tuple<f, s, t, th> T);
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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a;--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	const int lg = (int) log2(n) + 2;
	vector<vector<int>> lca(n, vector<int>(lg));
	vector<int> lev(n), tour, ct(n, 1);
	vector<pair<int, int>> se(n);
	function<int(int, int)> dfs = [&](int nd, int par) {
		se[nd].first = se[nd].second = tour.size();
		tour.push_back(nd);
		lca[nd][0] = par;
		for (auto el : g[nd]) {
			if (el != par) {
				lev[el] = lev[nd] + 1;
				ct[nd] += dfs(el, nd);
		  	se[nd].second = tour.size();
				tour.push_back(nd);		
			}
		}
		return ct[nd];
	};
	dfs(0, 0);
	for (int i = 1; i < lg; ++i) {
		for (int j = 0; j < n; ++j) {
			lca[j][i] = lca[lca[j][i - 1]][i - 1];
		}
	}
	debug("Passed");
	debug(tour);
	debug(se);
	const int sz = tour.size(), lgsz = (int) log2(sz) + 2;
	vector<vector<int>> rmq(lgsz, vector<int>(sz));
	for (int j = 0; j < lgsz; ++j) {
		for (int i = 0; i < sz - (1 << j) + 1; ++i) {
			debug(j, i);
			if (!j) rmq[j][i] = tour[i];
			else {
				int r = i + (1 << (j - 1));
				if (lev[rmq[j - 1][i]] < lev[rmq[j - 1][r]]) {
					rmq[j][i] = rmq[j - 1][i];			  	 	
				}	else rmq[j][i] = rmq[j - 1][r];			  	 	
			}
		}	
	}
	debug(rmq);
	vector<int> logfor(sz + 1);
	int lst = 1;
	for (int i = 1; i < sz + 1; ++i) {
		logfor[i] = logfor[i - 1];
		if (i == lst * 2) {
			++logfor[i];
			lst = i;
		}		
	}
	auto dist = [&](int a, int b) {
		debug(a, b);
		if (a == b) return 0;
		int LCA;
		if (se[a] > se[b]) swap(a, b);
		if (se[a].second > se[b].first) {
			return lev[b] - lev[a];
		}
		int l = se[a].second, r = se[b].first, csz = logfor[r - l + 1], qr = r - (1 << csz) + 1;
		assert(l <= qr);
		LCA = rmq[csz][qr];
		if (lev[rmq[csz][l]] < lev[rmq[csz][qr]]) {
			LCA = rmq[csz][l];		
    }
		debug(lev[a] + lev[b] - 2 * lev[LCA]);
		return lev[a] + lev[b] - 2 * lev[LCA];
	};
	vector<int> up(n);
	vector<bool> del(n);
	function<void(int, int)> cent = [&](int nd, int par) {
		int sum = 1, mx = 0, mxnd = -1;
		for (auto el : g[nd]) {
			if (!del[el]) {
				sum += ct[el];
				if (ct[el] > mx) {
					mx = ct[el];
					mxnd = el;
				}
			}
		}
		if (mxnd == -1 || mx * 2 <= sum) {
			del[nd] = true;
			up[nd] = par;
			for (auto el : g[nd])  {
				if (!del[el]) {
					cent(el, nd);
				}
			}	
		} else {
			ct[nd] = sum - mx;
			cent(mxnd, par);	
		}
	};
	cent(0, -1);
	debug(up);
	vector<int> best(n, n + 2);
	auto upd = [&](int nd) {
		int start = nd;
		while (nd != -1) {
			debug(nd);
			best[nd] = min(best[nd], dist(start, nd));
			nd = up[nd];					 
		}
	};
	auto query = [&](int nd) {
		int start = nd, r = INT_MAX;
		while (nd != -1) {
			r = min(r, best[nd] + dist(start, nd));				
		 	nd = up[nd];
		}
		return r;
	};
	upd(0);
	while (m--) {
		int type, nd;
		cin >> type >> nd;
		--type;--nd;
		if (type) cout << query(nd) << '\n';
		else upd(nd);
	}

}