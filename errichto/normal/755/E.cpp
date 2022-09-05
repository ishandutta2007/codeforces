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

vector<pair<int,int>> w;
void add(int a, int b) {
	w.push_back({a,b});
}

void NO() {
	puts("-1");
	exit(0);
}
void write() {
	printf("%d\n", (int) w.size());
	for(pair<int,int> p : w)
		printf("%d %d\n", p.first, p.second);
	exit(0);
}

const int nax = 1005;
const int inf = 1e9 + 5;
bool e[nax][nax];
int dist[nax][nax];
void mini(int & a, int b) { a = min(a, b); }
void maxi(int & a, int b) { a = max(a, b); }

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	if(n <= 3) NO();
	if(k > 3) NO();
	if(k == 1) NO();
	if(k == 3) {
		add(1, 2);
		add(1, 3);
		add(2, 4);
		for(int i = 5; i <= n; ++i) {
			add(1, i);
			add(2, i);
		}
		write();
	}
	if(k == 2) {
		if(n == 4) NO();
		while(true) {
			
			for(int i = 0; i < n; ++i)
				for(int j = i + 1; j < n; ++j)
					e[i][j] = e[j][i] = rand() % 2;
			int to = inf;
			if(n >= 200) to = 2;
			else for(int rep = 0; rep < 2; ++rep) {
				for(int i = 0; i < n; ++i) {
					for(int j = 0; j < n; ++j)
						dist[i][j] = inf;
					dist[i][i] = 0;
				}
				for(int i = 0; i < n; ++i)
					for(int j = 0; j < n; ++j)
						if(e[i][j])
							dist[i][j] = 1;
				for(int k2 = 0; k2 < n; ++k2)
					for(int i = 0; i < n; ++i)
						for(int j = 0; j < n; ++j)
							mini(dist[i][j], dist[i][k2] + dist[k2][j]);
				int ple = 0;
				for(int i = 0; i < n; ++i)
					for(int j = 0; j < n; ++j)
						maxi(ple, dist[i][j]);
				if(ple == inf) ple = -1;
				mini(to, ple);
				for(int i = 0; i < n; ++i)
					for(int j = 0; j < n; ++j)
						e[i][j] = !e[i][j];
			}
			if(to == 2) {
				for(int i = 0; i < n; ++i)
					for(int j = i + 1; j < n; ++j)
						if(e[i][j])
							add(i + 1, j + 1);
				write();
			}
			debug() << "try again";
		}
	}
	assert(false);
}