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
struct debug{
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
sim dor(const c &) { ris; }
#endif
};
#define imie(x) " [" << #x ": " << (x) << "] "

const int nax = 3005;
int in[nax];
bool win[nax][nax];

void NO() {
	puts("no");
	//assert(false);
	exit(0);
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int s = n * (n - 1);
	for(int i = 0; i < k; ++i) {
		scanf("%d", &in[i]);
		s -= in[i];
	}
	while(k != n && s > 0) {
		for(int j = k; j < n; ++j)
			if(s > 0) {
				//puts("b");
				s--;
				++in[j];
				if(in[j] > in[k-1]) NO();
			}
	}
	k = n;
	for(int i = 0; i < k; ++i) {
		//scanf("%d", &in[i]);
		in[i] -= n - 1;
	}
	vector<pair<int,int>> w;
	for(int i = 0; i < n; ++i) {
		if(i < k)
			w.push_back({in[i], i});
		else
			w.push_back({in[k-1], i});
	}
	for(int rep = 0; rep < k; ++rep) {
		for(pair<int,int> & p : w)
			if(p.second >= k)
				if(p.first > 0) p.first = -1000000005;
		sort(w.begin(), w.end(), [&](pair<int,int> a, pair<int,int> b) {
			return make_pair(a.first,-a.second) < make_pair(b.first,-b.second);
		});
		// for(pair<int,int> p : w) printf("(%d,%d), ", p.first, p.second); puts("");
		pair<int,int> big = w.back();
		w.pop_back();
		sort(w.begin(), w.end());
		// if(big.second >= k) NO();
		assert(big.second < k);
		if(big.first < 0) NO();
		if(big.first > (int) w.size()) NO();
		for(int i = 0; i < big.first; ++i) {
			win[big.second][w[i].second] = true;
			w[i].first++;
		}
	}
	for(int i = 0; i < n; ++i) {
		int cnt = 0;
		for(int j = 0; j < n; ++j) {
			if(i == j) continue;//printf("X");
			else if(win[i][j]) cnt += 2;//printf("W");
			else if(win[j][i]) continue; //printf("L");
			else cnt += 1;// printf("D");
		}
		if(i < k && cnt != in[i] + n - 1) NO();
		if(i >= k && cnt > in[k-1] + n - 1) NO();
	}
	puts("yes");
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(i == j) printf("X");
			else if(win[i][j]) printf("W");
			else if(win[j][i]) printf("L");
			else printf("D");
		}
		puts("");
	}
}