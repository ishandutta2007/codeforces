#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }



int main() {
	vector<string> in(6);
	for(int i = 0; i < 6; ++i) {
		cin >> in[i];
	}
	sort(in.begin(), in.end());
	vector<string> ans;
	do {
		string a = in[0], b = in[1], c = in[2], d = in[3];
		string e = in[4], f = in[5];
		int A = a.length();
		int B = b.length();
		int C = c.length();
		int D = d.length();
		int E = e.length();
		int F = f.length();
		// if(a[0] == b[0] && A + E == C + 1 && a.back() == 
		int H = D;
		int W = C;
		vector<string> grid(H, string(W, '.'));
		bool ok = true;
		auto foo = [&](int row, int col, string s, bool is_hori) {
			for(int i = 0; i < (int) s.length(); ++i) {
				if(row < H && col < W) {
					if(grid[row][col] != '.' && grid[row][col] != s[i]) {
						ok = false;
					}
					else grid[row][col] = s[i];
				}
				else {
					ok = false;
				}
				if(is_hori) col++;
				else row++;
			}
		};
		const bool HORI = true;
		const bool VERT = false;
		foo(0,0,a,HORI);
		foo(0,0,b,VERT);
		foo(0,A-1,d,VERT);
		foo(B-1,0,c,HORI);
		foo(D-1,A-1,e,HORI);
		foo(B-1,C-1,f,VERT);
		if(A + E == C + 1 && B + F == D + 1) {
			
		}
		else {
			ok = false;
		}
		if(!ok) {
			continue;
		}
		if(ans.empty() || grid < ans) {
			ans = grid;
		}
	} while(next_permutation(in.begin(), in.end()));
	if(ans.empty()) {
		puts("Impossible");
	}
	for(string s : ans) {
		cout << s << endl;
	}
}