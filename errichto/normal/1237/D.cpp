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
 
using ll = long long;



int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < 2 * n; ++i) {
		a.push_back(a[i]);
	}
	// (4, 7, 5) -> (4, 1, 5,  4, 1, 5,  4, 1, 5)
	//                     S      E
	vector<int> answer(n);
	// 1) find answer[n-1]
	answer[n-1] = n - 1 + 2 * n;
	int pref_max = a[n-1];
	for(int i = n - 1 + 1; i < answer[n-1]; ++i) {
		pref_max = max(pref_max, a[i]);
		if(a[i] < (pref_max + 1) / 2) {
			answer[n-1] = i;
			break;
		}
	}
	
	int B = 1;
	while(B < (int) a.size()) {
		B *= 2;
	}
	vector<int> tree(2 * B);
	for(int i = 0; i < (int) a.size(); ++i) {
		tree[B+i] = a[i];
	}
	for(int i = B - 1; i >= 0; --i) {
		tree[i] = min(tree[2*i], tree[2*i+1]);
	}
	
	// 2) find answer[n-2], answer[n-3], ...
	for(int start = n - 2; start >= 0; --start) {
		answer[start] = min(answer[start+1], start + 2 * n);
		// mono-queue / monotonic queue
		
		int i = B + start;
		int value = (a[start] + 1) / 2;
		while(i >= 2) {
			if(i % 2 == 0 && tree[i+1] < value) {
				i++;
				// go down
				while(i < B) {
					if(tree[2*i] < value) {
						i = 2 * i;
					}
					else {
						i = 2 * i + 1;
					}
				}
				answer[start] = min(answer[start], i - B);
				break;
			}
			i /= 2;
		}
		
		//~ for(int i = start + 1; i < answer[start]; ++i) {
			//~ if(a[i] < (a[start] + 1) / 2) {
				//~ answer[start] = i; // first bad
				//~ break;
			//~ }
		//~ }
	}
	for(int i = 0; i < n; ++i) {
		if(answer[i] == i + 2 * n) {
			printf("-1 ");
		}
		else {
			printf("%d ", answer[i] - i);
		}
	}
	puts("");
}