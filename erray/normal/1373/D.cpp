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
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		long long sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			if (!(i & 1)) sum += a[i];
		}
		long long ans = 0, mx = 0, ans2 = 0, mx2 = 0;    
		for (int i = 0; i < n - (n & 1); ++i) {
			if (i & 1) {
				ans += a[i];
				ans = max(0ll, ans);
				mx = max(ans, mx);		
			} else {
				ans -= a[i];								   		
			}
			debug(ans);
		}	
		for (int i = 1; i < n - !(n & 1); ++i) {
			if (i & 1) {
				ans2 += a[i];
			} else {
				ans2 -= a[i];								   		
				ans2 = max(0ll, ans2);
				mx2 = max(mx2, ans2);	
			}
			debug(ans2);
		}
		cout << sum + max(mx, mx2) << '\n';
	}
}