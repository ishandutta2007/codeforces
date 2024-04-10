// Lemma / well-known fact
// Lexicographical comparison of infinitely repeated s vs. r
// is the same as lexicographical comparison of sr vs. rs

// sssssss vs. rrrrrrrrrr
// same as:
// sr vs. rs

// bacbd(bac | bd)   bac(bac)bd

// find editorial of TCO Warsaw Regional ~2017


#include <bits/stdc++.h>
using namespace std;
const int nax = 5e5;
char s[nax];

const int MOD = 1e9 + 7;
const int BASE = 29;
int pref[nax];
#define power power_asldjfaslkj
int power[nax];

// goals:
// 1) quickly get hash of substring of s[]
// 2) quickly lex. compare two substrings

// alternative: KMR?   assign lex. hash for every power of two

int n;
int get_hash(int L, int R) {
	return (pref[R+1] - pref[L] + MOD) * (long long) power[n-L] % MOD;
}

// compares s[L1..R1] with s[L2..R2]
int cmp(int L1, int R1, int L2, int R2) {
	if(get_hash(L1, R1) == get_hash(L2, R2)) {
		return 0;
	}
	
	// binary search the first moment when hashes of [L1..x] and [L2..x] differ
	int low = L1, high = R1;
	while(low < high) {
		int mid = (low + high) / 2;
		if(get_hash(L1, mid) == get_hash(L2, mid + L2 - L1)) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}

	
	int i = low;
	int j = low + L2 - L1;
	assert(s[i] != s[j]);
	return s[i] < s[j] ? -1 : 1;
	
	// assert(R2 - L2 == R1 - L1);
	// for(int i = L1; i <= R1; ++i) {
		// if(s[i] != s[L2-L1+i]) {
			// if(s[i] < s[L2-L1+i]) {
				// return -1;
			// }
			// return 1;
		// }
	// }
	// return 0;
}

int main() {
	int k;
	
	
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	
	power[0] = 1;
	for(int i = 1; i <= n; ++i) {
		power[i] = (long long) power[i-1] * BASE % MOD;
	}
	
	for(int i = 1; i <= n; ++i) {
		pref[i] = (pref[i-1] + (long long) power[i] * (s[i-1] - 'a')) % MOD;
	}
	
	int best_end = 0;
	for(int end = 1; end < n; ++end) {
		
		// [8,9] + [0,7]  vs. [0, 1] + [2, 9]
		   // ^       ^
		// end       best_end
		
		// best_end+1 .. end     vs.   [0, end-best_end-1]
		int x = end - best_end;
		int c = cmp(best_end + 1, end, 0, x - 1);
		if(c != 0) {
			if(c == -1) {
				best_end = end;
			}
			continue;
		}
		c = cmp(0, best_end, x, end);
		if(c == -1) {
			best_end = end;
		}
		// string s1 = string(s, s + best_end + 1);
		// string s2 = string(s, s + end + 1);
		// if(s1 + s2 > s2 + s1) {
			// best_end = end;
		// }
	}
	string period = string(s, s + best_end + 1);
	while((int) period.length() < k) {
		period += period;
	}
	period.resize(k);
	printf("%s\n", period.c_str());
}

// kamilkamkami



// kakakakakakakaka
  // ^
  
// kecbeeep
// kecbeeekecbeeekecbeeekecbeeekecbeeekecbee



// kecbeeekd
 // ^      ^
 
 
 
// _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
// AAAAAAAAAAAAAAA
// BBBBBBBBBBBBBBBBBBBBBBB


// P1 vs. P2


// (P1P2) vs. (P2P1)


// kam vs. kamil    kamkamkam       kamilkamilkamil...

// kamkamil vs. kamilkam