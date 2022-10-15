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
#ifdef DEBUG
	#define debug(...) cerr << "[" <<  #__VA_ARGS__ << "]:", dbg(__VA_ARGS__)
#else
	#define debug(...) 37
#endif
 
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, x, y;
		cin >> n >> x >> y;
		vector<int> a(n);
	  vector<vector<int>> inds(n + 2);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			inds[a[i]].push_back(i);			
		}
		debug(a);
		priority_queue<pair<int, int>> pq;
		auto add = [&](int ind) {
			if (!inds[ind].empty()) pq.emplace((int) inds[ind].size(), ind);
		};
		int gar = 1;
		while (!inds[gar].empty()) ++gar;
		for (int i = 0; i < n + 2; ++i) add(i);
		vector<int> ans(n, gar);
		for (int i = 0; i < x; ++i) {
			int tp = pq.top().second;
			debug(pq.top());
			pq.pop();		
			ans[inds[tp].back()] = tp;
			inds[tp].pop_back();
			debug(inds);
			add(tp);
		}
		debug(ans);
		debug(pq.top());
		pq.emplace(0, 0);
		int mx = pq.top().first, tot = n - x, ms = max(mx * 2 - tot, 0);
		debug(tot, ms, y, x);	
		if (tot - ms < y - x) cout << "NO\n";
		else {
			cout << "YES\n";
			int del = n - y;
			vector<int> ind;
			while (!pq.empty()) {
				int tp = pq.top().second;
				pq.pop();
				ind.insert(ind.end(), inds[tp].begin(), inds[tp].end());
			}
			debug(ind);
			debug(del);
			vector<int> temp(n, gar);
			for (int i = 0; i < (int) ind.size(); ++i) {
				int next = (i + (tot / 2)) % (int) ind.size();
				ans[ind[i]] = temp[ind[i]] = a[ind[next]];
			}
			debug(temp, ans, a, x, y);
			for (int i = 0; i < n; ++i) {
				if (temp[i] == a[i] && del) {		
					--del;
					ans[i] = gar;
					temp[i] = gar;											
				}
			}
			for (int i = 0; i < n; ++i) {
				if (temp[i] != gar && del) {		
					--del;
					ans[i] = gar;											
				}
			}
			assert(del == 0);
			for (auto el : ans) cout << el << ' ';
			cout << '\n';
		}
	}
}