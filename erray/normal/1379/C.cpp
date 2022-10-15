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
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		struct fl {
			int a, b;		
			operator< (const fl ot) const {
				return a < ot.a;
			}
		};
		vector<fl> a(m);
		for (auto& el : a) cin >> el.a >> el.b;
		sort(a.begin(), a.end());
		vector<long long> suf(m + 1);
		for (int i = m - 1, ind = 1; i >= 0; --i, ++ind) {
			suf[ind] = suf[ind - 1] + a[i].a;
		}
		debug(suf);
		int cur = 0;
		long long ans = 0;
		for (auto el : a) {                                         
			int sz = a.end() - lower_bound(a.begin(), a.end(), fl{el.b, 0});
			debug(el.b, sz);
			if (m - sz <= cur) {
			 	sz = min(sz, n);			
				ans = max(ans, (n - sz) * 1ll * el.b + suf[sz]);
				debug((n - sz) * 1ll * el.b + suf[sz]);											
			} else {
			 	sz = min(sz, n);							
				ans = max(ans, (n - sz - 1) * 1ll * el.b + el.a + suf[sz]);
				debug((n - sz - 1) * 1ll * el.b + el.a + suf[sz]);
			}
			++cur;
		}
		cout << ans << '\n';
	} 
}