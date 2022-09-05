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

const int nax = 1e6 + 5;
int tmp[nax], cnt[nax];
long long h[nax];
unsigned long long total[nax];
const int mod = 1e9 + 7;
bool vis[nax];
int sd = 2345678;
int ne() {
	sd = (long long) (sd * 84398175LL + 4591132325) % mod;
	return sd ^ 4581292;
}

int main() {
	srand(943953);
	int days, n;
	scanf("%d%d", &days, &n);
	for(int rep = 0; rep < days; ++rep) {
		int size;
		scanf("%d", &size);
		for(int i = 0; i < size; ++i) {
			scanf("%d", &tmp[i]);
			++cnt[tmp[i]];
		}
		for(int i = 0; i < size; ++i) {
			int who = tmp[i];
			if(h[cnt[who]] == 0) {
				h[cnt[who]] =
(((((((long long) rand()) << 16) + rand()) << 16) + rand()) << 16) + rand();
h[cnt[who]] ^= (unsigned long long) (rep * 9592134LL + i + tmp[i] * 469125LL);
h[cnt[who]] ^= ne();
			}
			if(!vis[who]) {
				total[who] ^= h[cnt[who]];
				vis[who] = true;
			}
		}
		for(int i = 0; i < size; ++i) {
			int who = tmp[i];
			vis[who] = false;
			h[cnt[who]] = 0;
			cnt[who] = 0;
		}
	}
	vector<unsigned long long> w;
	for(int i = 1; i <= n; ++i)
		w.push_back(total[i]);
	sort(w.begin(), w.end());
	debug() << imie(w);
	long long ans = 1;
	for(int i = 0; i < (int) w.size(); ++i) {
		int ple = 1;
		while(i + 1 != (int) w.size() && w[i] == w[i+1]) {
			++ple;
			++i;
		}
		for(int j = 1; j <= ple; ++j)
			ans = ans * j % mod;
		
	}
	printf("%lld\n", ans);
}