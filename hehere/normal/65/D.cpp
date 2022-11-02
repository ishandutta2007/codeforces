#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#ifdef DEBUG
#define display(x) cerr << #x << " = " << x << endl;
#define displaya(a, st, n)\
	{cerr << #a << " = {";\
	for(int qwq = (st); qwq <= (n); ++qwq) {\
		if(qwq == (st)) cerr << a[qwq];\
		else cerr << ", " << a[qwq];\
	} cerr << "}" << endl;}
#define displayv(v) displaya(v, 0, (int)(v).size() - 1)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define display(x) ;
#define displaya(a, st, n) ;
#define displayv(v) ;
#define eprintf(...) if(0) fprintf(stderr, "...")
#endif
template<typename T> bool chmin(T &a, const T &b) { return a > b ? a = b, true : false; }
template<typename T> bool chmax(T &a, const T &b) { return a < b ? a = b, true : false; }

const int maxN = 10000 + 5;
int n;
string s;
map<char, int> mp;
string name[] = {"Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"};
set< basic_string<int> > S, T;

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	cin >> n;
	string s; cin >> s;
	mp['G'] = 0; mp['H'] = 1; mp['R'] = 2; mp['S'] = 3;
	S.clear(); T.clear();
	S.insert(basic_string<int>{0, 0, 0, 0});
	for(char c : s) {
		T.clear();
		if(c != '?') {
			for(auto x : S) {
				x[mp[c]]++;
				T.insert(x);
			}
		} else {
			for(auto x : S) {
				for(int i = 0; i < 4; ++i) if(x[i] == *min_element(x.begin(), x.end())) {
					x[i]++;
					T.insert(x);
					x[i]--;
				}
			}
		}
		T.swap(S);
//		display(c);
//		for(auto x : S) displayv(x);
	}
	set<int> A;
	for(auto x : S) {
		for(int i = 0; i < 4; ++i) if(x[i] == *min_element(x.begin(), x.end())) {
			A.insert(i);
		}
	}
	for(int x : A) cout << name[x] << endl;
	return 0;
}