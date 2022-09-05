#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e; };
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

const int nax = 1e5 + 5;

string read() {
	static char sl[nax];
	scanf("%s", sl);
	return string(sl);
}

void NO() {
	puts("NO");
	exit(0);
}

//~ bool contains(const string & s, char ch) {
	//~ for(char he : s) if(he == ch) return true;
	//~ return false;
//~ }

int main() {
	int n;
	scanf("%d", &n);
	
	vector<pair<string, int>> they;
	
	for(int rep = 0; rep < n; ++rep) {
		
		string nowy = read();
		int mask = 0;
		for(char ch : nowy) mask |= 1 << (ch - 'a');
		
		vector<pair<string, int>> later;
		
		for(pair<string, int> p : they) {
			if((p.second & mask) == 0) {
				later.push_back(p);
				continue;
			}
			
			int any = -1;
			for(int i = 0; i < 26; ++i)
				if(mask & p.second & (1 << i))
					any = i;
			
			assert(any != -1);
			
			mask |= p.second;
			
			string b = p.first;
			
			// merge b with 'nowy'
			int where1 = 0, where2 = 0;
			while(b[where1] != 'a' + any) ++where1;
			while(nowy[where2] != 'a' + any) ++where2;
			
			string ultra;
			if(where1 > where2) {
				swap(nowy, b);
				swap(where1, where2);
			}
			//~ if(where1 <= where2) {
			ultra = nowy; // where2
			for(int i = (int) nowy.length(); true; ++i) {
				int j = i + where1 - where2;
				if(j >= (int) b.length()) break;
				ultra += b[j];
			}
			for(int i = 0; i < (int) b.length(); ++i) {
				int j = i + where2 - where1;
				if(j < 0 || j >= (int) ultra.length() || ultra[j] != b[i])
					NO();
			}
			nowy = ultra;
			if(__builtin_popcount(mask) != nowy.length()) NO();
			//~ }
			//~ else {
				
		}
		
			if(__builtin_popcount(mask) != nowy.length()) NO();
		
		later.push_back({nowy, mask});
		
		they = later;
	}
	debug() << imie(they);
	
	string ans;
	sort(they.begin(), they.end());
	for(auto p : they) ans += p.first;
	cout << ans << "\n";
	
	//~ vector<string> in(n);
	
	//~ for(int i = 0; i < n; ++i) {
		//~ in[i] = read();
		//~ if((int) in[i].length() > 26) NO();
		//~ for(char ch : in[i]) {
			//~ int val = ch - 'a';
			//~ if(mask[i] & (1 << val)) NO();
			//~ mask[i] |= 1 << val;
		//~ }
	//~ }
	//~ vector<string> parts;
	//~ int mask_already = 0;
	//~ vector<int> waiting;
	//~ for(int val = 0; val < 26; ++val)
		//~ if(!(mask_already & (1 << val))) {
			//~ for(int i = 0; i < n; ++i)
				//~ if(in[i] & (1 << val)) {
					//~ mask_already |= mask[
				//~ }
		//~ }
	//~ for(char ch = 'a'; ch <= 'z'; ++ch) {
		//~ bool started = false;
		//~ for(const string & s : in)
			//~ if(contains(s, ch)) {
				//~ if(!
			//~ }
}