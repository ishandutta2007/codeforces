#include<bits/stdc++.h>
 
using namespace std;

template<typename T, typename F> string to_string(pair<T, F> p);
string to_string(string s) {
	return '"' + s + '"';
}
string to_string(const char* p) {
	return to_string((string) p);
}
string to_string(char c) {
	return (string) "'" + c + "'";
}
string to_string(bool b) {
	return (b ? "true" : "false");
}
template<size_t T> string to_string(bitset<T> bs) {
	return bs.to_string();
}
string to_string(vector<bool> v) {
	string res = "{";
	for (size_t i = 0; i < v.size(); ++i) {
		if ((int) res.size() > 1) res += ", ";
		res += to_string(v[i]);
	}
	res += "}";
	return res;
}
template<typename T> string to_string(T v) {
	string res = "{";
	for (const auto& el : v) {
		if ((int) res.size() > 1) res += ", ";
		res += to_string(el);
	}
	res += "}";
	return res;
}
template<typename T, typename F> string to_string(pair<T, F> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() {
	cerr << endl;
}
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
	cerr << "  " << to_string(H);
	debug_out(T...);
}
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) (void) 37
#endif
 
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, x, y, k;
	cin >> n >> m >> x >> k >> y;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];
	int ind = 0;
	long long ans = 0;
	b.push_back(-1);
	for (int i = 0; i <= m; ++i) {
		vector<int> ex;
		while (ind < n && a[ind] != b[i]) {
			ex.push_back(a[ind]);
			++ind;
		}		
		++ind;
		if (a[ind - 1] != b[i] && i != m)  return cout << -1, 0;
		debug(ex);
		if (ex.empty()) continue;
		
		bool del = (*max_element(ex.begin(), ex.end()) > max(b[i], (i > 0 ? b[i - 1] : 0)));
		debug(del);
		
		if (((int) ex.size() < k && del)) return cout << -1, 0;
		if ((long long) y * k > x) {
			ans += ((int) ex.size() % k) * 1ll * y + 1ll * ((int) ex.size() / k) * x;
		} else {
			if (del) ans += ((int) ex.size() - k) * 1ll * y + x;
			else ans += (int) ex.size() * 1ll * y;			
		}	
	}
	cout << ans << '\n';
}