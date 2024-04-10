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

const int base = 2 * 1024 * 1024;
pair<int,int> tree[2*base];
// (count, value)

int main() {
	int q, k;
	scanf("%d%d", &q, &k);
	vector<int> moves(k);
	for(int i = 0; i < k; ++i) {
		scanf("%d", &moves[i]);
	}
	for(int i = k - 1; i >= 1; --i) {
		moves[i] = moves[i] - moves[i-1];
	}
	int nxt = 0;
	while(q--) {
		int type;
		scanf("%d", &type);
		if(type == -1) {
			int start = 0;
			debug() << imie(moves);
			for(int skip : moves) {
				// for(int rep = 0; rep < skip; ++rep) {
				if(start >= base) {
					break;
				}
				start += base;
				debug() << imie(start) imie(tree[start]);
				skip -= tree[start].first;
				if(skip) {
					while(start >= 1) {
						if(start % 2 == 0 && tree[start+1].first >= skip) {
							start++;
							break;
						}
						else if(start % 2 == 0) {
							skip -= tree[start+1].first;
						}
						start /= 2;
					}
					if(start == 0) {
						start = base;
						break;
					}
					while(start < base) {
						if(tree[start*2].first >= skip) {
							start *= 2;
						}
						else {
							skip -= tree[start*2].first;
							start = 2 * start + 1;
						}
						assert(tree[start].first);
					}
				}
				start -= base;
				// while(start < base && !tree[base+start].first) {
					// ++start;
				// }
				debug() << imie(start);
				if(start < base) {
					debug() << "erase" imie(tree[base+start].second);
					assert(tree[base+start].first);
					for(int i = base + start; i >= 1; i /= 2) {
						tree[i].first--;
					}
					start++;
				}
				else {
					break;
				}
			}
		}
		else {
			int pos = base + nxt;
			tree[pos].second = type;
			for(int i = pos; i >= 1; i /= 2) {
				tree[i].first++;
			}
			nxt++;
		}
		
	}
	vector<int> answer;
	for(int i = 0; i < nxt; ++i) {
		if(tree[base+i].first) {
			answer.push_back(tree[base+i].second);
		}
	}
	if(answer.empty()) {
		puts("Poor stack!");
	}
	else {
		for(int x : answer) {
			printf("%d", x);
		}
		puts("");
	}
}