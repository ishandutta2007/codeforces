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

// CCCCCCCC


// PCCPCPPPPPPPPPPPPPPPPPPPP

// PCCPCPCPCPCPCPCPPPPPPPPPP


// PCCPPPPPPPPPPPPPPPPPPC
// PCCPPPPPPPPPPPPPPPPPPP



// (CCCCC)PCPCPCPC(PPPP)(PPC)
      // ^

const int mod = 998244353;

void test_case() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	long long at_most = 0;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		at_most += a[i];
	}
	if(n == 1) {
		puts("1");
		return;
	}
	at_most = (at_most - 1) / 2; // the sum of C
	long long answer = 1; // PPPPPPP
	
	
	long long suffix = 0;
	for(int i = n - 1; i >= 1; --i) { // does count PCCCCCC
		suffix += a[i];
		if(suffix <= at_most) {
			answer++;
		}
	}
	// rep=0 -> 2
	// rep=1 -> 3
	vector<long long> sum(n);
	for(int i = 0; i < n; ++i) {
		sum[i] = a[i];
		if(i >= 2) {
			sum[i] += sum[i-2];
		}
	}
	for(int rep = 0; rep < 2; ++rep) { // second repetition considers PC...
		long long prefix = (rep == 0 ? a[0] : a[1]);
		for(int start = (rep == 0 ? 1 : 2); start < n && prefix <= at_most; ++start) {
			// first P
			long long tmp = 0;
			answer++; // CCCCCCPPPPPPPPPP
			if(start <= n - 3 && prefix + a[n-1] <= at_most) {
				answer++;
			}
			int low = start - 1;
			int high = n - 1;
			if(low % 2 != high % 2) {
				high--;
			}
			assert(low <= high);
			while(low != high) {
				int mid = (low + high) / 2;
				if(mid % 2 != low % 2) {
					mid++;
				}
				long long p = sum[mid] - sum[start-1];
				// for(int i = start + 1; i <= mid; i += 2) {
					// p += a[i];
				// }
				if(prefix + p <= at_most) {
					low = mid;
				}
				else {
					high = mid - 2;
				}
			}
			answer += (low - (start - 1)) / 2;
			
			
			low = start - 1;
			high = n - 4;
			if(low % 2 != high % 2) {
				high--;
			}
			if(low <= high) {
				while(low != high) {
					int mid = (low + high) / 2;
					if(mid % 2 != low % 2) {
						mid++;
					}
					long long p = sum[mid] - sum[start-1];
					// for(int i = start + 1; i <= mid; i += 2) {
						// p += a[i];
					// }
					if(prefix + p + a[n-1] <= at_most) {
						low = mid;
					}
					else {
						high = mid - 2;
					}
				}
				answer += (low - (start - 1)) / 2;
			}
			
			/*for(int i = start + 1; i < n; i += 2) {
				tmp += a[i];
				// if(prefix + tmp <= at_most) {
					// answer++;
				// }
				if(prefix + tmp + a[n-1] <= at_most && i <= n - 4) {
					answer++;
				}
			}*/
			prefix += a[start];
		}
		
	}
	printf("%lld\n", answer % mod);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}